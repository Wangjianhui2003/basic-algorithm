#include <bits/stdc++.h>
using namespace std;

/**
 * 常见的IO格式化
 */

void fixed_precision() {
    // setprecision(n) is persistent
    // fixed is also persistent
    double x = 3.1415926;
    cout << fixed << setprecision(2) << x << '\n'; // 3.14
    cout << setprecision(4) << x << '\n';          // 3.1416
}

void set_precision() {
    double x = 123.456789;
    cout << setprecision(4) << x << '\n';          // 123.5
    cout << fixed << setprecision(4) << x << '\n'; // 123.4568
}

void use_setw() {
    // It only affects the next output item.
    cout << setw(5) << 42 << 43 << '\n';
    cout << setw(5) << 42 << setw(5) << 43 << '\n';
    // fill,always be effective
    cout << setfill('0') << setw(5) << 42 << '\n';
    // left
    cout << left << setw(10) << "abc" << '\n';
}

int main(int argc, char const *argv[]) {
    // fixed_precision();
    // set_precision();
    use_setw();
    return 0;
}
