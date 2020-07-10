set(COMPONENT_SRCS
    "src/SharedVirtualRegisters.cpp"
    # "common/tusb_fifo.c"
    )
set(COMPONENT_INCLUDEDIRS
    "include"
    # "common"
    )



idf_component_register( REQUIRES freertos
                        SRCS ${COMPONENT_SRCS}
                        INCLUDE_DIRS ${COMPONENT_INCLUDEDIRS})