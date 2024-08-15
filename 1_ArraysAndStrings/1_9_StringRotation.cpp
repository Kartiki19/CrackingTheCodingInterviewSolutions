#include<iostream>
using namespace std;

bool isRotation(string& s1, string& s2){
    if(s1.size() > 0 && s1.size() == s2.size()){
        s1 += s1;
        if(s1.find(s2) != string::npos) return true;
        return false;
    }
    return false;
}
int main(){
    string s1 = "kartiki";
    string s2 = "ikartik";
    cout << boolalpha << isRotation(s1,s2) << endl;
    return 0;
}