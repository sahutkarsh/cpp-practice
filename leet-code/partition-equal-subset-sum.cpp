class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int W = accumulate(nums.begin(), nums.end(), 0);
        if (W % 2 == 0) W /= 2;
        else return false;
        bool dp[N+1][W+1];
        for (int i=0; i<=N; i++) dp[i][0] = true;
        for (int j=1; j<=W; j++) dp[0][j] = false;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=W; j++) {
                dp[i][j] = dp[i-1][j];
                if (nums[i-1] <= j) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[N][W];
    }
};