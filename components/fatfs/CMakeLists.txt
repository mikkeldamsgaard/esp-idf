set(srcs "diskio/diskio.c"
         "diskio/diskio_rawflash.c"
         "diskio/diskio_sdmmc.c"
         "diskio/diskio_wl.c"
         "diskio/diskio_nand.c"
         "src/ff.c"
         "port/freertos/ffsystem.c"
         "src/ffunicode.c"
         "vfs/vfs_fat.c"
         "vfs/vfs_fat_sdmmc.c"
         "vfs/vfs_fat_spiflash.c"
         "vfs/vfs_fat_spinandflash.c"
        )

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS diskio vfs src
                       REQUIRES wear_levelling sdmmc spi_nand_flash
                      )
