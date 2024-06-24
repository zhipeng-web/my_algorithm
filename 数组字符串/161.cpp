//
// Created by china on 2024/6/23.
//
#include "string"
using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs(int((s.size() - t.size()))>=2)) return false;
        int count = 0;//两个字符串不同字符数
        if(s.size() == t.size()){//字符串长度相等情况
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] != t[i]) count++;
            }
        } else{//字符串长度不等，此时两个字符串长度差为1，令s为较长的字符串
            if(s.size()==0 || t.size()==0) return true; //若某个字符串为空串，返回true
            if(s.size()<t.size()){
                string temp = s;
                s = t;
                t = temp;
            }
            int i, j;
            for (i=0,j=0; i < s.size() && j<t.size(); ++i) {
                if(s[i] != t[j]){ //碰到不相等的，较短的字符串长度不变，较长的指针继续后移
                    count++;
                    continue;
                }
                j++;
            }
            count += s.size() -i;//防止出现t == s[0:s.size()-2]，最后一个字符没有判断情况
        }
        return count==1;
    }
};