#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;
long long sum=0;
int main()
{
    int n=1;
    while(n)
    {
        cin>>n;
        if(n==0)
            break;
        vector<signed int> a;
        a.clear();
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            a.pb(k);
        }
        int i=0,j=0;
        while(i!=n||j!=n)
        {
            if(a[i]<0)
                i++;
            if(a[j]>0)
                j++;
            sum+=abs(j-i)*std::max(a[i],abs(a[j]));
            a[i]-=abs(a[i]-abs(a[j]));
            a[j]+=abs(a[i]-abs(a[j]));
        }
       cout<<sum<<endl;
    }

    return 0;
}