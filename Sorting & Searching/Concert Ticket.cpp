#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n,k;
    cin>>n>>k;
    multiset<ll>mp;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        mp.insert(x);
    }
    for(ll i=0;i<k;i++){
        ll myPrice;
        cin>>myPrice;
        if(mp.empty()){
            cout<<"-1"<<endl;
            continue;
        }
        auto it=mp.lower_bound(myPrice);
        if(it==mp.end()){
            cout<<*(--it)<<endl;
        }
        else {
            if(*it>myPrice){
                if(it==mp.begin()){
                    cout<<"-1"<<endl;
                    continue;
                }else{
                    cout<<*(--it)<<endl;
                }
            }else{
                cout<<*(it)<<endl;
            }
        }
        mp.erase(it);
    }
}