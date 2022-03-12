#include <stdint.h>
#define min(a, b) ((a) ^ ((a) ^ (b)) & -(a > b));

uint64_t gcd64(uint64_t u, uint64_t v) {
  if (!u || !v)
    return u | v;
  int shift;
  for (shift = 0; !((u | v) & 1); shift++) {
    u /= 2, v /= 2;
  }
  while (!(u & 1))
    u /= 2;
  do {
    while (!(v & 1))
      v /= 2;
    if (u < v) {
      v -= u;
    } else {
      uint64_t t = u - v;
      u = v;
      v = t;
    }
  } while (v);
  return u << shift;
}

uint64_t gcd64_v2(uint64_t u, uint64_t v) {
  if (!u || !v)
    return u | v;
  int shift;
  int u_ctz = __builtin_ctzl(u);
  int v_ctz = __builtin_ctzl(v);

  u >>= u_ctz;

  do {
    v >>= __builtin_ctzl(v);

    if (u < v) {
      v -= u;
    } else {
      uint64_t t = u - v;
      u = v;
      v = t;
    }
  } while (v);
  return u << min(u_ctz, v_ctz);
}

int main() {
  printf("%u", gcd64(128, 10));
  printf("%u", gcd64_v2(128, 10));
}