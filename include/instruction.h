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


#define prefix_bkp    N

#define no_prefix     0
#define prefix_bits   1 // 0CBh
#define prefix_ix     2 // 0DDh
#define prefix_misc   3 // 0EDh
#define prefix_iy     4 // 0FDh
#define prefix_ixbits 5 // DDCBh
#define prefix_iybits 6 // FDCBh

#endif
