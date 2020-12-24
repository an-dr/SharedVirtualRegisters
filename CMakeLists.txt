# for ESP-IDF
if(COMMAND idf_component_register)

    if(COMMAND idf_component_get_property)
        idf_component_get_property(FREERTOS_ORIG_INCLUDE_PATH freertos
                                    ORIG_INCLUDE_PATH)
    endif()
    idf_component_register( REQUIRES freertos )
endif()


set(SVR_SRCS
    "src/SharedVirtualRegisters.c"
    "src/svr_mux_noos.c"
    "src/svr_mux_freertos.c"
    )

set(SVR_INCLUDES
    "include"
    "${FREERTOS_ORIG_INCLUDE_PATH}"
    )

# Library
add_library(svr STATIC ${SVR_SRCS})
target_include_directories(
    svr
    PUBLIC ${SVR_INCLUDES}
)

# for ESP-IDF
if(DEFINED COMPONENT_TARGET)
    target_compile_options(svr PUBLIC -DSVR_CFG_OS=SVR_OS_FREERTOS)
    target_link_libraries(${COMPONENT_TARGET} INTERFACE svr)
endif()
