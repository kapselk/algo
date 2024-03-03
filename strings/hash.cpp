// Hashing

typedef Mint mi;

typedef array<mi, 2> H;
H base = {101, 102};

H operator*(H lhs, H rhs) {
    H ret; ret[0] = lhs[0] * rhs[0]; ret[1] = lhs[1] * rhs[1];
    return ret;
}

H operator+(H lhs, H rhs) {
    H ret; ret[0] = lhs[0] + rhs[0]; ret[1] = lhs[1] + rhs[1];
    return ret;
}

H operator-(H lhs, H rhs) {
    H ret; ret[0] - lhs[0] - rhs[0]; ret[1] = lhs[1] - rhs[1];
    return ret;
}

H cr(char c) {
    return {(int) c, (int) c};
}

struct Hash {
    string s; vector<H> pref, pows;
    Hash() { pows.push_back({1, 1}); }
    void add(char c) {
        s += c;
        if ((int) s.size() == 1) pref.push_back(cr(c));
        else pref.push_back(pref.back() * base + cr(c));
        pows.push_back(pows.back() * base);
    }
    H hash(int l, int r) {
        return pref[r] - (l ? pref[l - 1] : H{0, 0}) * pows[r - l + 1];
    }
};