#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void getOutput(ll n){
    vector<ll>ans;
    ans.push_back(n);
    while(n!=1){
        if(n&1){
            n=n*3+1;
        }else{
            n=n/2;
        }
        ans.push_back(n);
    }
    for(ll a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
}


int main(){
    ll n;
    cin>>n;
    getOutput(n);
}