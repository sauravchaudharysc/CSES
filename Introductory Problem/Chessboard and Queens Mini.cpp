#include<bits/stdc++.h>
using namespace std;
bool col[8]={0};
bool leftUpperDiag[15]={0};
bool rightUpperDiag[15]={0};
void solve(vector<string> s,int &count,int i){
    if(i==8){
        count++;
        return;
    }else{
        for(int j=0;j<8;j++){
            if(!col[j] && s[i][j]=='.' && !leftUpperDiag[i-j+7] && !rightUpperDiag[i+j] ){
                col[j]=1;
                leftUpperDiag[i-j+7]=1;
                rightUpperDiag[i+j]=1;
                solve(s,count,i+1);
                  col[j]=0;
                leftUpperDiag[i-j+7]=0;
                rightUpperDiag[i+j]=0;
            }
              
        }
    }
}
int main(){
    vector<string>v;
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int count=0;
    solve(v,count,0);
    cout<<count<<endl;
}