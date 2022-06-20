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
    int n,x;
    cin>>n>>x;
    vector <int> vec(n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        maxi=max(maxi,vec[i]);
    }

    int ans2=0;
    for(int i=0;i<n;i++)
    {
        int t=ceil(vec[i]*1.0/x);
        ans2+=t;
    }
    cout<<min(maxi,ans2)<<endl;
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