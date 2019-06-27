#include<cstdio>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}

int main(){
    ll a,b,c,d,ans=0;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    a--;
    ans-=a;
    ans+=a/c;
    ans+=a/d;
    ans-=a/(c*d/gcd(c,d));
    ans+=b;
    ans-=b/c;
    ans-=b/d;
    ans+=b/(c*d/gcd(c,d));
    printf("%lld\n",ans);
}