#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void start(){
    ll n,k;
    cin>>n;
    cin>>k;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    map<ll,ll>mp;
    ll count=0;
    ll left=0;
    for(ll i=0;i<n;i++){
        mp[arr[i]]++;
        //cout<<mp.size()<<" "<<k<<endl;
        while(mp.size()>k){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                auto it = mp.find(arr[left]);
                mp.erase(it);
            }
            left++;
          //  cout<<"yaha aay"<<endl;
        }
        count+=(i-left+1);
        //cout<<left<<" "<<i<<" "<<count<<endl;
    }
    cout<<count<<endl;
}

void print(vector<ll>arr){
    ll n=arr.size();
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    start();
}