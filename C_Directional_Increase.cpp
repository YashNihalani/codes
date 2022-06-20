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
    long long c=0;
    if(n==1 && vec[0]==0)
    {
       cout<<"Yes"<<endl;
       return ;
    }
 
    for(long long i=n-1;i>=0;i--)
    {
      
        if(i==0)
        {
            if(c!=vec[i])
            {
                cout<<"No"<<endl;
                return;
            }
            break;

        }
        if(vec[i]>c)
        {
             cout<<"No"<<endl;
            return ;
            

        }
        if(vec[i]==c)
        {
            if(vec[i]!=0)
            {
                 cout<<"No"<<endl;
            return ;

            }
        }
        else
        {
            c=c-vec[i];
        }

    }
    cout<<"Yes"<<endl;
    
 return ;
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