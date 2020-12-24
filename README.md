# SharedVirtualRegisters

The library allows to dynamically create a set of thread-save registers

## How to use

To use the library you should provide a SVR_CFG_OS define. For example, add `-DSVR_CFG_OS=SVR_OS_FREERTOS` to the list of your compiler arguments

Possible values of `SVR_CFG_OS`:
- SVRS_OS_NOOS
- SVR_OS_FREERTOS

You can change type of a register. Default is `unsigned char`. For define another type use `SVR_reg_t`, e.g. `-D'SVR_reg_t=unsigned int'`
