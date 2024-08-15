#include<iostream>
#include<vector>
using namespace std;
bool isUniqueChars(string str){ /// O(n) , O(128)
    int n = str.size();
    if (n >  128) return false;
    vector<bool> charSet(128, 0); /// O(128)
    for(char c: str){ /// O(n)
        if(charSet[c - 'a']) return false;
        charSet[c-'a'] = true;
    }
    return true;
}

bool isUniqueBitSet(string str){ /// O(n) ///  O(n/8)
    /// Bool vetors take 8 bits for each value
    /// bit set reduces size by factor of 8
    bitset<256> bits(0); /// O(n/8)
    for(int i = 0; i < str.size(); ++i){ /// O(n)
        int val = str[i];
        if(bits.test(val)) return false;
        bits.set(val);
    }
    return true;
}

bool isUniqueNoDS(string str){ /// O(n2)
    int n = str.size();
    for(int i = 0; i < n; ++i){ /// O(n)
        for(int j = i+1; j < n; ++j){ /// O(n)
            if(str[i] == str[j]) return false;
        }
    }
    return true;
}

bool isUniqueSorting(string str){ /// O(n log n)
    sort(str.begin(), str.end());  /// O(n log n)
    for(int i = 0; i < str.size()-1; ++i){ /// O(n)
        if(str[i] == str[i+1]) return false;
    }
    return true;
}


int main(){
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};

    /// TC = O(n) | SC = O(128)
    cout << "\nUsing Vector " << endl;
    for(string w: words){
        cout << w << " : " << boolalpha << isUniqueChars(w) << endl;
    }

    /// TC = O(n) | SC = O(n/8)
    cout << "\nUsing Bit set " << endl;
    for(string w: words){
        cout << w << " : " << boolalpha << isUniqueBitSet(w) << endl;
    }

    /// O(n2)
    cout << "\nWithout DS " << endl;
    for(string w: words){
        cout << w << " : " << boolalpha << isUniqueNoDS(w) << endl;
    }

    /// O(n log n)
    cout << "\nWith sorting " << endl; 
    for(string w: words){
        cout << w << " : " << boolalpha << isUniqueSorting(w) << endl;
    }
    return 0;
}