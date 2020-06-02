#ifndef H_REGISTERS
#define H_REGISTERS

#include "byte_util.h"

#define mem       L₁
#define flags     L₄

#define flag_c    flags(1)
#define flag_n    flags(2)
#define flag_pv   flags(4)
#define flag_h    flags(6)
#define flag_z    flags(7)
#define flag_s    flags(8)

#define reg_a     A
#define reg_ubc   B
#define reg_ude   D
#define reg_uhl   H
#define reg_spl   L
#define reg_mbase M
#define reg_pc    P
#define reg_sps   S
#define reg_ix    X
#define reg_iy    Y

#define reg_b     mid_byte(reg_ubc)
#define reg_c     low_byte(reg_ubc)
#define reg_d     mid_byte(reg_ude)
#define reg_e     low_byte(reg_ude)
#define reg_h     mid_byte(reg_uhl)
#define reg_l     low_byte(reg_uhl)
// todo: shadow regs

// Non-register processor state
#define adl       C
#define madl      E
#define ief       I

#endif
