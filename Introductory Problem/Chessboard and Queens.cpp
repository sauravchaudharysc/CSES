#include<bits/stdc++.h>
using namespace std;
bool isSafe(int board[][8],int i,int j,int n)
{
    //Column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    //Left Diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //Right Diagonal  
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    //The Position is safe if it crosses above cases
    return true;
}

int counter=0;

bool solveNQueen(int board[][8],int i,int n)
{
    if(i==n) //Queens have been sucessfully placed
    {
        //Print the board
        counter++;
        return false;
    }
    //Recursive case
    //In recursion take assumption the remaining sub-grid will be filled by recursion
    //Try to place the queen in current row and call the remaining part
    for(int j=0;j<n;j++)
    {
        //Check for Position which you are placing the queen is safe or not
        if(isSafe(board,i,j,n) && board[i][j]!='*')
        {
            board[i][j]=1;
            bool restOfTheQueens=solveNQueen(board,i+1,n);
            if(restOfTheQueens)
            {
                return true;
            }
            //Backtrack,since our assumption is false so we need to correct it.
            board[i][j]=0;
        }
        
    }
    //Tried all position in current row
    return false;
}


int main()
{
    int board[8][8];
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            board[i][j]=s[j];
        }
    }
    solveNQueen(board,0,8);
    cout<<counter<<endl;
}