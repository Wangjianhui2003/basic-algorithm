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

// normal struct
typedef struct {
    f32 x;
    f32 y;
} vec2f;

// union
typedef struct {
    enum { SHAPE_SQUARE, SHAPE_CIRCLE, SHAPE_TRIANGLE } kind;

    // union取决于最大的struct
    union {
        struct {
            f32 s;
        } square;
        struct {
            f32 r;
        } circle;
        struct {
            f32 b, h;

        } triangle;
    } content;
} shape;

// 4 byte对齐
typedef struct {
    char a;
    i32 b;
} align;

// 8 byte对齐
typedef struct {
    char a;
    i64 b;
} align2;

// 不使用对齐
#pragma pack(1)
struct A {
    char c;
    int i;
};
#pragma pack()

// 不使用对齐2
struct __attribute__((packed)) B {
    char c;
    int i;
};

// align rule:
//  member alignment depends on the member type
//  struct alignment usually depends on the largest member alignment
//  final result also depends on platform, compiler, and packing settings

// 结构体
int main(int argc, char *argv[]) {
    // === vec
    vec2f v1 = {32.14, 42.52};
    printf("vector:<%f,%f>\n", v1.x, v1.y);
    vec2f v2 = {.x = 3.14};
    printf("vector:<%f,%f>\n", v2.x, v2.y);
    // 构造一个 vec2f 类型的匿名临时对象”，这就是 compound
    // literal（复合字面量）。这样右边就变成了一个合法表达式，可以赋值给 v1
    v1 = (vec2f){.x = 42.4, .y = 142.1};
    printf("vector:<%f,%f>\n", v1.x, v1.y);

    // === shape
    shape s = {.kind = SHAPE_CIRCLE, .content.circle.r = 123};
    return 0;
}
