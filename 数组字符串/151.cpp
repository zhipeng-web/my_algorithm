//
// Created by china on 2023/12/18.
//
#include "string"
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0, n=s.length();
        string ans = "";
        while (i<n){
            if(s[i]==' '){
                i++;
            } else{
                break;
            }
        }
        j=i;
        while (i<n){
            if(s[i]!=' '){
                i++;
            } else{
                ans = s.substr(j, i-j) + ' ' + ans;
                while (i<n){
                    if(s[i]==' '){
                        i++;
                    } else{
                        break;
                    }
                }
                j=i;
            }
        }
        ans = s.substr(j, i-j) + ' ' + ans;
        int start = ans.find_first_not_of(' ');
        int end = ans.find_last_of(' ');
        return ans.substr(start, end-start);
    }
};