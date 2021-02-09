#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
 ll n;
 cin>>n;
 vector<pair<ll,ll>>arr;
 for(ll i=0;i<n;i++){
     ll x,y;
     cin>>x>>y;
     arr.push_back(make_pair(x,y));
 }
 sort(arr.begin(),arr.end());
 ll count=0;
 ll end=0;
 for(ll i=0;i<n;i++){
     count+=(arr[i].second-(arr[i].first+end));
     end=arr[i].first+end;
 }
 cout<<count<<endl;
}