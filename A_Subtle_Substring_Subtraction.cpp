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
// ll n,vector <int> vec;
map <ll, ll> prime;

void solve()
{
    string s;
    cin>>s;
    if(s.size()==1)
    {
        int diff=s[0]-'a'+1;
        cout<<"Bob "<<diff<<endl;

    }
    else if(s.size()%2==1)
    {
        cout<<"Alice ";
        int sum=0;
        for(int i=0;i<s.size();i++)
            {
                sum+=s[i]-'a'+1;
                
            }

        if(s[0]>s[s.size()-1])
        {
            int a=s[0]-'a'+1;
            int b=s[s.size()-1]-'a'+1;
         cout<<sum-b-b;
        }
        else
        {
            int a=s[0]-'a'+1;
            int b=s[s.size()-1]-'a'+1;
            // cout<<sum<<endl;
           cout<<sum-a-a;
        }
        cout<<endl;
    }
    else
    {
        cout<<"Alice ";
        int sum=0;
        for(int i=0;i<s.size();i++)
            {
                sum+=s[i]-'a'+1;
                
            }
            cout<<sum<<endl;

    }
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        // vec.clear();
        solve();
    }
 return 0;

}