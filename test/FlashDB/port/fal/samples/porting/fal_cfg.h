/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#define FAL_PART_HAS_TABLE_CFG

/* ===================== Flash device Configuration ========================= */
extern struct fal_flash_dev dev_ram_flash0;
extern struct fal_flash_dev dev_ram_flash1;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                         \
{                                                                   \
    &dev_ram_flash0,                                                \
    &dev_ram_flash1,                                                \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                               \
{                                                                                    \
    {FAL_PART_MAGIC_WORD,        "kv",       "ram_flash0",         0,    4*1024, 0}, \
    {FAL_PART_MAGIC_WORD,        "ts",       "ram_flash0",    4*1024,    4*1024, 0}, \
    {FAL_PART_MAGIC_WORD, "easyflash",       "ram_flash1",         0,    8*1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
