//
// Created by china on 2024/1/13.
//
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<string> assist(strs);//辅助数组
        unordered_map<string, vector<int>> hash;//哈希表
        for(int i=0;i<assist.size();i++){
            sort(assist[i].begin(), assist[i].end());//首先将每一组字符串排序，排序后字母异位词相同的字符串就一样了
            hash[assist[i]].push_back(i);//记录每一组字母异位词的下标
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            vector<string> team;
            for(int i=0;i<it->second.size();i++){
                team.push_back(strs[it->second[i]]);//将异位词相同的字符串的下标去除
            }
            answer.push_back(team);
        }
        return answer;
    }
};