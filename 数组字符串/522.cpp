//
// Created by china on 2024/6/17.
//
#include "vector"
#include "string"
#include "algorithm"
using namespace std;
class Solution {
public:
    bool is_subseq(string& s, string& t){ //判断s是不是为t的子序列
       int index_s = 0;
       int index_t = 0;
       while (index_s<s.size() && index_t<t.size()){
            if(s[index_s] == t[index_t]){
                index_s++;
            }
            index_t++;
       }
        return index_s == s.size(); //相等代表s是t的子序列
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            bool flag = true; //标记当前字符串是否是特殊序列
            for (int j = 0; j < n; ++j) {
                if(i!=j && is_subseq(strs[i], strs[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int temp = strs[i].size();
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};