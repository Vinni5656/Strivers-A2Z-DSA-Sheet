#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        //longest palindromic subsequence is LCS of string and its reverse
        int l = s.length();

        string r = s;
        reverse(r.begin(), r.end()); //reverse of s

        if(s == r) return l;

        vector<vector<int>> dp(l+1, vector<int>(l+1, 0));

        for(int i = 1; i <= l; i++) {
            for(int j = 1; j <= l; j++) {

                //both are equal
                if(s[i-1] == r[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  //skip i or skip j
                }
            }
        }

        return dp[l][l];  //length of longest palindromic subsequence   
    }
};