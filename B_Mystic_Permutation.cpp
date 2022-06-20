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
    vector <int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    if(n==1)
    {
        cout<<-1<<endl;
        return ;
    }
    else
    {
        map <int, int> mp;
        vector <int> ans ;
        for(int i=0;i<n;i++)
        {
            int key=vec[i];
            for(int j=1;j<=n;j++)
            {
                if(j!=key && mp[j]==0)
                {
                    mp[j]=1;
                    ans.push_back(j);
                    break;
                }

            }
        }
        if(ans.size()<n)
        {
            ans.push_back(vec[n-1]);
            swap(ans[n-1],ans[n-2]);
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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