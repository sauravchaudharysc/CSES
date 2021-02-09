#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n;
    cin>>n;
    set<ll>s;
    multiset<ll>d;
    s.insert(0);
    s.insert(n);
    d.insert(n);
    ll k;
    cin>>k;
    while(k--){
        ll place;
        cin>>place;
        //The max position where we can find traffic lights
        auto it = s.upper_bound(place);
        auto itNext=it;
        auto itPrev=--it;
        d.erase(d.find(*itNext-*itPrev));
        s.insert(place);
        d.insert(*itNext-place);
        d.insert(place-*itPrev);
        it=d.end();
        it--;
        cout<<*it<<" ";
    }
}