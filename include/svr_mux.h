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
#include "svr_types.h"

/* API */
bool SVR_mux_init(SVR_mux_handle_t *mux);
bool SVR_mux_deinit(SVR_mux_handle_t *mux);
bool SVR_mux_take(SVR_mux_handle_t *mux, bool from_isr, unsigned timeout_ticks);
bool SVR_mux_give(SVR_mux_handle_t *mux, bool from_isr);


#ifdef __cplusplus
}
#endif