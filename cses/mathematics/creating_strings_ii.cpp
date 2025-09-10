#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;

ll inverse(ll i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a, ll b) {
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll fact[1000001]; fact[0] = fact[1] = 1;
    for(int i=2;i<=1000000;i++) fact[i] = (fact[i-1]*i)%MOD;
    string s; cin >> s;
    ll n = s.size();
    ll cnt[26] = {};
    for(int i=0; i<n; i++) cnt[s[i]-'a']++;
    ll tot = fact[n];
    for(int i=0; i<26; i++) {
        tot *= inverse(fact[cnt[i]]);
        tot %= MOD;
    }
    cout << tot << endl;
}
