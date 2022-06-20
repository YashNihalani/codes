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
    int a,b;
    cin>>a>>b; 
    // a 0 b 1 
    string s ;
    if(a>b)
    {
        int f=1;
       while(a >0 && b>0)
       {
        if(f)
        {
            s.push_back('0');
            f=0;
            a--;
        }
        else
        {
             s.push_back('1');
            f=1;
            b--;
        }

       }
      
    }
    else
    {
       int f=0;
       while(a >0 && b>0)
       {
        if(f)
        {
            s.push_back('0');
            f=0;
            a--;
        }
        else
        {
             s.push_back('1');
            f=1;
            b--;
        }

       }
    }
    while(a>0)
    {
       s.push_back('0');
       a--;
    }
    while(b>0)
    {
       s.push_back('1');
       b--;
    }

    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
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