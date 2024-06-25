//
// Created by china on 2024/6/25.
//
#include "string"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int left=0, right=0; //左右指针
        int n = s.size();
        if(n<3) return n;
        unordered_map<char, int> hashmap;//存储字符和字符在滑动窗口中最后出现的位置
        while (right<n){
            // 当滑动窗口包含小于 3 个字符
            hashmap[s[right]] = right;
            right++;

            if(hashmap.size() == 3){
                int del_index = INT_MAX;
                //找到最左边字符位置
                for (pair<char, int> element : hashmap) {
                    del_index = min(del_index, element.second);
                }
                hashmap.erase(s[del_index]);
                left = del_index + 1;

            }

            ans = max(ans, right - left);
        }
    }
};