// Exponentiation

template<typename T>
T exp(T a, ll n) {
    // n > 0
    T res = a; n--;
    while (n) {
        if (n&1) { res = res * a; }
        a = a * a;
        n >>= 1;
    }
    return res;
}