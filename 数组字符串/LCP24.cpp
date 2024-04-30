//
// Created by china on 2024/4/22.
//
#include "vector"
#include "algorithm"
#include "queue"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<int> numsGame(vector<int> &nums) {
        const int MOD = 1'000'000'007;
        vector<int> ans(nums.size());
        priority_queue<int> left;//大根堆，维护较小一半
        priority_queue<int, vector<int>,greater<int>> right;// 维护较大的一半，小根堆
        long long left_sum = 0, right_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int b = nums[i] - i;
            if(i%2==0){ //前缀长度为奇数
                if(!left.empty() && b<left.top()){
                    // 如果left为空，b入左边。或者b比left.top()小，b入左边。
                    // 同时将left最大值移除left，加入right
                    left_sum -= left.top() - b;
                    left.push(b);
                    b = left.top();
                    left.pop();
                }
                right_sum += b;
                right.push(b);
                ans[i] =  (right_sum - right.top() - left_sum) % MOD;//中位数不用动
            } else{
                // b比right.top()大，b入右边
                // 同时将right最小值移除right，加入left
                if(b > right.top()){
                    right_sum += b - right.top();
                    right.push(b);
                    b = right.top();
                    right.pop();
                }
                left_sum += b;
                left.push(b);
                ans[i] = (right_sum - left_sum) % MOD;
            }
        }
        return ans;
    }
};