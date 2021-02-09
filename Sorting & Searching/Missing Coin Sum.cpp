#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll minimum=1;
    vector<int>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]>minimum){
            cout<<minimum<<endl;
            return 0;
        }
        minimum+=arr[i];
    }
    cout<<minimum<<endl;
}
