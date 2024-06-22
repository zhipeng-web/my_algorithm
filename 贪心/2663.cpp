//
// Created by china on 2024/6/22.
//
#include "string"
using namespace std;
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        k += 'a';
        int n = s.size();
        int i = n-1;
        s[i]++;
        while (i < n) {
            if (s[i] == k) { // 需要进位
                if (i == 0) { // 无法进位
                    return "";
                }
                // 进位
                s[i] = 'a';
                s[--i]++;//保证新生成的字符串大于原字符串s
            } else if (i && s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2]) {
                s[i]++; // 如果 s[i] 和左侧的字符形成回文串，就继续增加 s[i]
            } else {
                i++; // 反过来检查后面是否有回文串
            }
        }
        return s;
    }
};