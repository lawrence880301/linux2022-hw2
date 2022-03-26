#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
// int main() {
//     for (unsigned int i = 1; i < 100; i++) {
//         if (i % 3 == 0) printf("Fizz");
//         if (i % 5 == 0) printf("Buzz");
//         if (i % 15 == 0) printf("FizzBuzz");
//         if ((i % 3) && (i % 5)) printf("%u", i);
//         printf("\n");
//     }
//     return 0;
// }

//檢查是否整除
static inline bool is_divisible(uint32_t n, uint64_t M)
{
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;
static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;

int main(int argc, char **argv)
{
    for (size_t i = 1; i <= 100; i++) {
        uint8_t div3 = is_divisible(i, M3);
        uint8_t div5 = is_divisible(i, M5);
        unsigned int length = (2 << div3) << div5;

        char fmt[9];
        strncpy(fmt, &"FizzBuzz%u"[(8 >> div5) >> (div3<<2)], length);
        fmt[length] = '\0';

        printf(fmt, i);
        printf("\n");
    }
    return 0;
}
