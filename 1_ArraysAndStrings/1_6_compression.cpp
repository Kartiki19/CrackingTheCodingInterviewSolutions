#include<iostream>
using namespace std;

string compress(string s){
    int i = 0;
    int count = 1;
    string output = ""; /// O(2n)
    for(int j = 1; j < s.size(); ++j) /// O(n)
    {   
        if(s[i] == s[j]) count++;
        else{
            output += s[i];
            output += count + '0';
            count = 1;
            i = j;
        }
    }
    if(count > 0 && i < s.size()) {
        output += s[i];
        output += count + '0';
    }
    return (output.size() > s.size()) ? s : output;
}
int main(){
    string s = "abcd";
    cout << compress(s);
    return 0;
}