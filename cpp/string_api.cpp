#include <bits/stdc++.h>
using namespace std;

// string usual api
int main(int argc, char const *argv[]) {
    string s = "hello world";
    s.size();                    // 长度
    s.empty();                   // 是否为空
    s.substr(1, 3);              // 从下标1开始取3个字符
    s.find("ll");                // 查找子串，找不到返回 string::npos
    s.push_back('a');            // 末尾加字符
    s.pop_back();                // 删除末尾字符
    reverse(s.begin(), s.end()); // 反转
    sort(s.begin(), s.end());    // 排序

    int x = stoi("123");
    long long y = stoll("123456");
    string t = to_string(123);

    return 0;
}
