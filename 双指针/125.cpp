//
// Created by china on 2023/12/20.
//
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str="";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
               str += tolower(s[i]);
            } else if(isdigit(s[i])){
                str += s[i];
            }
        }
        n=str.length();
        int i=0,j=n-1;
        while (i<j){
            if(str[i]==str[j]){
                i++;
                j--;
            } else{
                return false;
            }
        }
        return true;
    }
};
