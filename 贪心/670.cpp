//
// Created by china on 2024/6/15.
//
#include "vector"
#include "algorithm"
#include "string"
#include "algorithm"
using namespace std;
class Solution {
public:
    int traversal(vector<int> nums){
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = res * 10 + nums[i];
        }
        return res;
    }
    void swap(vector<int> &nums, int left, int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    int maximumSwap(int num) {
       string s = to_string(num);
       int n = s.length();
       int max_index = n-1;
       int p = -1, q;
       for(int i=n-2;i>=0;i--){
           if(s[i]>s[max_index]){
               max_index = i;
           } else{
               p = i;
               q = max_index;
           }
       }
       if(p == -1){
           return num;
       }
       ::swap(s[p], s[q]);
        return stoi(s);
    }
};