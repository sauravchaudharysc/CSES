#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void start(){
    ll n,k;
    cin>>n;
    cin>>k;
    vector<ll>arr;
    ll low=INT_MAX;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        low=min(x,low);
        arr.push_back(x);
    }
    ll high=low*k;
    while(low<high){
        ll mid = (low+high)/2;
        ll count=0;
        for(ll i=0;i<n;i++){
            count+=(mid/arr[i]);
        }
        if(count<k){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    cout<<low<<endl;
}

int main(){
    start();
}