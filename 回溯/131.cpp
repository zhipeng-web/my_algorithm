//
// Created by china on 2024/6/12.
//
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool judge(string str){
        int left = 0;
        int right = str.size()-1;
        while(left<=right){
            if(str[left]!= str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrace(int start, string s){//
        if(start>=s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            string substr = s.substr(start, i-start+1); //切割子串
            if(judge(substr)){
                path.push_back(substr);
            }else{
                continue;
            }
            backtrace(i+1, s);
            path.pop_back();
        }

    }
    vector<vector<string>> partition(string s) {
        backtrace(0, s);
        return ans;
    }
};