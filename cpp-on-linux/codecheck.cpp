#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    cin>>n;
    vector<int>a;
    a.clear();
    a.pb(0);
    int k=a.size();
    while(k!=n){
        int p=a.at(k-1);
        int count = std::count(a.begin(),a.end(),p)-1;
        if(count==0){
            a.pb(0);
        }
        else{
            vector<int>::reverse_iterator it=find(a.rbegin()+1,a.rend(),p);
            int dist= abs(std::distance(it,a.rbegin()));
            a.pb(dist);
        }
        k=a.size();
    }
    if(k==n){
        cout<< count(a.begin(),a.end(),a.at(n-1)) << endl;
    }
        }
}