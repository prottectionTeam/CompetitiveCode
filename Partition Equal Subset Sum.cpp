class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int target, int len) {
        vector<vector<int>> dp(len+1, vector<int>(target+1, -1));
        
        for(int i=1; i<=target; i++)
            dp[0][i] = 0;
        
        for(int i=0; i<=len; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=len; i++) {
            for(int j=1; j<=target; j++) {
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
            }
        }
        
        return dp[len][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total%2 != 0)
            return false;
        
        int len = nums.size();
        int target = total/2;
        return isSubsetSum(nums, target, len);
    }
};
