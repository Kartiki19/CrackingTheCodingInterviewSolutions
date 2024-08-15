#include<iostream>
using namespace std;
int getCharId(char c){
    int id = -1;
    if(c >= 'a' && c <= 'z') id = c - 'a';
    else if(c >= 'A' && c <= 'Z') id = c - 'A';
    return id;
}

void countCharFrequency(string& s, int frequency[]){
    for(char c: s){ /// O(n)
        int id = getCharId(c);
        if(id != -1) frequency[id]++;
    }
}

bool isPalPurmutation_1(string s){ /// O(n) + O(26) | O(26)
    int frequency[26] = {0}; /// O(26)
    countCharFrequency(s, frequency); /// O(n)
    bool oddAppreared = false;
    for(int i = 0; i < 26; ++i){ /// O(26)
        if(frequency[i]%2 == 1){
            if(oddAppreared) return false;
            else oddAppreared = true;
        }
    }
    return true;
}

bool isPalPurmutation_2(string s){ /// O(n) | O(26)
    int frequency[26] = {0}; /// O(26)
    int oddCount = 0;
    for(int i = 0; i < s.size(); ++i){ /// O(n)
        int id = getCharId(s[i]);
        if(id != -1){
            frequency[id]++;
            if(frequency[id]%2 == 1)
                oddCount++;
            else oddCount--;
        }
    }
    return oddCount <= 1;

}
int toggle( int bitVector, int index )
{
    if(index < 0) return bitVector;
    int mask = 1 << index;

    if((bitVector & mask) == 0){ /// bitvector is not set
        bitVector |= mask;
    }
    else{ /// bitvector is set
        bitVector &= ~mask;
    }
    return bitVector;
}

bool isExactlyOneBitSet( int bitVector )
{
    return ((bitVector & (bitVector - 1)) == 0);
}

bool isPalPurmutation_3(string & str )/// O(n)
{
    int bitvector = 0;
    int id = 0;
    for(char c: str){ /// O(n)
        id = getCharId(c);
        bitvector = toggle(bitvector, id);
    }

    return (bitvector == 0 || isExactlyOneBitSet(bitvector));
}


int main(){

    string str_1 = "Tact Coa";
    string str_2 = "A big Cat";
    string str_3 = " Aba cbc";
    cout << "\n";
    cout << str_1 << " Using Char Frequency array: "<< boolalpha << isPalPurmutation_1(str_1) << endl; /// O(n) + O(26) | O(26)
    cout << str_1 << " Using on the go: "<< boolalpha << isPalPurmutation_2(str_1) << endl; /// O(n) | O(26)
    cout << str_1 << " Using bit: "<< boolalpha << isPalPurmutation_3(str_1)<< endl; /// O(n)
    
    cout << "\n";
    cout << str_2 << " Using Char Frequency array: "<< boolalpha << isPalPurmutation_1(str_2)<< endl;
    cout << str_2 << " Using on the go: "<< boolalpha << isPalPurmutation_2(str_2)<< endl;
    cout << str_2 << " Using bit: "<< boolalpha << isPalPurmutation_3(str_2)<< endl;

    cout << "\n";
    cout << str_3 << " Using Char Frequency array: "<< boolalpha << isPalPurmutation_1(str_3)<< endl;
    cout << str_3 << " Using on the go: "<< boolalpha << isPalPurmutation_2(str_3)<< endl;
    cout << str_3 << " Using bit: "<< boolalpha << isPalPurmutation_3(str_3)<< endl;
    return 0;
}