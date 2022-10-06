#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isvalid(int n, int row, int col){
    for(int i = row-1; i >= 0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    for(int i = row-1, j=col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}


void nqueenshelper(int n, int s){
    if(s == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(isvalid(n, s, i)){
            board[s][i] = 1;
            nqueenshelper(n, s+1);
            board[s][i] = 0;
        }
    }
}

void nqueens(int n){
    memset(board, 0, 11*11*4);
    nqueenshelper(n, 0);
}    
    
int main(){
    int n;
    cin >> n;
    nqueens(n);
    
    return 0;
}
