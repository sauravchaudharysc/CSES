/*Similar to Room Allocation problem but here we are given we have k peoples so we can only use these k and watch the movies.
So we first sort by end time and push the k top element in set and see whether among them can watch movies from i+k. And then update 
in the set accordingly. Set updation is not allowed so we erase and insert new.*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n,k;
    cin>>n;
    cin>>k;
    vector<pair<ll,pair<ll,ll>>>arr;
    vector<ll>ans(n);
    ll x,y;
    for(ll i=0;i<n;i++){
        cin>>x>>y;
        arr.push_back({y,{x,i}});
    }
    sort(arr.begin(),arr.end());
    set<pair<ll,ll>>st;
    ll count=1;
    st.insert({arr[0].first,count});
    auto it=st.begin();
    ans[arr[0].second.second]=count;
    ll occu=1;
    for(ll i=1;i<n;i++){
        ll start=arr[i].second.first;
        ll end=arr[i].first;
        auto it = st.lower_bound({start-1,INT_MAX});
        if(it==st.begin() && occu<k){
            st.insert({end,count});
            ans[arr[i].second.second]=count;
            occu++;
            count++;
        }else if(it==st.begin() && occu>=k && start<it->first){
            continue;
        }else{
            it--;
            ll o=it->second;
            st.erase(it);
            st.insert({end,o});
            count++;
        }
    }
   cout<<count<<endl;
}