//A simple modification in sliding median will help us here
//We need to bring all the element near to median in each windows for small cost
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>arr;
set<pair<ll,ll>>bot,top;
pair<ll,ll> median={-1,-1};

ll sumbot=0;
ll sumtop=0;

void adjust(){
    //Total Element so Far
    ll size=bot.size()+top.size();
    
    if(bot.size()<((size)/2)){
        sumbot+=median.first;
        bot.insert(median);
        median=*(top.begin());
        sumtop-=median.first;
        top.erase(top.begin());
    }
    if(bot.size()>((size)/2)){
        top.insert(median);
        sumtop+=median.first;
        median=*(--bot.end());
        sumbot-=median.first;
        bot.erase((--bot.end()));
    }
}

void add(pair<ll,ll> ele){
    if(median.first==-1){
        median=ele;
        return;
    }
    if(ele.first<median.first){
        sumbot+=ele.first;
        bot.insert(ele);
    }else{
        sumtop+=ele.first;
        top.insert(ele);
    }
    adjust();
}

void rem(pair<ll,ll> ele){
    if(ele==median){
         median=*(top.begin());
         sumtop-=median.first;
        top.erase(top.begin());
    }
     else if(ele.first<=median.first){
        sumbot-=ele.first;
        bot.erase(ele);
    }else{
        sumtop-=ele.first;
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
            cout<<"0"<<" ";
        }
        return 0;
    }
    
    for(ll i=0;i<k-1;i++){
        add({arr[i],i});
    }
        
    for(ll i=k-1;i<n;i++){
        add({arr[i],i});
        cout<<(sumtop-median.first*top.size())+(median.first*bot.size()-sumbot)<<" ";
        rem({arr[i-k+1],i-k+1});
    }
}