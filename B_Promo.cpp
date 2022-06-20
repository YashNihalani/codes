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
    long long n ,qq;
    cin>>n>>qq;

    vector <long long> vec(n);
    for(long long i=0;i<n;i++)
    cin>>vec[i];
   sort(vec.begin(),vec.end(),greater <long long> ());
   vector <long long> pref(n);
    for(long long i=0;i<n;i++)
    {
        if(i!=0)
       pref[i]=vec[i]+pref[i-1];
       else
       pref[i]=vec[i];
    }
   
    for(long long i=0;i<qq;i++)
    {
        long long x,y;
        cin>>x>>y;
        long long ans ;
        if(x-y!=0)
        ans =pref[x-1]-pref[x-y-1];
        else
        ans=pref[x-1];

    //    cout<<i<<endl;
    cout<<ans<<endl;
    }
    

  return;

}
int main()
{
    fast
    long long t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
 return 0;

}