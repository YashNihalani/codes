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
    string s,t;
    cin>>s>>t;
 map <char, int> mp;
//  map <char , int> mp2;
 
 for(auto it:t)
 {
     mp[it]++;
 }
 if(t.size()==1)
 {
     int f=0;
     for(auto it:t)
     {
         if(it=='a')
         {f=1; break;}
     }
     if(f)
     {
         cout<<1<<endl;
         return;
     }
     else
     {
         ll ans =powl(2,s.size());
         cout<<ans<<endl;
         return;
     }
 }
 if(mp.size()>=1)
 {
     int f=0;
     for(auto it:mp)
     {
         if(it.first=='a')
        { 
         f=1;
         break;
         }
     }
     if(f)
     {
         cout<<-1<<endl;
     }
     else
     {
       ll ans =powl(2,s.size());
       cout<<ans<<endl;
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
    }
 return 0;

}