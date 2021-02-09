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
    vector<ll>ans1;
    vector<ll>ans2;
    for(ll i=0;i<n;i++){
        ll mark1=0;
        ll mark2=0;
        for(ll j=0;j<n;j++){
            if(i==j)continue;
            if(arr[i].first<=arr[j].first && arr[j].second<=arr[i].second) mark1+=1;
            if(arr[i].first>=arr[j].first && arr[j].second>=arr[i].second) mark2+=1;
        }
        if(mark1){
            ans1.push_back(mark1);
        }else{
            ans1.push_back(0);
        }
        if(mark2){
            ans2.push_back(mark2);
        }else{
            ans2.push_back(0);
        }        
    }
    for(auto x:ans1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:ans2){
        cout<<x<<" ";
    }    
}