//
// Created by china on 2023/12/21.
//
#include "algorithm"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0, high=numbers.size()-1;
        int mid=0;
        while (low<high){
            mid = numbers[low] + numbers[high];
            if(mid == target){
                return {low, high};
            } else if(mid < target){
                low++;
            } else{
                high--;
            }
        }
        return {-1, -1};
    }
};