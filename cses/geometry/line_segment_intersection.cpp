#include <iostream>
using namespace std;

#define ll long long

struct Point{
    ll x, y;
    Point operator-(Point b) { return {x-b.x, y-b.y}; }
} p[5];
ll cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
ll dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
int sign(ll x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

bool onseg(Point a, Point b, Point c) {
    if(cross(c-a, b-a) != 0) return false;
    if(0 <= dot(c-a, b-a) && dot(c-a, b-a) <= dot(b-a, b-a)) return true;
    return false;
}

bool intersec(Point a, Point b, Point c, Point d){
    int f1 = sign(cross(a-c, d-c)) * sign(cross(b-c, d-c));
    int f2 = sign(cross(c-a, b-a)) * sign(cross(d-a, b-a));
    if(f1 < 0 && f2 < 0) return true;
    if(f1 > 0 || f2 > 0) return false;
    if(onseg(a, b, c)) return true;
    if(onseg(a, b, d)) return true;
    if(onseg(c, d, a)) return true;
    if(onseg(c, d, b)) return true;
    return false;
}

int main() {
    int t; cin >> t;
    while(t--) {
        for(int i=1; i<5; i++) cin >> p[i].x >> p[i].y;
        if(intersec(p[1], p[2], p[3], p[4])) cout << "YES\n";
        else cout << "NO\n";
    }
}
