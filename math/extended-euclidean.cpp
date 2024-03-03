// Extended Euclidean algorithm

// return {x, y} such that ax + by = gcd(a, b)
pair<long long, long long> extendedEuclidean(long long a, long long b) {
    if (b == 0) return {1, 0};
    pair<long long, long long> x = extendedEuclidean(b, a % b);
    return {x.second, x.first - a / b * x.second};
}