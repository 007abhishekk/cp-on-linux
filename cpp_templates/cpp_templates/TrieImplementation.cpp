#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

struct Trie
{
   bool leaf;
   Trie *child[26];
};

Trie *create()
{
   Trie *temp = new Trie();
   temp->leaf = false;
   for (int i = 0; i < 26; i++)
      temp->child[i] = NULL;
   return temp;
}

void insert(Trie *root, string s)
{
   for (int i = 0; i < int(s.size()); i++)
   {
      if (root->child[s[i] - 'a'] == NULL)
      {
         root->child[s[i] - 'a'] = create();
      }
      root = root->child[s[i] - 'a'];
   }
   root->leaf = true;
}

void remove(Trie *root, string s)
{
}

bool check(Trie *root, string s)
{
   for (int i = 0; i < int(s.size()); ++i)
   {
      if (root->child[s[i] - 'a'] == NULL)
         return false;
      root = root->child[s[i] - 'a'];
   }
   return true;
}

Trie *root;

int main()
{
   root = NULL;
   root = create();
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i)
   {
      string s;
      cin >> s;
      insert(root, s);
   }
}