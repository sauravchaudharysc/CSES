#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    stack<pair<ll,ll>>St;
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        while(!St.empty() && St.top().first>=x){
            St.pop();
        }
        if(St.empty()){
            St.push({x,i+1});
            ans.push_back(0);
            continue;
        }
        ans.push_back(St.top().second);
        St.push({x,i+1});
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}