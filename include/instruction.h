#ifndef H_PREFIXES
#define H_PREFIXES

#define inst_part_list L₃
#define inst_byte      inst_part_list(1)
#define inst_prefix    inst_part_list(2)
// Octal components of the instruction
#define inst_x         inst_part_list(3)
#define inst_y         inst_part_list(4)
#define inst_z         inst_part_list(5)
// Upper two bits of y
#define inst_p         inst_part_list(6)
// LSB of y
#define inst_q         inst_part_list(7)
#define inst_immediate inst_part_list(8)


#define prefix_bkp     N

#define no_prefix      1
#define prefix_bits    2 // 0CBh
#define prefix_misc    3 // 0EDh
#define prefix_ix      4 // 0DDh
#define prefix_iy      5 // 0FDh
#define prefix_ixbits  6 // DDCBh
#define prefix_iybits  7 // FDCBh

#define table_curr_hl  list(A)//L₇
// Require table_curr_hl to be in Ans
#define table_r        L₅
#define table_rp       L₆
// Conditionals. Rather than using y (as in http://www.z80.info/decoding.htm), this is indexed with p and then xored with q
#define table_cc       list(B)//L₈

#define cond(cc)       table_cc(int(cc / 2) + 1) xor not(remainder(cc, 2))

// Get the value of hl, ix, or iy depending on the prefix
#define get_hl(prefix) table_curr_hl(prefix)
#define get_h(prefix)  mid_byte(table_curr_hl(prefix))
#define get_l(prefix)  low_byte(table_curr_hl(prefix))

#define get_r(prefix, x)       get_hl(prefix):table_r(x+1)
#define get_rp(prefix, x)      get_hl(prefix):table_rp(x+1)

#endif
