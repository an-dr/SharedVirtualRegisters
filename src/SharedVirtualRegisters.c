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

#include "SharedVirtualRegisters.h"
#include <stdio.h>
#include <stdlib.h>
#include "svr_mux.h"


bool SVR_Init(SharedVirtualRegisters_t *regs, unsigned regs_ammount) {
    /* mutex*/
    if (!SVR_mux_init(&(regs->mux))) {
        return false;
    }
    /* registers */
    regs->regs_ammount = regs_ammount;
    regs->registers    = calloc(regs_ammount, sizeof(SVR_reg_t));
    if (!regs->registers) {
        return false;
    }
    return true;
}

bool SVR_Deinit(SharedVirtualRegisters_t *regs) {
    free(regs->registers);
    regs->registers = NULL;
    return true;
}

bool SVR_Set(SharedVirtualRegisters_t *regs, unsigned reg_num, SVR_reg_t val, bool from_isr, unsigned timeout_ticks) {
    if (reg_num > (regs->regs_ammount - 1)) {
        return false;
    }
    if (!SVR_mux_take(&(regs->mux), from_isr, timeout_ticks)) {
        return false;
    }
    regs->registers[reg_num] = val;
    if (!SVR_mux_give(&(regs->mux), from_isr)) {
        return false;
    }
    return true;
}

bool SVR_Get(SharedVirtualRegisters_t *regs, unsigned reg_num, SVR_reg_t *val_buf, bool from_isr, unsigned timeout_ticks) {
    if (reg_num > (regs->regs_ammount - 1)) {
        return false;
    }
    if (!SVR_mux_take(&(regs->mux), from_isr, timeout_ticks)) {
        return false;
    }
    *val_buf = regs->registers[reg_num];
    if (!SVR_mux_give(&(regs->mux), from_isr)) {
        return false;
    }
    return true;
}

const SVR_reg_t* SVR_get_regs(SharedVirtualRegisters_t *regs, unsigned *amount_buf)
{
    *amount_buf = regs->regs_ammount;
    return regs->registers;

bool SVR_Dump(SharedVirtualRegisters_t *regs,
              unsigned start,
              unsigned amount,
              SVR_reg_t *buf,
              bool from_isr,
              unsigned timeout_ticks) {
    if (start > (regs->regs_ammount - 1)) {
        return false;
    }
    if (!SVR_mux_take(&(regs->mux), from_isr, timeout_ticks)) {
        return false;
    }
    for(int r = start; r<regs->regs_ammount; r++){
        buf[r-start] = regs->registers[r];
    }

    if (!SVR_mux_give(&(regs->mux), from_isr)) {
        return false;
    }
    return true;
}