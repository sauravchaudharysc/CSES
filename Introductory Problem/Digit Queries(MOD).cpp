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
        
        ll needed=input-lastrange;
        ll steps = (needed-1)/digit;
        ll digRank = (needed)%digit-1;
        if(start==1){
            cout<<input<<endl;
            continue;
        }
        while(steps--){
            start++;
        }
        string s=to_string(start);
        if(digRank>=0)
        cout<<s[digRank]<<endl;
        else
        cout<<s[digit-1]<<endl;
    }
}