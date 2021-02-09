#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void getOutput(vector<ll>arr,ll n){
    ll moves=0;
    for(ll i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            moves+=abs(arr[i+1]-arr[i]);
            arr[i+1]+=abs(arr[i+1]-arr[i]);
        }
    }
    cout<<moves<<endl;
}


int main(){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    getOutput(arr,n);    
    
}