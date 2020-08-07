#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define sint int32_t
#define int long long int
#define all(v) v.begin() , v.end()
#define vii vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct TrieNode {
    TrieNode* child[26];
    int cnt = 0;
};

TrieNode* root;



void insert(string &s)
{
    TrieNode* cur = root;
    for(int i=0; s[i]; i++) {
        char c = s[i];
        int pos = c-'a';
        if(!cur->child[pos]) cur->child[pos] = new TrieNode();
        cur = cur->child[pos];
    }
    cout<<cur->cnt<<endl;
    cur->cnt++;
}

int query(string& s)
{
    TrieNode* cur = root;
    for(int i=0; s[i]; i++) {
        char c = s[i];
        int pos = c-'a';
        if(!cur->child[pos]) return 0;
        cur = cur->child[pos];
    }
    return cur->cnt;
}


int32_t main()
{   fastio;

    int n;
    cin>>n;

    root = new TrieNode();


    string arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        insert(arr[i]);
    }

    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<query(s)<<endl;
    }



}
