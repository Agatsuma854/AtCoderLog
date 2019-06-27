#include<cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> task(n);

    for (int i = 0; i < n; ++i) {
        cin >> task.at(i).second >> task.at(i).first; // 締め切り/所要時間
    }

    sort(task.begin(), task.end()); // pairだとfirst要素にソートがかかる

    int sum = 0;
    bool isYes = true;
    for (auto v : task) {
        // 所要時間が締め切り時間をオーバーしなければよい
        sum += v.second;

        if (sum > v.first) {
            isYes = false;
            break;
        }
    }

    cout << (isYes ? "Yes" : "No") << endl;

    return 0;
}