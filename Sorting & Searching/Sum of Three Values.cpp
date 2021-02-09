#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n,sum;
    cin>>n>>sum;
    vector<pair<ll,ll>>arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(make_pair(x,i));
    }
    sort(arr.begin(),arr.end());
    set<ll>st;
    for(ll i=0;i<n;i++){
        ll x=i;
        bool chosen=i;
        ll y=0,z=n-1;
        while(y<z){
            if(chosen==y){
                y++;
                continue;
            }    
            if(chosen==z){
                z--;
                continue;
            }    
            ll total=arr[x].first+arr[y].first+arr[z].first;
            //cout<<total<<endl;
            // if(total==6){
            //     cout<<arr[x].second<<" "<<arr[y].second<<" "<<arr[z].second<<endl;
            // }
            if(total==sum && y!=z && x!=y && x!=z){
                st.insert(arr[x].second+1);
                st.insert(arr[y].second+1);
                st.insert(arr[z].second+1);
                for(auto k:st){
                    cout<<k<<" ";
                }
                return 0;
            }
            if(total<sum){
                y++;
            }else{
                z--;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}