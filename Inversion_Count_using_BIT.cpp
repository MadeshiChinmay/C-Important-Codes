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

void update(int x)
{
    for(; x<N; x += (x&(-x)))
    {
        bit[x]++;
    }
}

int main()
{

    int t;
    //cin>>t;
    t = 1;
    while(t--)
    {
        memset(bit , 0 , sizeof(bit));

        int ans = 0;

        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++) {
            cin>>arr[i];
        }

        for(int i = 1; i <= n; i++) {
            ans += sum(N - 5) - sum(arr[i]);
            update(arr[i]);
        }

        cout<<ans<<"\n";






    }

}
