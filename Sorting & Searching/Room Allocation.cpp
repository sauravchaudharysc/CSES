#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void start(){
    ll n;
    cin>>n;
    vector<ll>ans(n);
    vector<pair<ll,pair<ll,ll>>>arr;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x;
        cin>>y;
        arr.push_back({y,{x,i}});
    }
    //End time ke basis par sort kiya
    sort(arr.begin(),arr.end());
    // for(auto x:arr){
    //     cout<<x.second<<" "<<x.first<<endl;
    // }
    //cout<<"I end"<<endl;
    //Set jo finish time aur room no store kare
    set<pair<ll,ll>>st;
    //Pehla input ko khud push kardia set meh and room no 1 dedia
    ans[arr[0].second.second]=1;
    st.insert({arr[0].first,1});
    ll count=1;
   for(ll i=1;i<n;i++){
       ll start=arr[i].second.first;
       ll end=arr[i].first;
       /*Yaha -1 islie kai agar soch ki pehla input jo manually maine insert kia woh
       2 ,1 h yani room no 1 ka end time 2 . 
       
       Agar iske baad input aae ki start time 2 and end time 4 tab mujhe iska 
       lower bound end milega kyuki 2,1 is smaller than 2,INT_MAX.
       
       Islie -1 karke rakhunga.*/
       auto it = st.lower_bound({start-1,INT_MAX});
       if(it==st.begin()){
           st.insert({end,++count});
           ans[arr[i].second.second]=count;
       }else{
           it--;
           ll o=it->second;
           st.erase(it);
           ans[arr[i].second.second]=o;
           st.insert({end,o});
       }
   }
   ll maxi=0;
   for(auto x:ans){
       maxi=max(maxi,x);
   }
   cout<<maxi<<endl;
   for(auto x:ans){
      cout<<x<<" ";
   }
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