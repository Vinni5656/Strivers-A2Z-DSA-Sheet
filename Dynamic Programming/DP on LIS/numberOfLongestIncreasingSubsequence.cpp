#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> len(n, 1);  //stores length of LIS ending at i
        vector<int> count(n, 1);  //stores count of LIS ending at i with length len[i]

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                //if forms an increasing subsequence
                if(nums[j] < nums[i]) {

                    //found a better length
                    if(len[i] < len[j]+1) {
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    } 
                    
                    //same length
                    else if(len[i] == len[j]+1) {
                        count[i] += count[j];
                    }
                }
            }
  
        }

        int maxLen = 0; //length of LIS
        
        for(int i = 0; i < n; i++) {
            if(len[i] > maxLen) {
                maxLen = len[i];
                
            }
        }

        int cnt = 0; //count of LIS

        for(int i = 0; i < n; i++) {
            if(len[i] == maxLen) {
                cnt += count[i];
            }
        }

        return cnt;
    }
};