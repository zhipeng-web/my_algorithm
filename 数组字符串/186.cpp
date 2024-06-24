//
// Created by china on 2024/6/24.
//
#include "vector"
#include "algorithm"
using namespace std;

/**
 * 将字符串中的每个单词反序，可以分成两步操作。
   第一步：将整个字符串反转，则所有的字符都变成反序，每个单词的位置变成反序后的位置，同时每个单词中的字母也变成反序。
   第二步：对每个单词，分别反转单词中的每个字母。
   两步操作之后，每个单词的字母顺序为正确顺序，同时单词的顺序被反转。
  上述操作都可以通过在字符串内部原地修改实现，因此额外空间复杂度是 O(1)。
 */


class Solution {
public:
    void transvel(vector<char>& s, int left, int right){//翻转区间字符串
        while(left<right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        //先将字符串整体翻转，这样最后面的单词就到最前面了，然后在将每一个单词翻转，这样单词就恢复正常
        reverse(s.begin(), s.end());
        for(right;right<n;right++){
            if(s[right] == ' '){//找到一个单词或者到达字符串末尾
                transvel(s,left, right-1);
                left = right+1;//更新下一个单词开始索引
            }
            if(right== n-1){//找到一个单词或者到达字符串末尾
                transvel(s,left, right);
                left = right+1;//更新下一个单词开始索引
            }
        }
    }
};