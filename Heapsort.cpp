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
// HEAPSORT

vector<int>v(10);
void heapify(int i , int n)
{
    int l = 2*i+1;
    int r = 2*i+2;

    int big = i;
    if(l<n && v[l]>v[i]) big = l;
    if(r<n && v[r]>v[big]) big = r;

    if(big != i)
    {
        swap(v[big] , v[i]);
        heapify(big , n);
    }
}


int32_t main()
{   fastio;

    v = {3 , 2 , 1 , 4 , 5 , 6 , 9 , 10 , 7 , 8};

    for(int i=9; i >= 0; i--) {
        heapify(i , 10);
    }

    for(auto x:v) cout<<x<<" ";
    cout<<"\n";

    for(int i = 9; i >= 0; i--)
    {
        swap(v[i] , v[0]);
        heapify(0 , i);
    }

    for(auto x:v) cout<<x<<" ";
    cout<<"\n";

}

