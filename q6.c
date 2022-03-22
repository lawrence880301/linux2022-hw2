/*
 * ALIGNOF - get the alignment of a type
 * @t: the type to test
 *
 * This returns a safe alignment for the given type.
 */
//宣告一個 struct 並將 0 轉型為 struct * ，使此 struct 的位址起點在 0
#define ALIGNOF(t) \
    ((char *)(&((struct { char c; t _h; } *)0)-> _h ) - (char *)0)