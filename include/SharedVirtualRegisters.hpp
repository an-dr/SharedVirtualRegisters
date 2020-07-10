#pragma once

#include <stdint.h>


/** @} */

/** \defgroup group_supported_os Supported RTOS
 *  \ref CFG_TUSB_OS must be defined to one of these
 *  @{ */
#define SHAREDVR_OPT_OSNONE       1 ///< No RTOS
#define SHAREDVR_OPT_OSFREERTOS   2 ///< FreeRTOS
#define SHAREDVR_OPT_OSMYNEWT     3 ///< Mynewt OS
/** @} */

#define CFG_SHAREDVR_OS SHAREDVR_OPT_OSFREERTOS
// #include "osal/osal.h"


class SharedVirtualRegisters {
protected:
    bool inited;
    uint32_t regs_ammount;
    uint32_t selected_reg;
    uint8_t *registers;

public:
    SharedVirtualRegisters() = default;
    SharedVirtualRegisters(uint32_t regs_num);
    void Init(uint32_t regs_num);
    // void Deinit(void); //TODO
    uint8_t *GetRegs(void);
    uint32_t GetRegsAmmount(void);
    void SelectReg(uint32_t num);
    void SelectNextReg(void);
    uint32_t GetSelectedRegNum(void);
    void SetReg(uint8_t val);
    void SetRegAndNext(uint8_t val);
    uint8_t GetReg(void);
    uint8_t GetRegAndNext(void);
    void Write(uint32_t num, uint8_t val);
    uint8_t Read(uint32_t num);
};