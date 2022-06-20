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
    int n ;
    cin>>n;
    
     if(n==6)
    {
        cout<<"101101";
    }
     if(n==5)
    {
        cout<<"10101";
        return ;
    }
     if(n==4)
    {
        cout<<"0110";
        return ;
    }
    if(n==3)
    {
        cout<<"101";
        return ;
    }
   
   
   
    else
    {
        n-=3;
        string ans="101";
        while(n!=3)
        {
            n--;
            ans.push_back('0');
        }
        ans+="010";
        cout<<ans<<endl;
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