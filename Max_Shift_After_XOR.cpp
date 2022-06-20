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
    set <long long> s;

    long long ans =0;
    long long i=0;

    while(i<n)
    {
        long long cnt=0;
        long long x=0;
        long long j=i;
        while(cnt<n)
        {
            x=x^vec[j];
            cnt++;
            s.insert(x);
            j=(j+1)%n;
        }
        i++;
        ans=max(ans,(long long)s.size());
        s.clear();
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