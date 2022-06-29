set(srcs "src/nand.c"
         "src/spi_nand_oper.c"
         "src/dhara_glue.c"
         "dhara/dhara/error.c"
         "dhara/dhara/journal.c"
         "dhara/dhara/map.c"
)

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS include dhara
                       REQUIRES driver
                      )
