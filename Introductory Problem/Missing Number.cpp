#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void getOutput(vector<ll>arr,ll n){
    ll sum=0;
    for(ll i=0;i<n-1;i++){
        sum+=arr[i];
    }
    ll tsum=n*(n+1)/2;
    cout<<tsum-sum<<endl;
}


int main(){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<n-1;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    getOutput(arr,n);
}