#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of LIS ending at index i
        vector<int> dp(n, 1);  
        
        int maxLen = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                //if increasing subsequence
                if(nums[j] < nums[i]) { 
                   dp[i] = max(dp[i], dp[j]+1);
                }    
            }

            // update after dp[i] is finalized
            maxLen = max(maxLen, dp[i]);
        }

        //length of longest increasing subsequence
        return maxLen;
        
    }
};