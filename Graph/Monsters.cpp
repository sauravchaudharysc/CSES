#include<bits/stdc++.h>
using namespace std;
void findPath(vector<vector<int>>adj,vector<vector<int>>&dist,int x,int y,int n,int m){
    queue<pair<string,pair<int,pair<int,int>>>>q;
    int distance=0;
    q.push({"",{0,{x,y}}});
    bool flag=0;
    string s="";
    while(!q.empty()){
        pair<string,pair<int,pair<int,int>>> top = q.front();
        s=top.first;
        distance = top.second.first;
        x = top.second.second.first;
        y = top.second.second.second;
        if(x==0 || y==0 || x==n-1 || y==m-1){
            flag=1;
            cout<<"YES"<<endl;
            cout<<distance<<endl;
            cout<<s<<endl;
            break;
        }
       
        if(x-1>=0  && adj[x-1][y]!=-1 && dist[x-1][y]>distance+1){
             string t="";
             t=s+"U";
             q.push({t,{distance+1,{x-1,y}}});
         }
         if(y-1>=0 && adj[x][y-1]!=-1 && dist[x][y-1]>distance+1){
             string t="";
             t=s+"L";
             q.push({t,{distance+1,{x,y-1}}});
         }
         if(x+1<n && adj[x+1][y]!=-1 && dist[x+1][y]>distance+1){
             string t="";
             t=s+"D";
             q.push({t,{distance+1,{x+1,y}}});
         }
         if(y+1<m && adj[x][y+1]!=-1 && dist[x][y+1]>distance+1){
             string t="";
             t=s+"R";
             q.push({t,{distance+1,{x,y+1}}});
         }
        q.pop();
    }
    if(!flag)
    cout<<"NO"<<endl;
}


/*
// The function to construct the distance matrix using the monsters.
// Leads to tle if monster count is high . 
void bfs(vector<vector<int>>adj,vector<vector<int>>&dist,int x,int y,int n,int m){
    queue<pair<int,pair<int,int>>>q;
    int distance=0;
    q.push({0,{x,y}});
    while(!q.empty()){
        pair<int,pair<int,int>> top = q.front();
        distance = top.first;
        x = top.second.first;
        y = top.second.second;
        if(adj[x][y]!=-1 && dist[x][y]>distance){
            dist[x][y]=distance;
         if(x-1>=0){
             q.push({distance+1,{x-1,y}});
         }
         if(y-1>=0){
             q.push({distance+1,{x,y-1}});
         }
         if(x+1<n){
             q.push({distance+1,{x+1,y}});
         }
         if(y+1<m){
             q.push({distance+1,{x,y+1}});
         }
        }
        q.pop();
    }
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    stack<pair<int,int>>st;
    pair<int,int> person;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                adj[i][j]=-1;
            }else{
                if(c=='M'){
                    st.push({i,j});
                }
                if(c=='A'){
                    person={i,j};
                }
                adj[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=adj[i][j];
        }
    }
    queue<pair<int,pair<int,int>>>q;
    int distance=0;
    while(!st.empty()){
        pair<int,int> monster = st.top();
        st.pop();
        q.push({0,{monster.first,monster.second}});
    }
    int x,y;
    while(!q.empty()){
        pair<int,pair<int,int>> top = q.front();
        distance = top.first;
        x = top.second.first;
        y = top.second.second;
        if(dist[x][y]>distance){
            dist[x][y]=distance;
         if(x-1>=0 && adj[x-1][y]!=-1){
             q.push({distance+1,{x-1,y}});
         }
         if(y-1>=0 && adj[x][y-1]!=-1){
             q.push({distance+1,{x,y-1}});
         }
         if(x+1<n && adj[x+1][y]!=-1){
             q.push({distance+1,{x+1,y}});
         }
         if(y+1<m && adj[x][y+1]!=-1){
             q.push({distance+1,{x,y+1}});
         }
        }
        q.pop();
    }
    findPath(adj,dist,person.first,person.second,n,m);
}