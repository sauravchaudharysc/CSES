#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll count(ll n){
    return n*n*(n*n-1)-8-24-((n-4)*16)-16-((n-4)*24)-(((n-4)*(n-4))*8);
}


int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cout<<count(i)/2<<endl;
    }
}