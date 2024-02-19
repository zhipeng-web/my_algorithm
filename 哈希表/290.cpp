//
// Created by china on 2024/1/12.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        vector<string> words; //存放字符串s中所有单词
        s+= ' ';//最后一个单词后面加空格，统一处理
        while (s.length() != 0) {
            int index = s.find_first_of(' '); //空格为分隔符划分单词
            string str = s.substr(0, index);
            words.push_back(str);
            s = s.substr(index + 1); // 每处理一个单词，就将它从字符串s中移除
        }
        if(pattern.length() != words.size()){
            return false;
        }
        unordered_map<char, string> p_s; //两个映射关系
        unordered_map<string, char> s_p;
        for (int i = 0; i < n; i++) {
            if(p_s.count(pattern[i])!=0 && p_s[pattern[i]]!=words[i]){
                return false;
            }
            if(s_p.count(words[i])!=0 && s_p[words[i]] != pattern[i]){
                return false;
            }
            p_s[pattern[i]] = words[i];
            s_p[words[i]] = pattern[i];
        }
        return true;
    }
};