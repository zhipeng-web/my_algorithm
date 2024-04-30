#include <iostream>
#include <string>
using namespace std;




void reverse(string& s,int left, int right){
    int index =0;
    for(int j = left; j < (left+right)>>1; j++){
        swap(s[j],s[right-index]);
        index++;
    }
    cout <<s <<endl;
}
void replace(string & s ,string subString , int left, int right){
    int j =0;
    for(int i= left ; i <=right; i++){
        s[i] = subString[j++];
    }
    cout <<s<<endl;
}
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >>s;
    if (k==1){
        cout<< s;
        return 0;
    }
    string prev = string(s.begin(), s.begin() + k-1);
    reverse(s,0,k-1);

    for(int i =1; i< n; i++){
        if (i+k-1 >= n) break;
        string temp = string(s.begin()+i,s.begin()+i+k-2);
        prev = s[i+k-1] + prev;
        replace(s,prev,i ,i+k-1);
        prev = temp;
    }
    cout<<s;
}