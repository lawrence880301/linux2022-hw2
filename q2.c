#include <stdint.h>
#include <stdio.h>

uint32_t max(uint32_t a, uint32_t b) { return a ^ ((a ^ b) & -(a < b)); }

int main() { printf("%d\n", max(1, 5)); }