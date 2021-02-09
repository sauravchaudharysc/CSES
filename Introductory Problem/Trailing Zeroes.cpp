#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll ans=0;
    //First Iteration meh kitne 5 h woh nikala
    //Second Iteration meh kitne 25 h woh nikala
    //Third Iteration meh kitne 125 woh nikala and so on...
    for(ll i=5;i<=n;i=i*5){
        ans+=(n/i);
    }
    cout<<ans<<endl;
}