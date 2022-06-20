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
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int a =0;
    int b=0;
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a')
        a++;
        if(s[i]=='b')
        b++;
        else
        c++;
    }
     for(int i=0;i<s.size();i++)
    {
        if(t[i]=='a')
        a--;
        if(t[i]=='b')
        b--;
        else
        c--;
    }
    if(s==t)
    {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==0 && c==0)
    {
     

    }
    else
    {
        cout<<"NO"<<endl;
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