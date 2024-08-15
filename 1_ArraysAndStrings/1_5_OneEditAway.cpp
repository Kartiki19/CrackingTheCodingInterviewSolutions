#include<iostream>
using namespace std;



bool isOneReplaceAway(string s1, string s2){
    bool diffFound = false;
    for(int i = 0; i < s1.size(); ++i){
        if(s1[i] != s2[i]){
            if(diffFound) return false;
            diffFound = true;
        }
    }
    return true;
}

bool isOneInsertDeleteAway(string s1, string s2){
    int i = 0, j = 0;
    while(i < s1.size() && j < s2.size()){
        if(s1[i] != s2[j]){
            if(i != j) return false;
            else j++;
        }
        else{
            i++;j++;
        }
    }
    return true;
}

bool isOneEditAway_1(string s1, string s2){
    if(s1.size() == s2.size()) return isOneReplaceAway(s1, s2);
    else if(s1.size() == s2.size() - 1) return isOneInsertDeleteAway(s1, s2);
    else if(s2.size() == s1.size() - 1) return isOneInsertDeleteAway(s2, s1);
    return false;
}
int main(){
    string s1 = "apple";
    string s2 = "able";

    cout << boolalpha << isOneEditAway_1(s1,s2) << endl;
}