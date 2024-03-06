#include<iostream>
using namespace std;

bool possible(int sudoku[9][9],int r, int c,int n){
    for(int i=0;i<9;i++){
        if(sudoku[r][i]==n)
            return false;
        if(sudoku[i][c]==n)
            return false;
        if(sudoku[3*(r/3)+i/3][3*(c/3)+i%3]==n)
            return false;
    }
    return true;
}

bool solve(int sudoku[9][9],int r, int c){
    if(r==9)
        return true;
    int row=0,col=0;
    if(c!=8){
        row=r;
        col=c+1;
    }
    else{
        row=r+1;
        col=0;
    }
    if(sudoku[r][c]==0){
        for(int i=1;i<=9;i++){
            if(possible(sudoku,r,c,i)){
                sudoku[r][c]=i;
                if(solve(sudoku,row,col))
                    return true;
                else
                    sudoku[r][c]=0;
            }
        }
    }
    else{
        if(solve(sudoku,row,col))
            return true;
    }
    return false;
}

int main(){
    int sudoku[9][9];
    cout<<"Enter the sudoku to be solved: "<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>sudoku[i][j];
    }
    if(solve(sudoku,0,0)){
        cout<<"Solved sudoku: "<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<" ";
                if((j+1)%3==0)
                    cout<<"| ";
            }
            cout<<endl;
            if((i+1)%3==0)
                    cout<<"_ _ _ _ _ _ _ _ _ _ _ _"<<endl;
            cout<<endl;
        }
    }
    else
        cout<<"Not possible to solve...."<<endl;
    return 0;
}
