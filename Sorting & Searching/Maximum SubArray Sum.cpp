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
    ll maxSum=INT_MIN;
    ll currSum=INT_MIN;
    for(ll i=0;i<n;i++){
        currSum=max(currSum+arr[i],arr[i]);
        maxSum=max(maxSum,currSum);
    }
    cout<<maxSum<<endl;
}