#ifndef __PP
#define __PP
typedef struct PP_ {
  struct Vector_ filename;
  struct Hash_* macros;
  struct Macro_* entry;
  struct pp_info* def;
  size_t arg_len, arg_cap;
  int npar;
  unsigned lint : 1;
} PP;

ANEW PP* new_pp(const uint size);
ANN void free_pp(PP* pp);
ANN void pp_pre(PP* pp, const m_str filename);
void pp_post(PP* pp, void* data);
#endif