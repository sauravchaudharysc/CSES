#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    ll number=arr[arr.size()/2];
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=abs(arr[i]-number);
    }
    cout<<sum<<endl;
}