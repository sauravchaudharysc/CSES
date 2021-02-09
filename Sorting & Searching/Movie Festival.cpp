#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<int,int> x,pair<int,int>y){
    if(x.second==y.second){
        return (x.first<y.first);
    }
    return (x.second<y.second);
}
int main(){
    ll n;
    cin>>n;
    vector<pair<int,int>>arr;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end(),compare);
    ll count=1;
    ll end=arr[0].second;
    for(ll i=1;i<n;i++){
        if(arr[i].first>=end){
            end = arr[i].second;
            count++;
        }  
    }
    cout<<count<<endl;
}