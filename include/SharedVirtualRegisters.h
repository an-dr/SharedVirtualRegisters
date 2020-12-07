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

#include <stdbool.h>
#include "svr_types.h"

/**
 * @brief User should provide one of theese values to the SVR_CFG_OS define
 *        e.g. adding `-DSVR_CFG_OS=SVR_OS_FREERTOS` to the compiler arguments
 */
#define SVR_OS_NOOS 0
#define SVR_OS_FREERTOS 1

#ifndef SVR_CFG_OS
#error "SharedVirtualRegisters: to use the library you should provide a SVR_CFG_OS define. For example, add -DSVR_CFG_OS=SVR_OS_FREERTOS to the list of your compiler arguments"
#endif

#ifdef __cplusplus
extern "C" {
#endif

bool SVR_Init(SharedVirtualRegisters_t *regs, unsigned regs_ammount);
bool SVR_Deinit(SharedVirtualRegisters_t *regs);
bool SVR_Set(SharedVirtualRegisters_t *regs, unsigned reg_num, SVR_reg_t val, bool from_isr, unsigned timeout_ticks);
bool SVR_Get(SharedVirtualRegisters_t *regs, unsigned reg_num, SVR_reg_t *val_buf, bool from_isr, unsigned timeout_ticks);
const SVR_reg_t *SVR_get_regs(SharedVirtualRegisters_t *regs, unsigned *amount_buf);

#ifdef __cplusplus
}
#endif