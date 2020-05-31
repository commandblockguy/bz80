#ifndef H_REGISTERS
#define H_REGISTERS

#include "byte_util.h"

#define mem       L₁

#define reg_a     A
#define reg_ubc   B
#define reg_ude   D
#define reg_f     F
#define reg_uhl   H
#define reg_spl   L
#define reg_mbase M
#define reg_pc    P
#define reg_sps   S
#define reg_ix    X
#define reg_iy    Y

#define reg_af (to16(a, f))
// todo: shadow regs

// Non-register processor state
#define adl       C
#define madl      E
#define ief       I

#endif
