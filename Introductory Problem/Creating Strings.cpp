#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
int totalWays(string s){
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int repeatedChar=1;
    for(auto i=mp.begin();i!=mp.end();i++){
        repeatedChar*=fact(i->second);
    }
    int totalChar=fact(s.size());
    return totalChar/repeatedChar;
}

int main(){
    string s;
    cin>>s;
    cout<<totalWays(s)<<endl;
    int n=totalWays(s);
    sort(s.begin(),s.end());
    cout<<s<<endl;
    for(int i=1;i<n;i++){
        int p=0;
        int q=0;
        int len=s.size()-1;
        for(int i=len-1;i>=0;i--){
            if(s[i]<s[i+1]){
                p=i;
                break;
            }    
        }
        for(int i=len;i>=0;i--){
            if(s[i]>s[p]){
                q=i;
                break;
            }
        }
        if(p==0 && q==0){
            reverse(s.begin(),s.end());
            cout<<s<<endl;
            continue;
        }
        swap(s[p],s[q]);
        reverse(s.begin()+p+1,s.end());
        cout<<s<<endl;
    }
}