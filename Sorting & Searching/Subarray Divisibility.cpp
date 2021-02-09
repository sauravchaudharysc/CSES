#include<bits/stdc++.h>
using namespace std;
#define ll long 
int main(){
    ll n,s,r;
    cin>>n;
    map<ll,ll>c;
    c[0]=1;
    r=s=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s+=x;
        ll ans=s%n;
        if(ans<0){
            ans=ans+n;
            r+=c[ans];
        }
        else if(c.find(ans)!=c.end()){
            r+=c[ans];
        }
        c[ans]++;
    }
    cout<<r;
}