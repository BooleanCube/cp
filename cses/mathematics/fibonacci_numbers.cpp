#include <map>
#include <iostream>
using namespace std;
#define long long long

const long M = 1e9+7;
map<long, long> fib;

long fibo(long n) {
    if(fib.count(n)) return fib[n];
    long k=n/2;
    if(n%2==0) return fib[n] = (fibo(k)*fibo(k) + fibo(k-1)*fibo(k-1)) % M;
    return fib[n] = (fibo(k)*fibo(k+1) + fibo(k-1)*fibo(k)) % M;
}

int main() {
    fib[0] = fib[1] = 1;
    long n; cin >> n;
    cout << (n==0 ? 0 : fibo(n-1)) << endl;
}
