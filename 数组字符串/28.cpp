//
// Created by china on 2023/12/19.
//
#include "iostream"
#include "string"
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length(), n=needle.length();
        if(m<n){
            return -1;
        }
        int i=0, j=0;
        while (i<m){
            if(haystack[i]!=needle[0]){
                i++;
            } else{
                for(j=0;j<n;){
                    if(haystack[i]!=needle[j]){
                        break;
                    }
                    i++, j++;
                }
                if(j==n){
                    return i - n;
                }
                i=i-j+1;
                j=0;
            }
        }
        return -1;
    }
};