#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        int l1 = word1.length();
        int l2 = word2.length();

        if(word1 == word2) return 0;

        //number of total characters in both the strings
        int totalChars = l1+l2;

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

        for(int i = 1; i <= l1; i++) {
            for(int j =  1; j <= l2; j++) {

                //if both are equal
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] += dp[i-1][j-1] + 1;
                } 
                
                //skip i or skip j
                else {
                    dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //dp[l1][l2] is max num of character u need to keep in each string such that both strings are equal

        //min characters to be deleted to make strings equal;
        return totalChars - 2*dp[l1][l2]; 
    }
};