#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    vector<pair<int,int>>arr;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,1));
        arr.push_back(make_pair(b,-1));
    }
    sort(arr.begin(),arr.end());
    ll maxCount=0;
    ll count=0;
    for(ll i=0;i<2*n;i++){
        count+=arr[i].second;
        maxCount=max(count,maxCount);
    }
    cout<<maxCount<<endl;
}