#include<bits/stdc++.h>

using ll=long long int;

using namespace std;

void start( ){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll>arr;
    ll low=0;
    ll high=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        low=max(low,x);
        high+=x;
        arr.push_back(x);
    }
    ll count;
    while(low<high){
        ll mid=((low+high)/2);
        ll sum=0;
        count=1;
        for(ll i=0;i<n;i++){
            if(sum+arr[i]>mid){
                count++;
                sum=0;
            }
            sum+=arr[i];
        }
        if(count>k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<low<<endl;
}
int main(){
    start();
}