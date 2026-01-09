#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        //stores length of largest subset till i
        vector<int> dp(n, 1);

        //stores parent of indices
        vector<int> parent(n, -1);

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {

                //satisfy given condition
                if(nums[i] % nums[j] == 0) {

                    //taking current element gives a larger subset
                    if(dp[j]+1 > dp[i]) {
                        parent[i] = j;
                        dp[i] = dp[j]+1;
                    }
                }
            }
        }

        int maxLen = 0;  //length of largest divisible subset
        int index = 0;   //index of last element of largest divisible subset

        for(int i = 0; i < n; i++) {
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                index = i;
            }
        }

        vector<int> res;

        //push elements backwards
        while(index != -1) {
            res.push_back(nums[index]);
            index = parent[index];
        }

        //reverse 
        reverse(res.begin(), res.end());

        //largest divisible subset
        return res;

    }
};