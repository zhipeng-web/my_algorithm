//
// Created by china on 2023/12/25.
//
#include "iostream"
#include "unordered_set"
#include "string"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        int ans = -1;
        int left = 0,right=0;
        unordered_set<char> hash;
        while(right < n){
            while (!hash.count(s[right])){
                hash.insert(s[right]);
                right++;
            }
            ans = max(ans, right - left);
            hash.erase(s[left]);
            left++;
        }
        return ans;
    }
};
