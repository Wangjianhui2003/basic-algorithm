#include <bits/stdc++.h>
using namespace std;

//统计字符个数
int main(int argc, char const* argv[])
{
    string s;
    getline(cin, s);
    vector<int> vec(26, 0);
    for (char c : s) {
        vec[c - 'a']++;
    }
    for (int i = 0;i < 26;i++) {
        cout << char(i + 'a') << " " << vec[i] << '\n';
    }
    return 0;
}
