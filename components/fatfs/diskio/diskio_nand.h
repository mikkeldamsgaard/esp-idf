// Copyright 2015-2018 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "spi_nand_flash.h"
#include "ff.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Register NAND flash diskio driver
 *
 * @param pdrv  drive number
 * @param device pointer to a nand flash device structure; device should be initialized before calling f_mount.
 */
esp_err_t ff_diskio_register_nand(unsigned char pdrv, spi_nand_flash_device_t* device);

/**
 * @brief Get the driver number corresponding to a device
 *
 * @param device The device for which to return its driver
 * @return Driver number of the device
 */
BYTE ff_diskio_get_pdrv_nand(const spi_nand_flash_device_t* device);

void ff_diskio_clear_pdrv_nand(const spi_nand_flash_device_t *dev);

#ifdef __cplusplus
}
#endif