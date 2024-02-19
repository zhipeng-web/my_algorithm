//
// Created by china on 2024/1/11.
//
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count_char;
        int n = magazine.length();
        for(int i=0;i<n;i++){
            count_char[magazine[i]]++;
        }
        int m = ransomNote.length();
        for(int i=0;i<m;i++){
            count_char[ransomNote[i]]--;
            if(count_char[ransomNote[i]]<0){
                return false;
            }
        }
        return true;
    }
};