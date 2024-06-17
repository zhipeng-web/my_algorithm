//
// Created by china on 2024/6/17.
//
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> map; //key是前缀和，v是索引
        map[0] = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if(num == 1) count++;
            if(num == 0) count--;
            if(map.find(count) != map.end()){ //前缀和已经出现过一次，更新ans
                ans = max(ans, i - map[count]);
            } else{
                map[count] = i;
            }
        }
        return ans;
    }
};
/**
 *
根据题意，我们可以轻易发现如下性质：如果答案非 0，那么子数组长度必然为偶数，且长度至少为 2。
具体的，我们在预处理前缀和时，将 nums[i]为0 的值当做 −1 处理。
从而将问题转化为：如何求得最长一段区间和为 的子数组。 同时使用哈希表来记录某个前缀和出现的最小下标是多少。
*/
