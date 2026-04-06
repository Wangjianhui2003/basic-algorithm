#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <stdlib.h>

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

// 动态内存分配
int main(int argc, char *argv[]) {
    u32 num_vectors = 10;
    vec2f *vectors = (vec2f *)malloc(sizeof(vec2f) * num_vectors);

    for (u32 i = 0; i < num_vectors; i++) {
        //[]可以解引用
        vectors[i].x = i * 1;
        vectors[i].y = i * 2;
    }

    for (u32 i = 0; i < num_vectors; i++) {
        printf("vector:<%f,%f>\n", vectors[i].x, vectors[i].y);
    }

    free(vectors);

    return 0;
}
