//
// Created by china on 2024/5/22.
//
#include "string"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        //公牛数量，母牛数量
        int record_secret[10];
        int record_guess[10];
        int countBulls = 0;
        int countCows = 0;
        for (int i = 0; i < n; ++i) {
            // 哈希表，统计string secret, string guess字符数量各有多少
            record_secret[secret[i]-'0']++;
            record_guess[guess[i]-'0']++;
            if(secret[i] == guess[i]){ //公牛数++，同时将哈希表--，计算母牛数，
                countBulls++;
                record_secret[secret[i]-'0']--;
                record_guess[guess[i]-'0']--;
            }
        }
        for (int i = 0; i < 10; ++i) { //计算母牛数
            countCows += min(record_guess[i],record_secret[i]);
        }
        string ans= to_string(countBulls) + "A" + to_string(countCows) + "B";
        return ans;
    }
};