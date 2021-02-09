#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<int,int> x,pair<int,int>y){
    if(x.first==y.first){
        return (x.second<y.second);
    }
    return x.first<y.first;
}
int main(){
    ll n;
    cin>>n;
    ll sum;
    cin>>sum;
    vector<pair<int,int>>arr;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        arr.push_back(make_pair(a,i+1));
    }
    sort(arr.begin(),arr.end(),compare);
    ll i=0;
    ll j=n-1;
    while(i<j){
        if(arr[i].first+arr[j].first==sum){
            if(arr[i].second>arr[j].second){
                cout<<arr[j].second<<" "<<arr[i].second<<endl;
            }else
            cout<<arr[i].second<<" "<<arr[j].second<<endl;
            return 0;
        }else if(arr[i].first+arr[j].first<sum){
            i++;
        }else{
            j--;
        }
    }
    if(i==j){
        cout<<"IMPOSSIBLE"<<endl;
    }
}

/* O(N) Approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n,sum;
    cin>>n>>sum;
    std::vector<int> v(n); 
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    std::map<int, int> hash;
    hash[v[0]]=0;
    for (int i = 1; i < n; i++){
        if(hash.find(sum-v[i])!=hash.end()){
            cout<<hash[sum-v[i]]+1<<" "<<i+1;
            return 0; 
        }
        hash[v[i]] = i;
    }
    cout<<"IMPOSSIBLE";
} */
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;
    long long int sum;
    cin>>n>>sum;
    std::vector<int> v(n),index(n); 
    for (int i = 0; i < n; i++){
        cin>>v[i];
        index[i]=i;
    }
    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
    sort(index.begin(),index.end(),[&](int a,int b)->bool{
        return v[a]<v[b];
    });
    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
    int i=0,j=n-1;
    while(i<j){
        if(v[index[i]]+v[index[j]]<sum)
            i++;
        else if(v[i]+v[j]>sum)
            j--;
        else{
            cout<<(index[i]+1)<<" "<<(index[j]+1);
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}*/