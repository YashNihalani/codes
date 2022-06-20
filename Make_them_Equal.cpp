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
bool check(long long n)
{
    int div=2;
    n--;
    while(n>=1)
    {
        if(n<div)
        {
            // cout<<n<<endl;
            return false;
        }
        // cout<<n<<endl;
        n-=div;
        div=div*2;
        
    }
    return true;
}
void solve()
{
   vector <long long> vec(3);
   cin>>vec[0]>>vec[1]>>vec[2];

   sort(vec.begin(),vec.end());
   long long sum=0;
   for(long long i=0;i<2;i++)
   {
    sum+=vec[2]-vec[i];
   }
    
    // cout<<sum<<endl;
    if(check(sum))
    cout<<"YES";
    else
    cout<<"NO";
    cout<<endl;
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