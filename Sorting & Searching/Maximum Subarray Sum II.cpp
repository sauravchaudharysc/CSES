#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>arr(n+1);
    arr[0]=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i+1];
        arr[i+1]+=arr[i];
    }
    set<pair<ll,ll>>st;
    ll ans=-1e19;
    for(ll i=0;i<=n;i++){
        if(i>=a){
            st.insert({arr[i-a],i-a});
        }
        if(st.size()){
            ans=max(arr[i]-(st.begin()->first),ans);
        }
        if(i>=b){
            st.erase({arr[i-b],i-b});
        }
    }
    cout<<ans<<endl;
}