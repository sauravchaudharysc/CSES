#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    ll t;
    cin>>n;
    cin>>t;
    vector<ll>arr;
    unordered_map<ll,ll>mp;
    vector<ll>temp;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
        temp.push_back(x);
        mp[x]=i;;
    }
    sort(temp.begin(),temp.end());
    
    // for(auto x:mp){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    // for(auto x:temp){
    //     cout<<x<<" ";
    // }
    while(t--){
        ll a;
        ll b;
        cin>>a>>b;
        ll h=mp[arr[a-1]];
        mp[arr[a-1]]=mp[arr[b-1]];
        mp[arr[b-1]]=h;
        ll count=1;
        ll idx=mp[temp[0]];
        for(ll i=1;i<n;i++){
            if(mp[temp[i]]<idx){
                count++;
            }
            idx=mp[temp[i]];
        }
        cout<<count<<endl;
    }
}