#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,pair<int,int>>mp;
void bfs(vector<vector<int>>adj,int n,int m,pair<int,int>start,pair<int,int>end){
    queue<pair<int,int>>q;
    mp[start]={-1,-1};
    q.push(start);
    bool flag=0;
    while(!q.empty()){
        pair<int,int>front=q.front();
        q.pop();
        int x=front.first;
        int y=front.second;
        if(x<0 || x>=n || y<0 || y>=m){
            continue;
        }
         if(x==end.first && y==end.second){
            flag=1;
            break;
        }
        if( x>0 && adj[x-1][y]==0){
            mp[{x-1,y}]={x,y};
            adj[x-1][y]=1;
            q.push({x-1,y});
        }
        if(x<n-1 && adj[x+1][y]==0 ){
            mp[{x+1,y}]={x,y};
            adj[x+1][y]=1;
            q.push({x+1,y});
        }
        if(y>0 && adj[x][y-1]==0){
            mp[{x,y-1}]={x,y};
            adj[x][y-1]=1;
            q.push({x,y-1});
        }
        if(y<m-1 && adj[x][y+1]==0){
            mp[{x,y+1}]={x,y};
            adj[x][y+1]=1;
            q.push({x,y+1});
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
        return ;
    }
    pair<int,int>final={-1,-1};
    
    vector<pair<int,int>>path;
    while(end!=final){
        path.push_back(end);
        end=mp[end];
    }
    reverse(path.begin(),path.end());
    string s="";
    for(int i=0;i<path.size()-1;i++){
        int x,y;
        x=path[i+1].first-path[i].first;
        y=path[i+1].second-path[i].second;
        if(x==0 && y==-1){
            s+='L';
        }else if(x==0 && y==1){
            s+='R';
        }else if(x==1 && y==0){
            s+='D';
        }else{
            s+='U';
        }
    }
    cout<<s.length()<<endl;
    cout<<s<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int> (m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                adj[i][j]=-1;
            }else if(c=='A'){
                adj[i][j]=2;
            }else if(c=='B'){
                adj[i][j]=3;
            }
            else{    
                adj[i][j]=0;
            }
        }
    }
    pair<int,int>start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==2){
                start={i,j};
            }
            if(adj[i][j]==3){
                end={i,j};
            }
        }
    }
    adj[end.first][end.second]=0;
    bfs(adj,n,m,start,end);
}