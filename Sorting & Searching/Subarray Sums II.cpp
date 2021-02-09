#include<bits/stdc++.h>
using namespace std;
#define ll long 
int main(){
    ll n,y,s,r;
    cin>>n>>y;
    map<ll,ll>c;
    c[0]=1;
    r=s=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s+=x;
        if(c.find(s-y)!=c.end()){
            r+=c[s-y];
        }
        c[s]++;
    }
    cout<<r;
}