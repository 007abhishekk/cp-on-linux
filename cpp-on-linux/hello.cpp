#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n;
            cin>>n;
            vector<int> a;
            a.clear();
            a.pb(0);
			a.pb(0);
			a.pb(1);
			a.pb(0);
            int k=a.size();
			if(k>=n){
			cout<<count(a.begin(),a.end(),a.at(n-1))<<endl;
            break;
			}
			while(k!=n) {
                int c = a.at(k - 1);
                int count = std::count(a.begin(), a.end() - 2, c);
                if (count == 0) {
                    a.pb(0);
                } else {
                    reverse(a.begin(), a.end() - 2);
					vector<int>::iterator it1;
					for(auto it1=a.begin();it1!=a.end()-2;++it1) cout<<*it1<<' ';
                    vector<int>::iterator it = find(a.begin(), a.end() - 2, c);
                    reverse(a.begin(), a.end() - 2);
                    int dist = std::distance(it, a.end() - 2);
                    a.pb(dist);
                }
				k=a.size();
            }
            if(k==n){
                cout<<count(a.begin(),a.end(),a.at(k-1))<<endl;
            }
			for(int i=0;i<n;i++) cout<<a[i]<<' ';
        }

    return 0;
}