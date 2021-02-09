#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pair pair<ll,ll>

void start(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll move;
    if(k&1){
        move=k/2;
    }else{
        move=(k/2)-1;
    }
//    cout<<n<<" "<<k<<" "<<move<<endl;
    vector<ll> arr;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    set<pair>st;
    ll right=0;
    ll left=0;
    for(ll i=0;i<n;i++){
//        cout<<arr[i]<<" "<<i<<endl;
        st.insert({arr[i],i});
        if(right>=k){
            auto it = st.find(pair(arr[left],left));
//            cout<<"to erase "<<it->first<<endl;
            st.erase(it);
            left++;
        }
//        cout<<right<<" "<<k<<endl;
        right++;
        if(right>=k){
//            cout<<"I enter"<<endl;
            auto it=st.begin();
            for(ll u=0;u<move;u++){
                it++;
            }
            cout<<it->first<<" ";
        }
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