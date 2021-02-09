#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    ll x;
    cin>>n;
    cin>>x;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    ll count=0;
    ll i=0;
    ll j=n-1;
    while(i<j){
        if(arr[i]+arr[j]<=x){
            i++;
            j--;
        }else{
            j--;
        }
        count++;
    }
    if(i==j){
        count++;
    }
    cout<<count<<endl;
}