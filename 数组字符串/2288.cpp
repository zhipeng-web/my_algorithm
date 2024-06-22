//
// Created by china on 2024/6/18.
//
#include <iostream>
#include "vector"
#include "queue"
#include "unordered_map"
#include "set"
#include "sstream"
#include "iomanip"
#include "regex"
using namespace std;
//class Solution { 超时
//public:
//    bool is_digits(const string &str) { //正则判断字符串是否只有数字
//        return regex_match(str, regex("^[0-9]+$"));
//    }
//
//    string discountPrices(string sentence, int discount) {
//        string ans = "";
//        double dazhe = 1 - discount / 100.0;
//        int left = 0, right = 0, n = sentence.size();
//        while (right <= n) {//将句子中的单词拆分， 这里<=n是为了统一处理，本来应该是<n
//            if (right == n || sentence[right] == ' ') { //到达空格或者字符串结束的时候
//                string word = sentence.substr(left, right - left);
//                left = right + 1;
//                //拼接单词
//                if (word.front() == '$' && is_digits(word.substr(1))) { //如果是美元
//                    double num = stoll(word.substr(1));
//                    num = num * dazhe;
//                    // 保留两位小数
//                    ostringstream stream;
//                    stream << fixed << setprecision(2) << (num);
//                    ans += " $" + stream.str();
//                } else {
//                    ans += ' ' + word; //拼接单词
//                }
//            }
//            right++;
//        }
//
//        ans = ans.substr(1, ans.size() - 1);
//        return ans;
//    }
//};

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double d = 1 - discount / 100.0;
        stringstream ss(sentence);
        string ans, w;
        while (ss >> w) { // 具体来说，stringstream 可以将一个字符串按照空格分割成多个单词（或者称为 token）。
            // 当你使用 >> 运算符从 stringstream 中读取数据时，它会从当前位置开始读取，直到遇到空格或者达到流的末尾为止。
            // 这样，每次操作 ss >> w 都会从 stringstream ss 中读取一个单词，并将其存储到变量 w 中
            if (!ans.empty()) {
                ans += ' ';
            }
            if (w.length() > 1 && w[0] == '$' && all_of(w.begin() + 1, w.end(), ::isdigit)) {
                stringstream s;
                s << fixed << setprecision(2) << '$' << stoll(w.substr(1)) * d;
                ans += s.str();
            } else {
                ans += w;
            }
        }
        return ans;
    }
};