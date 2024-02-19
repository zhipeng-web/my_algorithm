//
// Created by china on 2023/12/19.
//
#include "iostream"
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        vector<string> list;
        for(int i=0;i<n;){
            // 将答案每一行可以装载的单词记录下来
            list.clear();
            list.push_back(words[i]);
            int cur = words[i++].length();
            while (i<n && cur+1+words[i].length()<=maxWidth){
                cur += 1 + words[i].length();
                list.push_back(words[i++]);
            }
            //最后一行，特殊处理
            if(i==n){
                string str=list.front();
                for(int j=1;j<list.size();j++){
                    str += " " + list[j];
                }
                while (str.length()<maxWidth){
                    str+=" ";
                }
                ans.push_back(str);
                break;
            }
            //一行只有一个单词的情况下
            int count = list.size();
            if(count==1){
                string str = list.front();
                while (str.length()<maxWidth){
                    str+=" ";
                }
                ans.push_back(str);
                continue;
            }
            //一般情况每行不止一个单词，也不是最后一行
            int wordWidth = cur - count + 1;//单词字符长度
            int spaceWidth = maxWidth -wordWidth;//空格字符长度
            int spaceItemWidth = spaceWidth/(count - 1);//每个单词之间平均有多少个单词
            string spaceItem(spaceItemWidth, ' ');
            string str = "";
            for(int j=0, sum=0;j<count;j++){
                string item = list[j];
                str += item;
                if(j==count-1){
                    break;
                }
                str+=spaceItem;
                sum += spaceItemWidth;
                //剩余空格间隙数量,还可以插入多少空格
                int remainSpace = count-j-1-1;
                if (remainSpace * spaceItemWidth + sum < spaceWidth) {
                    str+=" ";
                    sum++;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};