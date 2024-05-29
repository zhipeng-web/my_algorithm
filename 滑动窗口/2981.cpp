//
// Created by china on 2024/5/29.
//
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<int> groups[26]; //hash表
        int cnt = 0, n = s.length(); //cnt 记录连续字符长度
        int ans = 0;
        for(int i=0;i<n;i++){
            cnt++;
            if(i+1 == n || s[i] != s[i+1]){
                groups[s[i] - 'a'].push_back(cnt);//记录连续字符长度
                cnt = 0;
            }
        }

        for(int i=0;i<26;i++){
            auto it = groups[i];
            if(it.empty()) continue;
            sort(it.begin(),it.end(),greater<int>());
            it.push_back(0);
            it.push_back(0);//放两个0就无需考虑字母对应的长度列表小于3的情况
            ans = max({ans, it[0] - 2, min(it[0] - 1, it[1]), it[2]});
        }
        return ans?ans:0;
    }
};

