#include<iostream>
using namespace std;

string URLify(string s, int n){ /// O(n) | O(n)
    string output = ""; /// O(n)
    for(char c: s){ /// O(n)
        if(c == ' ')
            output += "%20";
        else 
            output += c;
    }
    return output;
}

void URLifyWithoutNewStr(char *s, int n){ /// O(n)
    int spaceCount = 0;
    for(int i = 0; i < n; ++i){ /// O(n)
        if(s[i] == ' ') spaceCount++;
    }

    int extendedLength = n + spaceCount * 2;
    int j = extendedLength -1;

    for(int i = n-1; i >= 0; i--){ /// O(n)
        if(s[i] != ' '){
            s[j--] = s[i];
        }
        else{
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
    }
}


int main(){
    char s[] = "Mr John Smith    ";
    string t = "Mr John Smith";

    /// TC = O(n) | SC = O(n)
    cout << "With new String: "<< URLify(t, t.size()) << endl;

    /// TC = O(n)
    URLifyWithoutNewStr(s, 13) ;
    cout << "Without DS: " << s << endl;
    return 0;
}