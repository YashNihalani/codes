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
    ll n ;
    cin>>n;
    vector <ll> vec(n);
    ll odd=0;
    ll even=0;
    for(ll i=0;i<n;i++)
    {
        cin>>vec[i];
        if(vec[i]%2)
        {
        odd+=vec[i];
        }
        else
        even+=vec[i];
    }
    ll first=odd-(odd%(n/2)),second=even+(n/2-even%(n/2));
    if(even%(n/2)==0)
    second-=n/2;
    if(first-odd==second-even)
    {
        if((first/(n/2))%2==1&&(second/(n/2))%2==0&&first%(n/2)==0&&second%(n/2)==0)
        {
            cout<<"YES\n";
            return;
        }
        first-=n/2;  second+=n/2;
        if((first/(n/2))%2==1&&(second/(n/2))%2==0&&first%(n/2)==0&&second%(n/2)==0)
        {
            cout<<"YES\n";
            return;
        }
    }
    first=odd+((n/2)-odd%(n/2));
    second=even-(even%(n/2));
    if(odd%(n/2)==0)
    first-=n/2;
    if(first-odd==second-even)
    {
        if((first/(n/2))%2==1&&(second/(n/2))%2==0&&first%(n/2)==0&&second%(n/2)==0)
        {
            cout<<"YES\n";
            return;
        }
        first+=n/2;  second-=n/2;
        if((first/(n/2))%2==1&&(second/(n/2))%2==0&&first%(n/2)==0&&second%(n/2)==0)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 return 0;

}