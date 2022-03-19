#include <stddef.h>
#include <stdint.h>

size_t naive(uint64_t *bitmap, size_t bitmapsize, uint32_t *out) {
  size_t pos = 0;
  for (size_t k = 0; k < bitmapsize; ++k) {
    /* bitset 的 value等於原始陣列的第 k 個元素的 value
     * p 用來紀錄原始陣列的第 k 個元素 對應到 out 陣列的初始位置
     */
    uint64_t bitset = bitmap[k];
    size_t p = k * 64;
    /* 檢查原始陣列的第 k 個元素的 bit 形式(64位元)
     * 紀錄 第 k 個元素的 bit 形式當中 總共有幾個 bit 為 1
     * pos 用來紀錄 bitmap 的每一個數值的二進位形式中 1 的總數量
     * 將 out 陣列的值 透過函數的轉換即可知道當初在原始陣列中的值的哪個 bit 為
     * 1
     * */
    for (int i = 0; i < 64; i++) {
      if ((bitset >> i) & 0x1)
        out[pos++] = p + i;
    }
  }
  return pos;
}

size_t improved(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    uint64_t bitset;
    for (size_t k = 0; k < bitmapsize; ++k) {
        bitset = bitmap[k];
        while (bitset != 0) {
            //save rightmost one
            uint64_t t = bitset & -bitset;
            //the position of rightmost one
            int r = __builtin_ctzll(bitset);
            out[pos++] = k * 64 + r;
            //把剛剛保存的 1 變成 0 ,其餘的部份則會複製原本的 bitset
            bitset ^= t;                           
        }
    }
    return pos;
}