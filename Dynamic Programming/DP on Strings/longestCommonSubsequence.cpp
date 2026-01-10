#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int l1 = text1.length();
        int l2 = text2.length();

        if(text1 == text2) return l1;

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {

                //both are equal
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  //skip i or skip j
                }
            }
        }

        return dp[l1][l2];  //length of LCS   
    }
};