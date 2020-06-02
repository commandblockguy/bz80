#ifndef H_BYTE_UTIL
#define H_BYTE_UTIL

#define to24(u, h, l) (l+(h)256+(u)2^16)
#define to16(h, l)    (l+(h)256)

#define low_byte(x)   remainder(x, 256)
#define mid_byte(x)   remainder(int(x / 256), 256)
#define high_byte(x)  int(x / 4^8)

#define set_low_byte(b, n)  256 int(n/256)+b
#define set_mid_byte(b, n)  low_byte(x) + 256 b + 4^8 high_byte(x)
#define set_high_byte(b, n) remainder(n,4^8)+4^8 b

#endif
