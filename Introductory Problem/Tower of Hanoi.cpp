#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void tofh(int ndisk,int src,int temp,int dest){
    if(ndisk==1){
        cout<<src<<" "<<dest<<endl;
        return;
    }
    tofh(ndisk-1,src,dest,temp);
        cout<<src<<" "<<dest<<endl;
    tofh(ndisk-1,temp,src,dest);    
}


int main(){
    int n;
    cin>>n;
    ll moves=(1<<n)-1;
    cout<<moves<<endl;
    tofh(n,1,2,3);
}