#include <fs/fcb.h>
#include <logging/log.h>
#include <ztest.h>

LOG_MODULE_REGISTER(test_fcb, 4);

#define TEST_FLASH_AREA FLASH_AREA_ID(storage)
#define SECTOR_COUNT 16

static struct fcb fcb;
static struct flash_sector fcb_sectors[16];
static struct fcb_entry fcb_write_entry;

int disk_erase(void)
{
	const struct flash_area *flash;
	int err;

	err = flash_area_open(TEST_FLASH_AREA, &flash);
	if (err < 0)
		return err;

	uint32_t sector_count = sizeof(fcb_sectors) / sizeof(fcb_sectors[0]);
	err = flash_area_get_sectors(TEST_FLASH_AREA, &sector_count,
				     fcb_sectors);

	__ASSERT_NO_MSG(sector_count == SECTOR_COUNT);

	for (int i = 0; i < sector_count; i++) {
		LOG_DBG("Erasing area %i", i);

		err = flash_area_erase(flash, fcb_sectors[i].fs_off,
				       fcb_sectors[i].fs_size);

		if (err < 0)
			return err;
	}

	return 0;
}

int disk_init(void)
{
	int err;
	uint32_t sector_count = sizeof(fcb_sectors) / sizeof(fcb_sectors[0]);

	err = flash_area_get_sectors(TEST_FLASH_AREA, &sector_count,
				     fcb_sectors);

	if (err) {
		LOG_ERR("Failed to fetch flash sectors (%i)", err);
		return err;
	}

	LOG_DBG("%u sectors are available", sector_count);

	fcb.f_magic = 0xb0ffeeee;
	fcb.f_sectors = fcb_sectors;
	fcb.f_version = 42;
	fcb.f_sector_cnt = sector_count;

	err = fcb_init(TEST_FLASH_AREA, &fcb);
	if (err) {
		LOG_ERR("Failed to initialize flash circular buffer (%i)", err);
		return err;
	}

	if (fcb.f_oldest == fcb.f_active.fe_sector)
		LOG_WRN("FCB Reinitialized!");

	return 0;
}

static int fcb_rotate_append(int len, struct fcb_entry *entry)
{
	int err = fcb_append(&fcb, len, entry);
	if (err == -ENOSPC) {
		err = fcb_rotate(&fcb);
		if (err) {
			LOG_ERR("Failed to rotate FCB (%i)", err);
			return err;
		}

		int err = fcb_append(&fcb, len, entry);
		if (err) {
			LOG_ERR("Failed to append after rotation (%i)", err);
			return err;
		}
	} else if (err) {
		LOG_ERR("Failed to append (%i)", err);
		return err;
	}

	return err;
}

uint8_t data[2048];

static void write_to_fcb(void)
{
	int err;

	LOG_DBG("fd_id %u", fcb.f_active_id);

	err = fcb_rotate_append(sizeof(data), &fcb_write_entry);
	zassert_equal(err, 0, "rotate append failed (%i)", err);

	err = flash_area_write(fcb.fap, FCB_ENTRY_FA_DATA_OFF(fcb_write_entry),
			       data, sizeof(data));
	zassert_equal(err, 0, "write failed (%i)", err);

	err = fcb_append_finish(&fcb, &fcb_write_entry);
	zassert_equal(err, 0, "append finish failed (%i)", err);
}

static void test_fcb_fd_id_overflow(void)
{
	int err;
	uint32_t test_id_point;

	disk_erase();

	err = disk_init();
	zassert_equal(err, 0, "disk_init failed");

	memset(data, 42, sizeof(data));

	// Skip to near int16 rollover point.
	fcb.f_active_id = INT16_MAX - SECTOR_COUNT;

	// Go past int16 rollover
	while (fcb.f_active_id < INT16_MAX + 5) {
		write_to_fcb();
	}

	err = fcb_init(TEST_FLASH_AREA, &fcb);
	zassert_equal(err, 0, "fcb_init failed");
	zassert_equal(fcb.f_active_id, INT16_MAX + 5, "Failed at int16 rollover. Active ID was %u", fcb.f_active_id);

	// Skip to near uint16 rollover point.
	fcb.f_active_id = UINT16_MAX - SECTOR_COUNT;

	// Go past uint16 rollover
	test_id_point = UINT16_MAX + 5;
	while (fcb.f_active_id < test_id_point) {
		write_to_fcb();
	}

	err = fcb_init(TEST_FLASH_AREA, &fcb);
	zassert_equal(err, 0, "fcb_init failed");
	zassert_equal(fcb.f_active_id, test_id_point, "Failed at uint16 rollover. Active ID was %u", fcb.f_active_id);

	// Skip to near int32 rollover point.
	fcb.f_active_id = INT32_MAX - SECTOR_COUNT;

	// Go past int32 rollover
	test_id_point = ((uint32_t)INT32_MAX) + 5;
	while (fcb.f_active_id < test_id_point) {
		write_to_fcb();
	}

	err = fcb_init(TEST_FLASH_AREA, &fcb);
	zassert_equal(err, 0, "fcb_init failed");
	zassert_equal(fcb.f_active_id, test_id_point, "Failed at int32 rollover. Active ID was %u", fcb.f_active_id);

	// Skip to near uint32 rollover point.
	fcb.f_active_id = UINT32_MAX - SECTOR_COUNT;

	// Go past uint32 rollover
	test_id_point = 5;
	while (fcb.f_active_id != test_id_point) {
		write_to_fcb();
	}

	err = fcb_init(TEST_FLASH_AREA, &fcb);
	zassert_equal(err, 0, "fcb_init failed");
	zassert_equal(fcb.f_active_id, test_id_point, "Failed at uint32 rollover. Active ID was %u", fcb.f_active_id);
}

void test_main(void)
{
	ztest_test_suite(fcb_pd_extensions,
			 ztest_unit_test(test_fcb_fd_id_overflow));

	ztest_run_test_suite(fcb_pd_extensions);
}
