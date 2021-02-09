#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll i,m=0,a=0;
    while(n!=0){
        cin>>i;
        a=max(a,i);
        m+=i;
        n--;
    }
    cout<<max(2*a,m);
}