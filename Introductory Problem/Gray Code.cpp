#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    
    ll n,length;
    cin>>n;
    length=n;
    n=1<<n;
    ll x;
    for(int i=0;i<n;i++){
        x=i^i>>1;
        string s="";
        for(int j=0;j<length;j++){
            if(x&1){
                s='1'+s;
            }else{
                s='0'+s;
            }
            x=x>>1;
        }
        cout<<s<<endl;
    }   
}