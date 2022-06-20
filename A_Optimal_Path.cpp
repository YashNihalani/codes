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
  long long n ,m;
  cin>>n>>m;
  long long ans =0;
  for(long long i=0;i<m;i++)
  {
    ans+=i+1;
  }
  for(long long j=2;j<=n;j++)
  {
    ans+=j*m;
  }
  cout<<ans<<endl;
}
int main()
{
    fast
    long long t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 return 0;

}