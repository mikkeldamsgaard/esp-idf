// Copyright 2015-2022 Espressif Systems (Shanghai) PTE LTD
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

#include <stdint.h>
#include <esp_err.h>
#include <driver/spi_common.h>
#include <driver/spi_master.h>
#include "dhara/map.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Structure to describe how to configure the nand access layer.

 @note The spi device handle must be initialized with the flag SPI_DEVICE_HALFDUPLEX
*/
struct spi_nand_flash_config_t {
  spi_device_handle_t device_handle;       ///< SPI Device for this nand chip.
  uint8_t gc_factor;                       ///< The gc factor controls the number of blocks to spare block ratio.
                                           ///< Lower values will reduce the available space but increase performance
};
typedef struct spi_nand_flash_config_t spi_nand_flash_config_t;

struct spi_nand_flash_device_t;
typedef struct spi_nand_flash_device_t spi_nand_flash_device_t;

/** @brief Initialise SPI nand flash chip interface.
 *
 * This function must be called before any other API functions are called for this chip.
 *
 * @param config Pointer to SPI nand flash config structure
 * @param[out] handle The handle is returned in this variable.
 * @return ESP_OK on success, or a flash error code if initialisation fails.
 */
esp_err_t spi_nand_flash_init_device(spi_nand_flash_config_t *config, spi_nand_flash_device_t **handle);

esp_err_t spi_nand_flash_read_sector(spi_nand_flash_device_t *handle, uint8_t *buffer, uint16_t sector_id);

esp_err_t spi_nand_flash_write_sector(spi_nand_flash_device_t *handle, const uint8_t *buffer, uint16_t sector_id);

esp_err_t spi_nand_flash_sync(spi_nand_flash_device_t *handle);

esp_err_t spi_nand_flash_get_capacity(spi_nand_flash_device_t *handle, uint16_t *number_of_sectors);

esp_err_t spi_nand_flash_get_sector_size(spi_nand_flash_device_t *handle, uint16_t *sector_size);

esp_err_t spi_nand_erase_chip(spi_nand_flash_device_t *handle);

esp_err_t spi_nand_flash_deinit_device(spi_nand_flash_device_t *handle);

#ifdef __cplusplus
}
#endif
