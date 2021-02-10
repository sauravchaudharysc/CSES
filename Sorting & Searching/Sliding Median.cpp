#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>arr;
set<pair<ll,ll>>bot,top;
pair<ll,ll> median={-1,-1};
void adjust(){
    //Total Element so Far
    ll size=bot.size()+top.size();
    
    if(bot.size()<((size)/2)){
        bot.insert(median);
        median=*(top.begin());
        top.erase(top.begin());
    }
    if(bot.size()>((size)/2)){
        top.insert(median);
        median=*(--bot.end());
        bot.erase((--bot.end()));
    }
}

void add(pair<ll,ll> ele){
    if(median.first==-1){
        median=ele;
        return;
    }
    if(ele.first<median.first){
        bot.insert(ele);
    }else{
        top.insert(ele);
    }
    adjust();
}

void rem(pair<ll,ll> ele){
    if(ele.first==median.first){
         median=*(top.begin());
        top.erase(top.begin());
    }
     else if(ele.first<median.first){
        bot.erase(ele);
    }else{
        top.erase(ele);
    }
    adjust();
}

int main(){
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    if(k==1){
        for(ll i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
    }
    
    for(ll i=0;i<k-1;i++){
        add({arr[i],i});
    }
        
    for(ll i=k-1;i<n;i++){
        add({arr[i],i});
        cout<<median.first<<" ";
        rem({arr[i-k+1],i-k+1});
    }
}
/*//This Code wont Pass All Test Cases
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
}*/