#include <iostream>
#include <string>
#include "vector"
#include "algorithm"
#include <limits>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size() - 1){//如果需要赢n-1场，只有数组最大值做的到，返回即可
            sort(arr.begin(),arr.end());
            return arr.back();
        }
        int count = 0;//连赢场数
        int index = 1;//下一个上场的数的下标
        int n = arr.size();
        int fast = arr[0];//擂主，数组第一个元素
        while (count != k){
            if(fast>arr[index%n]){
                count++;
                index++;
            }
            else if(fast == arr[index%n]){//匹配到自己跳过
                index++;
            }
            else{
                fast = arr[index];//擂主换数
                count = 1;//换擂主的时候已经赢了一场
                index++;
            }
        }
        return fast;
    }
};


int main() {
    Solution solution;
    vector<int> a = {2,1,3,5,4,6,7};
    cout<<solution.getWinner(a,2);
}