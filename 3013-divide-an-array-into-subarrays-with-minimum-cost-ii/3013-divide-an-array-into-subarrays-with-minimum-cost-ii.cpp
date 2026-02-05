class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 1;

        multiset<pair<long long,int>> small, large;
        long long sum = 0;
        long long ans = LLONG_MAX;

        auto rebalance = [&]() {
            while ((int)small.size() > need) {
                auto it = prev(small.end());
                sum -= it->first;
                large.insert(*it);
                small.erase(it);
            }
            while ((int)small.size() < need && !large.empty()) {
                auto it = large.begin();
                sum += it->first;
                small.insert(*it);
                large.erase(it);
            }
        };

        int r = min(n - 1, 1 + dist);
        for (int i = 1; i <= r; i++) {
            small.insert({nums[i], i});
            sum += nums[i];
        }
        rebalance();
        if ((int)small.size() == need)
            ans = sum;

        for (int l = 1; l + dist < n; l++) {
            auto cur = make_pair((long long)nums[l], l);
            if (small.count(cur)) {
                small.erase(small.find(cur));
                sum -= nums[l];
            } else {
                large.erase(large.find(cur));
            }

            int nr = l + dist + 1;
            if (nr < n) {
                auto np = make_pair((long long)nums[nr], nr);
                if (!small.empty() && np < *prev(small.end())) {
                    small.insert(np);
                    sum += nums[nr];
                } else {
                    large.insert(np);
                }
            }

            rebalance();
            if ((int)small.size() == need)
                ans = min(ans, sum);
        }

        return ans + nums[0];
    }
};
