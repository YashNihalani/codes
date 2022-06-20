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
     long long n ;
    cin>>n;
    vector <long long> vec(n);
    for(long long i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans =0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(2*(vec[i]^vec[j])==vec[i]+vec[j])
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    fast
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
 return 0;

}