#include<iostream>
#include<vector>
using namespace std;

void print_matrix(vector<vector<int>>& matrix){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void nullify_row(int row, vector<vector<int>>& m){
    for(int i = 0; i < m[0].size(); ++i)
        m[row][i] = 0;
}


void nullify_col(int col, vector<vector<int>>& m){
    for(int i = 0; i < m.size(); ++i)
        m[i][col] = 0;
}

void zero_matrix(vector<vector<int>>& matrix){ /// TC = O(mn) + O(mn) + O(mn) | SC = O(n) + O(m)
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> row(n, false); /// O(n)
    vector<bool> col(m, false); /// O(m)

    for(int i = 0; i < n; ++i){ /// O(nm)
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0; i < n; ++i){ /// O(nm)
        if(row[i]) nullify_row(i, matrix); /// O(m)
    }


    for(int i = 0; i < m; ++i){ /// O(mn)
        if(col[i]) nullify_col(i, matrix); /// O(n)
    }
}

void zero_matrix_1(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    bool hasZeroRow = false;
    bool hasZeroCol = false;
    for(int i = 0; i < m; ++i){
        if(matrix[0][i] == 0) hasZeroRow = true;
    }

    for(int i = 0; i < n; ++i){
        if(matrix[i][0] == 0) hasZeroCol = true;
    }

    for(int i = 1; i < n; ++i){ /// O(nm)
        for(int j = 1; j < m; ++j){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    /*                              {{0, 2, 3, 4}, 
                                    {0, 6, 0, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16},
                                    {17, 0, 19, 20}};*/

    for(int i = 1; i < m; ++i){
        if(matrix[0][i] == 0) nullify_col(i, matrix);
    }


    for(int i = 1 ; i < n; ++i){
        if(matrix[i][0] == 0) nullify_row(i, matrix);
    }

    if(hasZeroRow) nullify_row(0, matrix);
    if(hasZeroCol) nullify_col(0, matrix);
}

int main(){
    vector<vector<int>> matrix = {{0, 2, 3, 4}, 
                                    {0, 6, 0, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16},
                                    {17, 0, 19, 20}};

    /// TC = O(mn) + O(mn) + O(mn) | SC = O(n) + O(m)
    ///zero_matrix(matrix);   

    zero_matrix_1(matrix); 
    print_matrix(matrix);                                 
    return 0;
}