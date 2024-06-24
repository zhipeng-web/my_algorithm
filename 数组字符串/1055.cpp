//
// Created by china on 2024/6/24.
//
#include "string"
using namespace std;
class Solution {
public:
    int shortestWay(string source, string target) {

        // 标记源的所有字符的布尔数组
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // 检查源文件中是否存在目标文件的所有字符
        // 如果没有任何字符，返回 -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // 使用 mod 循环返回到源开始的源长度
        int m = source.length();

        // 源指针
        int sourceIterator = 0;

        // 遍历源的次数。当在目标 sourceIterator 中找到一个字符时，它将被加 1
        // 再次到达源的起点。
        int count = 0;

        // 在源中查找目标的所有字符
        for (char c : target) {

            // 如果在查找时，迭代器再次到达源的起始点，
            // 增量计数
            if (sourceIterator == 0) {
                count++;
            }

            // 找出 c 在 source 中的第一次出现
            while (source[sourceIterator] != c) {

                // 在返回开始时进行递增的公式。
                sourceIterator = (sourceIterator + 1) % m;

                // 如果在查找时，迭代器再次到达源的起始点，
                // 增量计数
                if (sourceIterator == 0) {
                    count++;
                }
            }

            // 当在源代码中找到 c 时，循环将中断。
            // 因此，在不清楚目标是否存在之前，剩余字符不需要增加计数
            sourceIterator = (sourceIterator + 1) % m;
        }

        // 返回数目
        return count;
    }
};