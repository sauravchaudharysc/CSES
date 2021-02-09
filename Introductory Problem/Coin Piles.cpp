#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll a,ll b){
    if(a==0 && b==0){
        cout<<"YES"<<endl;
        return 1;
    }
    if(a==0 || b==0){
        cout<<"NO"<<endl;
        return 0;
    }    
    if((a+b)%3){
        cout<<"NO"<<endl;
        return 0;
    }else{
        if(b>a){
            return check(b,a);
        }
        if((a-b)>b){
            cout<<"NO"<<endl;
            return 0;
        }else{
            cout<<"YES"<<endl;
            return 1;
        }
    }
}


int main(){
    ll n;
    cin>>n;
    ll a ,b;
    while(n--){
        cin>>a>>b;
        bool output=check(a,b);
    }
}