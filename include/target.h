/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __TARGET_H
#define __TARGET_H

/* super early platform initialization, before almost everything */
void target_early_init(void);

/* later init, after the kernel has come up */
void target_init(void);

/* get memory address for fastboot image loading */
void *target_get_scratch_address(void);

/* get the max allowed flash size */
unsigned target_get_max_flash_size(void);

/* if target is using eMMC bootup */
int target_is_emmc_boot(void);

unsigned* target_atag_mem(unsigned* ptr);
void target_battery_charging_enable(unsigned enable, unsigned disconnect);
unsigned target_pause_for_battery_charge(void);
unsigned target_baseband(void);
void target_serialno(unsigned char *buf);
void target_fastboot_init(void);
void target_load_ssd_keystore(void);
bool target_is_ssd_enabled(void);
void *target_mmc_device();
uint32_t target_boot_device_emmc();

bool target_display_panel_node(char *panel_name, char *pbuf,
	uint16_t buf_size);
void target_display_init(const char *panel_name);
void target_display_shutdown(void);

uint32_t target_get_boot_device();

const char * target_usb_controller();
void target_usb_phy_reset(void);
void target_usb_phy_mux_configure(void);

/* Boot device */
enum boot_device
{
	BOOT_DEFAULT=0,
	BOOT_EMMC=2,
	BOOT_UFS=4,
};

#endif
