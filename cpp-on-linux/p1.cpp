#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;
int main()
{
    int n=1;
    while(n)
    {
        cin>>n;
		int sum=0;
        if(n==0)
            exit(0);
        vector<int> a;
        a.clear();
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            a.pb(k);
        }
         int i=0,j=0;
        while(i!=n-1&&j!=n-1)
        {
            while(a.at(i)<=0&&i<n)
                {i++;cout<<i<<endl;}
            while(a.at(j)>=0&&j<n)
                {j++;cout<<j<<endl;}
                cout<<sum<<endl;
                cout<<max(a.at(i),abs(a.at(j)))<<endl;
            sum+=abs(j-i)*max(a.at(i),abs(a.at(j)));
            cout<<sum<<endl;
            int k=a[i];
            a[i]+=a[j];
            if(a[i]<0)
            a[i]=0;
            cout<<"a[i]="<<a[i]<<endl;
            a[j]+=k;
            if(a[j]>0)
            a[j]=0;
            cout<<"a[j]="<<a[j]<<endl;
        }
       cout<<sum<<endl;
    }

    return 0;
}