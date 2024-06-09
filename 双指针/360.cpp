//
// Created by china on 2024/6/9.
//
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int length = nums.size();
        vector<int> ans(length);
        int left = 0;
        int right = length - 1;
        int index_left = 0;
        int index_right = length - 1;
        if(a < 0) //此时抛物线开口向下,原来数组的两端的数最小
        {
            while(left <= right)
            {
                if(fun(nums[left], a, b, c) > fun(nums[right], a, b, c))
                {
                    ans[index_left++] = fun(nums[right--], a, b, c);
                }
                else
                {
                    ans[index_left++] = fun(nums[left++], a, b, c);
                }
            }
            return ans;
        }
        else if(a > 0) //此时抛物线开口向上，原来数组两端的数最大
        {
            while(left <= right)
            {
                if(fun(nums[left], a, b, c) < fun(nums[right], a, b, c))
                {
                    ans[index_right--] = fun(nums[right--], a, b, c);
                }
                else
                {
                    ans[index_right--] = fun(nums[left++], a, b, c);
                }
            }
            return ans;
        }
        else //此时a == 0，二次函数退化为了一次函数，根据b来判断函数的单调性
        {
            if(b > 0)
            {
                for(int i = 0; i < length; i++)
                {
                    ans[i] = fun(nums[i], 0, b, c);
                }

            }
            else
            {
                for(int i = 0; i < length; i++)
                {
                    ans[i] = fun(nums[length - i - 1], 0, b, c);
                }
            }
        }
        return ans;

    }

    int fun(int x, int a, int b, int c)
    {
        return a*x*x+b*x+c;
    }
};