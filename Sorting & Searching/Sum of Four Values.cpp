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
    for(ll i=0;i<n-3;i++){
            for(ll k=i+1;k<n-2;k++){
                ll start=k+1;
                ll end=n-1;
                while(start<end){
                    if(arr[i].first+arr[k].first+arr[start].first+arr[end].first==sum){
                         st.insert(arr[i].second+1);
                         st.insert(arr[k].second+1);
                         st.insert(arr[start].second+1);
                         st.insert(arr[end].second+1);
                        for(auto k:st){
                            cout<<k<<" ";
                        }
                        return 0;
                    }else if(arr[i].first+arr[k].first+arr[start].first+arr[end].first<sum){
                        start++;
                    }else{
                        end--;
                    }
                }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}