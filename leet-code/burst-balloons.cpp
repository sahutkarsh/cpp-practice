class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n-i; j++) {
                int x = j, y = j + i;
                int maxVal = INT_MIN;
                for (int k=x; k<=y; k++) {
                    int adjacent = 0, current = nums[k];
                    if (k-1 >= x) adjacent += dp[x][k-1];
                    if (k+1 <= y) adjacent += dp[k+1][y];
                    if (x > 0) current *= nums[x-1];
                    if (y < n-1) current *= nums[y+1];
                    maxVal = max(maxVal, (adjacent + current));
                }
                dp[x][y] = maxVal;
            }
        }
        return dp[0][n-1];
    }
};