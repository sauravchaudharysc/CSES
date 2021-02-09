#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        ll position=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(position<arr.size()){
            arr[position]=x;
        }else{
            arr.push_back(x);
        }
    }
    cout<<arr.size()<<endl;
}