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

// bool
typedef i8 b8;
typedef i32 b32;

typedef float f32;
typedef double f64;

// 基本类型
int main(int argc, char *argv[]) {
    f32 f1 = 234.11;
    f64 f2 = 234.11;

    printf("%f and %f\n", f1, f2);
    printf("hellw world\n");
    return 0;
}
