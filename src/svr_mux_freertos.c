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

#include <stdlib.h>
#include "SharedVirtualRegisters.h"
#include "svr_mux.h"

#if SVR_CFG_OS == SVR_OS_FREERTOS

bool SVR_mux_init(SVR_mux_handle_t *mux) {
    *mux = xSemaphoreCreateMutex();
    if (*mux == NULL) {
        return false;
    }
    return true;
}

bool SVR_mux_deinit(SVR_mux_handle_t *mux) {
    vSemaphoreDelete(*mux);
    if (*mux != NULL) {
        return false;
    }
    return true;
}

bool SVR_mux_take(SVR_mux_handle_t *mux, bool from_isr, unsigned timeout_ticks) {
    BaseType_t res;
    if(from_isr){
        res = xSemaphoreTakeFromISR(*mux, NULL);
    } else{
        res = xSemaphoreTake(*mux, (TickType_t) timeout_ticks);
    }
    if (res != pdTRUE) {
        return false;
    }
    return true;
}

bool SVR_mux_give(SVR_mux_handle_t *mux, bool from_isr) {
    BaseType_t res;
    if(from_isr){
        res = xSemaphoreGiveFromISR(*mux, NULL);
    } else{
        res = xSemaphoreGive(*mux);
    }
    if (res != pdTRUE) {
        return false;
    }
    return true;
}

#endif /* #if SVR_CFG_OS == SVR_OS_FREERTOS */