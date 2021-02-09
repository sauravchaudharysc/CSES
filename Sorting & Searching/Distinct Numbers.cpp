#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    map<int,int>mp;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        mp[x]++;
    }
    cout<<mp.size()<<endl;    
}