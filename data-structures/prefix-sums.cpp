// Prefix sums

struct PrefixSum {
    vector<long long> pref;
    
    PrefixSum(vector<long long> a) {
        pref.resize((int) a.size());
        for (int i = 0; i < (int) a.size(); i++) {
            pref[i] = (i ? pref[i - 1] : 0) + a[i];
        }
    }

    long long sum(int l, int r) {
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};