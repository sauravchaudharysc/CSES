#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
void debrujnin(string s,vector<char>path,vector<int>&Edge){
    for(int i=0;i<2;i++){
        string ans = s+path[i];
        if(mp[ans]==0){
            mp[ans]++;
            debrujnin(ans.substr(1),path,Edge);
            Edge.push_back(i);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<char>path={'0','1'};
    string s="";
    for(int i=1;i<n;i++){
        s+='0';
    }
    vector<int>Edge;
    debrujnin(s,path,Edge);
    string str="";
    for(int i=0;i<Edge.size();i++){
        str+=Edge[i]+'0';
    }
    str+=s;
    cout<<str<<endl;
}