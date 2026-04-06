#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// 基本类型,不用built-in，大小可能会变化
// 比如long long - int64_t:标准要求long long 至少64bit
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i32 b32;

typedef float f32;
typedef double f64;

typedef struct {
    f32 x;
    f32 y;
} vec2f;

// pointer
int main(int argc, char *argv[]) {
    //===
    i32 x = 123;
    i32 *px = &x;
    printf("nums:%d,addr:%p\n", x, px);
    *px = 321;
    printf("nums:%d,addr:%p\n", x, px);

    //=== structure pointer

    //=== array pointer
    i32 nums[] = {1, 2, 3, 4, 5};

    //[] means: dereference and do some math!
    // so the array in c always have "size" variable along with it
    for (i32 i = 0; i < 5; i++) {
        printf("%d,", nums[i]);
    }
    printf("\n");

    *nums = 6;
    *(nums + 1) = 7;

    for (i32 i = 0; i < 5; i++) {
        printf("%d,", nums[i]);
    }
    printf("\n");

    return 0;
}
