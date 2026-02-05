class Solution {
public:
    long long gcd(long long x, long long y) {
        while (y) {
            long long t = x % y;
            x = y;
            y = t;
        }
        return x;
    }

    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }

    long long countUgly(long long x, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        return x / a + x / b + x / c
             - x / ab - x / ac - x / bc
             + x / abc;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = 2e9;
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countUgly(mid, a, b, c) >= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (int)ans;
    }
};
