#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    while(n--){
        ll start=1;
        ll digit=1;
        ll lastrange=1;
        ll Nextrange=9;
        ll input;
        cin>>input;
        while(input>Nextrange){
            start*=10;
            digit++;
            lastrange=Nextrange;
            Nextrange+=9*start*digit;
        }
        
        // cout<<lastrange<<endl;
        ll needed=input-lastrange;
        // cout<<needed<<endl;
        ll steps = (needed-1)/digit;
        // cout<<"steps"<<steps<<endl;
        // cout<<start<<endl;
        // cout<<digit<<endl;
        ll digRank = needed-steps*digit;
        // cout<<"i"<<digRank<<endl;
        if(start==1){
            cout<<input<<endl;
            continue;
        }
        while(steps--){
            start++;
        }
        string s=to_string(start);
        cout<<s[digRank-1]<<endl;  
    }
}