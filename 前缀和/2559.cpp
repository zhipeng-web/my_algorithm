//
// Created by china on 2024/7/2.
//
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const string str = "aeiou";
        int n = words.size();
        vector<int> ans(queries.size());
        int pre_sum[n+1];
        pre_sum[0] = 0;
        for (int i = 0; i <= n ; ++i) {
            //判断字符串首尾是否是元音
            if(str.find(words[i].front()) != string::npos && str.find(words[i].back()) != string::npos){
                pre_sum[i+1] = pre_sum[i]+1;
            } else{
                pre_sum[i+1] = pre_sum[i];
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = pre_sum[queries[i][1]+1] - pre_sum[queries[i][0]];
        }
        return ans;
    }
};