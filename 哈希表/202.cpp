//
// Created by china on 2024/1/13.
//
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> hash;
        vector<int> nums;
        int sum = 0;
        while (sum!=1){
            sum = 0;
            nums.clear();
            while (n!=0){
                nums.push_back(n % 10);
                n = n/10;
            }
            for(int i=0;i<nums.size();i++){
                sum += nums[i] * nums[i];
            }
            if(++ hash[sum] > 1){
                return false;
            }
            n = sum;
        }
        return true;
    }
};