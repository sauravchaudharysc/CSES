#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll csum=0;
    for(ll i=1;i<=n;i++){
        csum+=i;
    }
    if(csum&1){
        cout<<"NO"<<endl;
        return 0;
    }
    
        ll i=1;   
        ll j=n;
        set<ll,greater<ll>>arr1,arr2;
        if(n&1){
            arr2.insert(j);
            arr1.insert(i);
            arr1.insert(j-1);
            i++;
            j=j-2;
        }
        int flag=1;
        while(i<j){
            if(flag){
                arr1.insert(i);
                arr1.insert(j);
                flag=0;
            }else{
                arr2.insert(i);
                arr2.insert(j);
                flag=1;
            }
            i++;
            j--;
        }
        cout<<"YES"<<endl;
        cout<<arr2.size()<<endl;
        for(auto x:arr2){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<arr1.size()<<endl;
        for(auto x:arr1){
            cout<<x<<" ";
        }
        cout<<endl;
}