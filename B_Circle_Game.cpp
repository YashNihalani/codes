#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define makedp memset(dp,-1,sizeof(dp))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define MAX(a,b,c) max((ll)a,max((ll)b,(ll)c))
#define MIN(a,b,c) min((ll)a,min((ll)b,(ll)c)) 
#define cord4(x,y) vector<ll> x={1,0,-1,0},y={0,1,0,-1};
#define cord8(x,y) vector<ll> x={1,0,-1,0,1,1,-1,-1},y={0,1,0,-1,1,-1,-1,1};
#define mod 1000000007
map <ll, ll> prime;

void solve()
{
    int  n ;
    cin>>n;
    vector <int> vec(n);
    int even=0;
    int odd=0;
    int x=-1;
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        if(i%2==0)
        {
            even+=vec[i];
        }
        else
        {
            odd+=vec[i];
        }
        if(mini>vec[i])
        {
            mini=vec[i];
            x=i;
        }
    }
    if(n%2==0)
    {
        if(x%2==0)
        {
            cout<<"Joe";
        }
        else
        {
            cout<<"Mike";
        }
    }
    else
    {
        cout<<"Mike";
    }
    cout<<endl;
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 return 0;

}