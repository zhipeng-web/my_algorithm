//
// Created by china on 2024/6/24.
//
#include "vector"
#include "stack"
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);//初始化数据，-1表示暂时没有更大的元素
        stack<int> stk;//单调栈,存储元素下标，从栈底到栈顶的下标在数组 nums 中对应的值是单调不升的。
        //但是注意到只遍历一次序列是不够的，例如序列 [2,3,1]，最后单调栈中将剩余 [3,1]，其中元素 [1] 的下一个更大元素还是不知道的。
       //一个朴素的思想是，我们可以把这个循环数组「拉直」，即复制该序列的前 n−1个元素拼接在原序列的后面。这样我们就可以将这个新序列当作普通序列，用上文的方法来处理。
       //在本题中，我们不需要显性地将该循环数组「拉直」，而只需要在处理时对下标取模即可。
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i%n]){
                ans[stk.top()] = nums[i%n];
                stk.pop();
            }
            stk.push(i%n);
        }
        return ans;
    }
};