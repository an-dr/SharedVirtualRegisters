// *************************************************************************
//
// Copyright (c) 2020 Andrei Gramakov. All rights reserved.
//
// This file is licensed under the terms of the MIT license.
// For a copy, see: https://opensource.org/licenses/MIT
//
// site:    https://agramakov.me
// e-mail:  mail@agramakov.me
//
// *************************************************************************

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#if SVR_CFG_OS == SVR_OS_FREERTOS
#include "FreeRTOS.h"
#include "semphr.h"
typedef SemaphoreHandle_t SVR_mux_handle_t;
#elif SVR_CFG_OS == SVR_OS_NOOS
typedef unsigned char *SVR_mux_handle_t;
#endif

#define SVR_reg_t unsigned char

typedef struct {
    bool inited;
    SVR_mux_handle_t mux;
    unsigned regs_ammount;
    unsigned selected_reg;
    SVR_reg_t *registers;
} SharedVirtualRegisters_t;

#ifdef __cplusplus
}
#endif