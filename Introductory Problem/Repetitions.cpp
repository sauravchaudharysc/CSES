#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void getOutput(string s){
    ll maxCount=1;
    for(ll i=0;i<s.length();){
        ll j=i+1;
        int count=1;
        for(;j<s.length();j++){
             if(s[i]!=s[j]){
                 break;
             }
            count++; 
        }
        if(maxCount<count){
            maxCount=count;
        }
        i=j;
    }
    cout<<maxCount<<endl;

}


int main(){
    string s;
    cin>>s;
    getOutput(s);    
}