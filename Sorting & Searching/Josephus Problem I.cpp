#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    queue<ll>pq;
    for(int i=1;i<=n;i++){
        pq.push(i);
    }
    bool flag=1;
    while(!pq.empty()){
        if(flag){
            ll x=pq.front();
            pq.pop();
            pq.push(x);
            flag=!flag;
        }else{
            cout<<pq.front()<<" ";
            pq.pop();
            flag=!flag;
        }
    }
}