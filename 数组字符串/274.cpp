//
// Created by china on 2023/12/6.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n = citations.size();
       int total=0;
       vector<int> counter(n + 1);
       for(int i=0;i<n;i++){
           if(citations[i]>=n){
               counter[n]++;
           } else{
               counter[citations[i]]++;
           }
       }
       for(int i=n;i>=0;i--){
           total+=counter[i];
           if(total>=i){
               return i;

           }
       }
    }
};