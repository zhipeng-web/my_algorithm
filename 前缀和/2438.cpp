//
// Created by china on 2024/7/3.
//
#include "vector"
#include "cmath"
using namespace std;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> nums;
        const long long mod = 1e9 + 7;
        while (n>0){
            long long lb = n & (-n);
            // 获取最低位的1
            // 这一行代码是用来找到n的最低位的1（即二进制表示中最右边的1）。这是因为 -n 在二进制补码表示中会反转n的除了最低位1之外的所有位，所以 n & -n 就会得到这个最低位1的值。
            nums.push_back(lb);
            n ^= lb;
            // 清除最低位的1, ^= 是按位异或赋值运算符。异或（XOR）运算是二进制运算中的一种，其特点是当两个比特相同时结果为0，不同时结果为1。具体到这个表达式：
            // lb 的值是 n 的二进制表示中最低位的 1。
           //当我们对 n 和 lb 进行异或运算时，lb 中的 1 会与 n 中相对应的 1 异或，结果变为 0，而 n 中其他位保持不变（因为 lb 的其他位是 0，与任何数异或都保持原样）。
        }
        vector<int> ans;
        for (auto query : queries) {
            int mul = 1;
            for(int i= query[0];i<=query[1];i++){
                mul = mul * (nums[i] % mod);
                mul %= mod;
            }
            ans.push_back(mul);
        }
        return ans;
    }
};
