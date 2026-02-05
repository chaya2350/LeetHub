class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n);
        dp[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            long long next2 = dp[i2] * 2;
            long long next3 = dp[i3] * 3;
            long long next5 = dp[i5] * 5;

            long long next = min({next2, next3, next5});
            dp[i] = next;

            if (next == next2) i2++;
            if (next == next3) i3++;
            if (next == next5) i5++;
        }

        return (int)dp[n - 1];
    }
};
