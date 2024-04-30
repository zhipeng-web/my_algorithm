//
// Created by china on 2024/3/6.
//
#include "vector"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string, double>> hash;//哈希表，存放a/b的值，并表示a可以到达b
        for(int i=0;i<equations.size();i++){
            if(!hash.count(equations[i][0])){
                hash[equations[i][0]].emplace(equations[i][1],values[i]);
            }
            if(!hash.count(equations[i][1])){
                hash[equations[i][1]].emplace(equations[i][0],1/values[i]);
            }
        }

        for(int i=0;i<queries.size();i++){

        }
        vector<double> answer;
        return answer;
    }
};