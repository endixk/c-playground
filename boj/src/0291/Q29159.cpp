#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
struct Fraction {
    ll num, den;
    Fraction(ll num=0, ll den=1) {
        ll g = gcd(num, den);
        this->num = num / g;
        this->den = den / g;
        if(this->den < 0) {
            this->num *= -1;
            this->den *= -1;
        }
    }
    Fraction operator+(const Fraction& f) const {
        return Fraction(num * f.den + den * f.num, den * f.den);
    }
    Fraction operator-(const Fraction& f) const {
        return Fraction(num * f.den - den * f.num, den * f.den);
    }
    Fraction operator*(const Fraction& f) const {
        return Fraction(num * f.num, den * f.den);
    }
    Fraction operator/(const Fraction& f) const {
        return Fraction(num * f.den, den * f.num);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll x, y; cin >> x >> y;
    ll dm = 0, p, q;
    for(int i=0; i<3; i++) {
        ll a, b; cin >> a >> b;
        ll d = (a - x) * (a - x) + (b - y) * (b - y);
        if(d > dm) { dm = d; p = a; q = b; }
    }
    Fraction x1 = Fraction(x + p, 2);
    Fraction y1 = Fraction(y + q, 2);

    cin >> x >> y;
    dm = 0;
    for(int i=0; i<3; i++) {
        ll a, b; cin >> a >> b;
        ll d = (a - x) * (a - x) + (b - y) * (b - y);
        if(d > dm) { dm = d; p = a; q = b; }
    }
    Fraction x2 = Fraction(x + p, 2);
    Fraction y2 = Fraction(y + q, 2);

    Fraction a = (y1 - y2) / (x1 - x2);
    Fraction b = y1 - a * x1;
    cout << a.num;
    if(a.den != 1) cout << '/' << a.den;
    cout << ' ' << b.num;
    if(b.den != 1) cout << '/' << b.den;
}
