//
// Created by china on 2023/12/29.
//
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int words_num = words.size(); //单词数量
        int word_l = words[0].length(); //单词长度

        int length = s.length(); //字符串长度
        unordered_map<string, int> myMap; //哈希表
        unordered_map<string, int> word_count; // 记录words里面各个单词个数
        vector<int> ans; //答案
        //统计words里面各个单词数量
        for(auto it = words.begin(); it!=words.end();it++){
            word_count[*it]++;
        }

        for(int i=0; i<word_l;i++){
           int left = i, right = i;
           myMap.clear();
           while (right + word_l <= length){
                string word = s.substr(right, word_l);
                right+=word_l;

                if(word_count.find(word) == word_count.end()){
                    left = right;
                    myMap.clear();
                } else{
                    myMap[word]++;
                    while (myMap[word]>word_count[word]){
                        myMap[s.substr(left, word_l)]--;
                        left+=word_l;
                    }

                    if(right - left == words_num * word_l){
                        ans.push_back(left);
                    }
                }
           }
        }
        return ans;
    }
};