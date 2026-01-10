#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        //sort words vector by length
        sort(words.begin(), words.end(), [](const string &a, const string& b) {
            return a.size() < b.size();
        });
        
        //stores length of longest string chain
        int maxLen = 0;

        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                //if forms a chain
                if(words[i].length() - words[j].length() == 1 && isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            } 

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    //checks if string a is predecessor of string b
    bool isPredecessor(const string& a, const string& b) {

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == a.size();
    }
};