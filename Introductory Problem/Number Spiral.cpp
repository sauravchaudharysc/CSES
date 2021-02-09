#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(x==1 && y==1){
            cout<<"1"<<endl;
            continue;
        }
        ll row=max(x,y);
        ll sum=row*row;
        ans = sum-(row-1);
        if(row & 1)
        ans = ans-(x-y);
        else
        ans = ans+(x-y);
        
        cout<<ans<<endl;
    }
}