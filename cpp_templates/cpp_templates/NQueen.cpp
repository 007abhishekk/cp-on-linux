#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<pair<int, int>> solution;
int cnt = 0;
void nqueen(int row, int n)
{
   if (solution.size() == n)
   {

      // cout << "[ ";
      // for(auto v: solution){
      // 	cout << "[";
      // 	cout << v.first << " " << v.second;
      // 	if(v != solution.back())
      // 		cout << "], ";
      // 	else cout << "]";
      // }
      // cout << " ]\n";

      cnt++;
      vector<vector<char>> mat(n, vector<char>(n, 'E'));
      for (auto v : solution)
         mat[v.first][v.second] = 'Q';
      for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j)
            cout << mat[i][j] << " \n"[j == n - 1];
      cout << endl;
   }
   else
   {
      for (int col = 0; col < n; ++col)
      {
         bool ok = true;
         for (auto v : solution)
         {
            if (v.second == col or abs(v.second - col) == abs(v.first - row))
               ok = false;
         }
         if (ok)
         {
            solution.push_back(make_pair(row, col));
            nqueen(row + 1, n);
            solution.pop_back();
         }
      }
   }
}

int main()
{
   int n;
   cin >> n;
   nqueen(0, n);
   printf("Total possibilty: %d", cnt);
}