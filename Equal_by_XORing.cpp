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
unsigned int Log2n(unsigned int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}

void solve()
{
    int a,b,n;
    cin>>a>>b>>n;

  int x=a^b;
  if(a==b)
  {
    cout<<0;
    return ;
  }
  if(x<n)
  {
   cout<<1;
  }
  else
  {
    for(int i=0;i<100;i++)
    {

    }
    if(Log2n(x)==Log2n(n))
    {
        if(n & (n-1))
        {
            cout<<2;
        }
        else
        {
            cout<<-1;
        }
         for(int i=0;i<100;i++)
    {
        
    }

    }
    else
    {
        cout<<-1;
         for(int i=0;i<100;i++)
    {
        
    }
    }

  }
 
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
 return 0;

}