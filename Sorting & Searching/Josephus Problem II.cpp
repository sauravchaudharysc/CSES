#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll count;
    cin>>count;
    queue<ll>pq;
    for(int i=1;i<=n;i++){
        pq.push(i);
    }
    ll i=0;
    while(!pq.empty()){
        if(i < count){
            ll x=pq.front();
            pq.pop();
            pq.push(x);
            i++;
        }else{
            cout<<pq.front()<<" ";
            pq.pop();
            i=0;
        }
    }
}