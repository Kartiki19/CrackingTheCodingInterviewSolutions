#include<iostream>
#include<vector>
using namespace std;

void rotate_ninty(vector<vector<int>>& matrix){ /// O(n2)
    int n = matrix.size(); 
    for(int i = 0; i < matrix.size(); ++i){ /// O(n)
        for(int j = i+1; j < matrix[0].size(); ++j){ /// O(n)
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < n; ++i){ /// O(n)
        reverse(matrix[i].begin(), matrix[i].end()); /// O(n)
    }
}

void print_matrix(vector<vector<int>>& matrix){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> matrix =  {{1, 2, 3, 4}, 
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}};
    
    rotate_ninty(matrix); /// O(n2)
    print_matrix(matrix);
    return 0;
}