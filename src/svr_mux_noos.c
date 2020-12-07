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

#if SVR_CFG_OS == SVRS_OS_NOOS

bool SVR_mux_init(SVR_mux_handle_t *mux) {
    *mux = calloc(1, 1);
    if (!*mux) {
        return false;
    }
    **mux = true;
    return true;
}

bool SVR_mux_deinit(SVR_mux_handle_t *mux) {
    free(*mux);
    *mux = NULL;
    return true;
}
bool SVR_mux_take(SVR_mux_handle_t *mux, bool from_isr, unsigned timeout_ticks) {
    if (!**mux) {
        return false;
    }
    **mux = false;
    return true;
}

bool SVR_mux_give(SVR_mux_handle_t *mux, bool from_isr) {
    if (**mux) {
        return false;
    }
    **mux = true;
    return true;
}

#endif /* #if SVR_CFG_OS == SVR_OS_NOOS */