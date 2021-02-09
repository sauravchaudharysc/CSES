#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll target;
    cin>>target;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll count=0;
    ll sum=arr[0];
    ll j=0;
    if(sum==target)count++;
    for(ll i=1;i<n;i++){
        sum+=arr[i];
        while(sum>target){
            sum-=arr[j];
            j++;
        }
        if(sum==target){
            count++;
            sum-=arr[j];
            j++;
        }
    }
    cout<<count<<endl;
}