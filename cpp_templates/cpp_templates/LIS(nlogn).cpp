#include<bits/stdc++.h>
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
int lis(std::vector<int>& arr){
    std::vector<int> lis;
    for(int i = 0; i < (int)arr.size(); ++i){
        std::vector<int>::iterator it = std::lower_bound(lis.begin(),lis.end(),arr[i]);
        if(it == lis.end())
            lis.push_back(arr[i]);
        else *it = arr[i];
    }
    return lis.size();
}