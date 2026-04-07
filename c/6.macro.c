#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "lib/foo.h"

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

#define FOO 123
#define MIN_NUM(a, b)                                                          \
    (a < b ? a : b) // 圆括号！这里是expression,不是function,实际使用会expand

// macro和header file一样，属于pre-processor的工作，不用加;
int main(int argc, char *argv[]) {
    i32 x = FOO;
    printf("FOO: %d\n", x);
    printf("min:%d\n", MIN_NUM(x, 125));
    return 0;
}
