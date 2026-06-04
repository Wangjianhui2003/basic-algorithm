#include <bits/stdc++.h>
using namespace std;

int multi_input() {
    int a, b;
    while (cin >> a >> b) {
        cout << a + b << '\n';
    }
    return 0;
}

int multi_line_input() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}

int one_line() {
    string s;
    getline(cin, s);
    cout << s << '\n';
    return 0;
}

// 这是初学者最容易出错的地方。
// 因为 cin 读完数字后，行末换行符还留在缓冲区里，所以要先清掉。
int one_line2() {
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);

    cout << n << '\n' << s << '\n';
    return 0;
}

// array
int read_array() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}

// two-dimensional array
int read_array2() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

// 在比赛里常加下面两句：
// ios::sync_with_stdio(false);
// cin.tie(nullptr);

int main(int argc, char const *argv[]) { return 0; }
