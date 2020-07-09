#include "SharedVirtualRegisters.h"
#include <stdio.h>
#include <stdlib.h>

SharedVirtualRegisters::SharedVirtualRegisters(uint32_t regs_num) : regs_ammount(0),
                                              selected_reg(0),
                                              registers(NULL) {
    Init(regs_num);
}

void SharedVirtualRegisters::Init(uint32_t regs_num) {
    this->regs_ammount = regs_num;
    this->registers = (uint8_t *)(calloc(regs_num, sizeof(uint8_t)));
}

uint8_t *SharedVirtualRegisters::GetRegs(void) {
    return this->registers;
}

uint32_t SharedVirtualRegisters::GetRegsAmmount(void) {
    return this->regs_ammount;
}

void SharedVirtualRegisters::SelectReg(uint32_t num) {
    if (num >= regs_ammount)
        this->selected_reg = (this->regs_ammount - 1); // select the last reg
    else
        this->selected_reg = num;
}

void SharedVirtualRegisters::SelectNextReg(void) {
    if (this->selected_reg < (this->regs_ammount - 1)) // if not the last one
        this->selected_reg++;
}

uint32_t SharedVirtualRegisters::GetSelectedRegNum(void) {
    return selected_reg;
}

void SharedVirtualRegisters::SetReg(uint8_t val) {
    this->registers[this->selected_reg] = val;
}

void SharedVirtualRegisters::SetRegAndNext(uint8_t val) {
    SetReg(val);
    SelectNextReg();
}

uint8_t SharedVirtualRegisters::GetReg(void) {
    return this->registers[this->selected_reg];
}

uint8_t SharedVirtualRegisters::GetRegAndNext(void) {
    uint8_t val = GetReg();
    SelectNextReg();
    return val;
}
