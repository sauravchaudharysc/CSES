#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void getOutput(ll n){
    for(ll i=1;i<=n;i++){
        if(!(i&1)){
            cout<<i<<" ";
        }
    }
    for(ll i=1;i<=n;i++){
        if(i&1){
            cout<<i<<" ";
        }
    }
}


int main(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"1";
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION";
    }else{
        getOutput(n);    
    }
}