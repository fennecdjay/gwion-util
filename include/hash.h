#ifndef __HASH
#define __HASH
typedef struct Hash_* Hash;
struct Hash_ {
  void*       *table;
  uint size;  /* should be prime */
};

void  hini(const Hash, const uint);
void  hdel(const Hash, void (*)(void*));
void  hend(const Hash);
ANN unsigned int hash(const m_str s0);

#define haction(type, ret_type, argtype, prefix, func, pre, cmp, action, post, ret) \
ret_type prefix##_##func(const Hash h, argtype arg)  { \
  const unsigned int idx = hash((m_str)arg) % h->size;        \
  const type sym = h->table[idx];                      \
  pre                                                  \
  for(type s = sym; s; s = s->next) {                  \
    if(cmp) { action }                                 \
    post                                               \
  }                                                    \
  ret;                                                 \
}

// should go to ast
#define hstraction(type, ret_type, func, pre, action, post, ret) \
haction(type, ret_type, m_str, macro, func, pre, !strcmp(s->name, arg), action, post, ret)
#endif
