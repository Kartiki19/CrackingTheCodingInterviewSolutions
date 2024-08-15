#include<iostream>
using namespace std;

bool isPermutation(string s, string t){ /// O(nlogn) + O (mlogm) + O(n)
    if(s.size() != t.size()) return false;
    sort(s.begin(), s.end()); /// O(nlogn)
    sort(t.begin(), t.end()); /// O(mlogm)
    return (s==t); /// O(n)
}

bool isPermutationCharCount(string s, string t){ /// TC = O(N) + O(M) | SC =  O(128)
    if(s.size() != t.size()) return false;
    int count[128] = {0}; /// O(128)
    for(char c: s){ /// O(n)
        count[c-'a']++;
    }

    for(char c: t){ /// O(m)
        count[c-'a']--;
        if(count[c-'a'] < 0) return false;
    }
    return true;
}
int main(){
    string s = "abcde";
    string t = "ebcta";

    /// O(nlogn) + O (mlogm) + O(n)
    cout << "Using Sorting: " << s << " and " << t << " are permutations: " << boolalpha << isPermutation(s,t) << endl;

    /// TC = O(N) + O(M) | SC =  O(128)
    cout << "Using DS: " << s << " and " << t << " are permutations: " << boolalpha << isPermutationCharCount(s,t) << endl;
    return 0;
}