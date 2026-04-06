#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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

//结构体
int main(int argc, char *argv[]) {
    vec2f v1 = {32.14,42.52};
    printf("vector:<%f,%f>\n",v1.x,v1.y);
    vec2f v2 = {
        .x = 3.14
    };
    printf("vector:<%f,%f>\n",v2.x,v2.y);
    //构造一个 vec2f 类型的匿名临时对象”，这就是 compound literal（复合字面量）。这样右边就变成了一个合法表达式，可以赋值给 v1
    v1 = (vec2f){
        .x = 42.4,
        .y = 142.1
    };
    printf("vector:<%f,%f>\n",v1.x,v1.y);
    return 0;
}
