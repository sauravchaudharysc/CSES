#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
vector<ll> start(){
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    return arr;
}

void print(vector<ll>arr){
    ll n=arr.size();
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

ll csum(vector<ll>arr){
    ll n=arr.size();
    ll sum=0;
    for(auto x:arr){
        sum+=x;
    }
    return sum;
}

ll ans=0;

void getSusbet(ll sum,vector<ll>arr,int i,int n,ll csum){
    if(i==n){
        if(sum<=csum)
        ans=max(ans,sum);
        return;
    }
    getSusbet(sum+arr[i],arr,i+1,n,csum);
    getSusbet(sum,arr,i+1,n,csum);
}



int main(){
    vector<ll>arr=start();
    //print(arr);
    ll n=arr.size();
    ll cumsum=csum(arr);
    // cout<<cumsum<<endl;
    getSusbet(0,arr,0,n,cumsum/2);
    cout<<cumsum-2*ans<<endl;
}