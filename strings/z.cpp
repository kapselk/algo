// Z function

vector<int> z_function(string s) {
    int n = (int) s.size(), l = 1, r = 0;
    s += "#";
    vector<int> ret(n, 0);
    ret[0] = n;
    for (int i = 1; i < n; i++) {
        if (i <= r) ret[i] = min(r - i + 1, ret[i - l]);
        while (s[i + ret[i]] == s[ret[i]]) ret[i]++;
        if (i + ret[i] - 1 > r) {
            l = i;
            r = i + ret[i] - 1;
        }
    }
    return ret;
}