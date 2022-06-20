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
    if(b%a!=0)
    cout<<"0 0";
    else if(a>b)
    cout<<"0 0";
    else if(a==b)
    {
        cout<<1<<" "<<1;
    }
    else
    {
        int x=b/a;
        
        for(int i=2;i<=x;i++)
        {
            int temp=x;
            int f=1;
            int cnt=0;
            while(x>1)
            {
                if(x%i!=0)
                {
                    f=0;
                    break;
                }
                x=x/i;
                cnt++;
                
            }
            if(f)
            {
                cout<<cnt<<" "<<i;
                return ;
            }

            x=temp;
        }
            
        }
        // prime.clear();
    

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