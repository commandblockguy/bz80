#ifndef H_BYTE_UTIL
#define H_BYTE_UTIL

#define to24(u, h, l) (l+(h)256+(u)2^16)
#define to16(h, l)    (l+(h)256)

#define signed24(x)   x - (x>2^23)8^8
#define signed16(x)   x - (x>2^15)4^8
#define signed8(x)    x - (x>127)256

#define low_byte(x)   remainder(x, 256)
#define mid_byte(x)   remainder(int(x / 256), 256)
#define high_byte(x)  int(x / 4^8)

#define wrap24(x)     remainder(x + 8^8, 8^8)
#define wrap16(x)     remainder(x + 4^8, 4^8)
#define wrap8(x)      remainder(x + 256, 256)

#define set_low_byte(b, n)  256 int(n/256)+b
#define set_mid_byte(b, n)  low_byte(n) + 256*b + 4^8 high_byte(n)
#define set_high_byte(b, n) remainder(n,4^8)+4^8*b

#endif
