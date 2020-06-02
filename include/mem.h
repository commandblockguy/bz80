#ifndef H_MEM
#define H_MEM

#define get_byte(address) mem(min(address+1,999))
#define get2(address) mem(address+1) + 256 mem(address+2)
#define get3(address) mem(address+1) + 256 mem(address+2) + 4^8 mem(address+3)
#define get_bytes(address, size) Σ(mem(address+X)256^(X-1), X, 1, size)
#define set_byte(address, data) data→mem(address+1)
#define set_bytes(address, size, data) For(temp_var, 1, size):remainder(int(data/256^temp_var),256)→mem(address+temp_var):End

#endif
