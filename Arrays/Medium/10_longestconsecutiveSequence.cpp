#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        //base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        unordered_set<int> s;

        //store
        for(int num : nums) {
            s.insert(num);  //duplicates ignored
        }

        int maxLen = 0;  //stores maximum length found

        for(int num : s) {

            //start only if num is beginning of sequence
            if(!s.count(num - 1)) {
                int currNum = num;
                int currLen = 1;

                //extend sequence forward
                while(s.count(currNum + 1)) {
                    currNum++;
                    currLen++;
                }

                //update maximum length
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen; //longest consecutive sequence
        
    }
};