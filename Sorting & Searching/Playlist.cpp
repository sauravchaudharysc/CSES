#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin>>n;
    vector<ll>arr;
    map<ll,ll>mp;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    ll i=0;
    ll j=0;
    while(i<n && j<n){
        if(mp.find(arr[i])!=mp.end() && mp[arr[i]]>=j){
            j=mp[arr[i]]+1;
        }
        mp[arr[i]]=i;
        ans=max(ans,i-j+1);
        i++;
    }
    cout<<ans<<endl;
}


