#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int bit[N];

int arr[N];

int sum(int x)
{
    int ans = 0;

    for(; x>0; x -= x&(-x)) {
        ans += bit[x];
    }

    return ans;
}

void update(int x , int y)
{
    for(; x<N; x += (x&(-x)))
    {
        bit[x] += y;
    }
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        memset(bit , 0 , sizeof(bit));

        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++) {
            cin>>arr[i];
            update(i , arr[i]);
        }

        int q;
        cin>>q;
        while(q--)
        {
            int l;
            int r;
            cin>>l>>r;
            cout<<sum(r) - sum(l-1)<<"\n";
        }





    }

}
