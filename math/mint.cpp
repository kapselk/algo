// Modular int

const ll MOD = 1e9 + 7;

struct Mint {
    int v;
    explicit operator int() const { return v; }
    Mint() { v = 0; }
    Mint(long long v_) { v = v_ % MOD; if (v < 0) v += MOD; }
    bool operator==(const Mint& rhs) const { return v == rhs.v; }
    bool operator!=(const Mint& rhs) const { return v != rhs.v; }
    bool operator<(const Mint& rhs) const { return v < rhs.v; }
    Mint& operator+=(const Mint& rhs) {
        v += rhs.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint& rhs) {
        v -= rhs.v;
        if (v < 0) v += MOD;
        return *this;
    }
    Mint& operator*=(const Mint& rhs) {
        v = (int) (((long long ) v * rhs.v)%MOD);
        return *this;
    }
    Mint& operator/=(const Mint& rhs) {
        *this *= inv(rhs);
        return *this;
    }
    long long inv(long long a, long long b) {
        return a > 1 ? b - inv(b % a, a) * b / a : 1;
    }
    Mint inv(const Mint& a) {
        return Mint(inv(a.v, MOD));
    }
    Mint operator-() const {
        return Mint(-v);
    }
    Mint& operator++() {
        *this += Mint(1);
        return *this;
    }
    Mint& operator--() {
        *this -= Mint(1);
        return *this;
    }
};

Mint operator+(Mint lhs, Mint rhs) {
    return lhs += rhs;
}
Mint operator-(Mint lhs, Mint rhs) {
    return lhs -= rhs;
}
Mint operator*(Mint lhs, Mint rhs) {
    return lhs *= rhs;
}
Mint operator/(Mint lhs, Mint rhs) {
    return lhs /= rhs;
}