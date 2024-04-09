#include <stdint.h>
#include <string.h>
#include <fal.h>

static int init(void);
static int read(long offset, uint8_t *buf, size_t size);
static int write(long offset, const uint8_t *buf, size_t size);
static int erase(long offset, size_t size);

static uint8_t ram_flash[8 * 1024];

struct fal_flash_dev dev_ram_flash1 = {
    .name = "ram_flash1",
    .addr = 0,
    .len = 8 * 1024,
    .blk_size = 1024,
    .ops = {init, read, write, erase},
    .write_gran = 8,
};

static int init(void)
{
    dev_ram_flash1.addr = (uint32_t)ram_flash;
    return 0;
}

static int read(long offset, uint8_t *buf, size_t size)
{
    memcpy(buf, (void *)(dev_ram_flash1.addr + offset), size);

    return size;
}

static int write(long offset, const uint8_t *buf, size_t size)
{
    memcpy((void *)(dev_ram_flash1.addr + offset), buf, size);

    return size;
}

static int erase(long offset, size_t size)
{
    memset((void *)(dev_ram_flash1.addr + offset), 0xFF, size);

    return size;
}
