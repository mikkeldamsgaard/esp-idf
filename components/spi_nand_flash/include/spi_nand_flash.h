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

struct spi_nand_flash_config_t {
  spi_device_handle_t device_handle;
  uint8_t gc_factor; // Will default to 45 if set to 0
};
typedef struct spi_nand_flash_config_t spi_nand_flash_config_t;

struct spi_nand_flash_device_t;
typedef struct spi_nand_flash_device_t spi_nand_flash_device_t;

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
