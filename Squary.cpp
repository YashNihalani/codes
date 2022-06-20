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
ll n,vector <int> vec;
map <ll, ll> prime;

void solve()
{
    int n;
    cin>>n;
    vector <int> vec(n);
    int sum1=0;
    for(int i=0;i<n;i++)
    {
        sum1+=vec[i];
    }

    int sum2=0;
    for(int i=0;i<n;i++)
    {
        sum2+=vec[i]*vec[i];
    }
    if(sum1*sum1==sum2)
    {
        cout<<0;
    }
    else if(sum1==0)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        int diff=sum1-sum2;
        if(diff>0)
        {
            

        }
        else
        {

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
        vec.clear();
        solve();
    }
 return 0;

}