#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    priority_queue<ll>pq1,pq2;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        pq1.push(x);
    }
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        pq2.push(x);
    }
    // for(ll i=0;i<n;i++){
    //     cout<<pq1.top()<<" "<<pq2.top()<< endl;
    //     pq1.pop();
    //     pq2.pop();
    // } 
    
    ll count=0;
    while(!pq1.empty() && !pq2.empty()){
        if(pq1.top()==pq2.top() || (pq1.top()-k<=pq2.top() && pq1.top()+k>=pq2.top()) ){
            count++;
            pq1.pop();
            pq2.pop();
        }else if(pq1.top()>pq2.top()){
            pq1.pop();
        }else{
            pq2.pop();
        }
    }
    
    cout<<count<<endl;    
}