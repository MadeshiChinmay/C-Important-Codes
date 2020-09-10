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

// DSU IMPLEMENTATION

int parent[101];
int size[101];

void make_set()
{
    for(int i=1; i <= 100; i++) parent[i] = i , size[i] = 1;
}

int find_set(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = find_set(parent[a]);
}

void union_set(int a , int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(size[a]<size[b]) swap(a , b);

        parent[b] = a;
        size[a] += size[b];

    }
}




int32_t main()
{   fastio;

    make_set();

    int n;
    cin>>n;

    int edges;
    cin>>edges;

    // APPLICATION USING CYCLE DETECTION

    while(edges--)
    {
        int a , b;
        cin>>a>>b;
        if(find_set(a) == find_set(b)) {
            cout<<"CYCLE\n";
            return 0;
        }
        union_set(a , b);
    }

    // SIZE OF LARGEST CONNECTED COMPONENT

    cout<<*max_element(size+1 , size+n)<<"\n";


}
