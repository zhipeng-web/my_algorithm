//
// Created by china on 2023/12/14.
//
#include "iostream"
#include "map"
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        map<char, int> own_map;
        string answer = "";
        string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        answer += thousands[num/1000];
        num %= 1000;
        answer += hundreds[num/100];
        num %= 100;
        answer += tens[num/10];
        num %= 10;
        answer += ones[num];
        return answer;
    }
};