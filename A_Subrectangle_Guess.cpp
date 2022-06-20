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
    int n ,m;
    cin>>n>>m;
    vector <vector <int> > vec(n, vector <int> (m));
    int maxi=INT_MIN;
    int x,y;
    x=y=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
            if(maxi<vec[i][j])
            {
                x=i;
                y=j;
                maxi=vec[i][j];

            }
        }
    }
    // cout<<x<<" "<<y<<endl;
    int nn;
    int mm;
    if(x>=n/2)
    {
     nn=x+1;
    }
    else
    {
        nn=n-x;

    }
    if(y>=m/2)
    {
     mm=y+1;
    }
    else
    {
      mm=m-y;
    }
    // cout<<nn<<" "<<mm<<endl;
    cout<<nn*mm<<endl;
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