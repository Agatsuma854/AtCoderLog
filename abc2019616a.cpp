#include<cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    /*
     * a と b がありました.
     * その時の...
     * g = 最大公約数 <- ユークリッドの互除法で出せる
     * l = 最小公倍数
     *
     * a x b = g x l を変形すればlgを簡単に求められる
     *
     */


    ll a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;

    // これa-1以下の公約数も足しちゃってるから引かないとだめだよね
    ans += b; // 範囲から割り切れるやつを引く
    ans -= b / c;
    ans -= b / d;
    ans += b / (c * d / gcd(c, d)); // c*d / g = l で最小公倍数が求められる
    // bをcとdの最小公倍数で割ると２つかぶりを潰せる

    // a-1より下の領域を引いて, bの約数はa以下も引いてしまっているので足して戻す
    --a;
    ans -= a;
    ans += a / c;
    ans += a / d;
    ans -= a / (c * d / gcd(c, d));

    cout << ans << endl;
}