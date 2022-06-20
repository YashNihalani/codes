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
ll n;
vector <int> vec;
map <ll, ll> prime;

void solve()
{
    string s;
    cin>>s;
    map <char , int> mp;

    for(auto it:s)
    {
        mp[it]++;
    }
    if(mp.size()==1)
    {
        cout<<"YES";
    }
    else{
        int f=1;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                f=0;
                break;

            }
        }
        if(f)
        {
            cout<<"YES";
        }
        else
        {
            if(s.size()==3)
            {
                if(s[0]==s[s.size()-1])
                {
                    cout<<"YES";
                }
                else
                {
                    cout<<"NO";
                }
            }
            else
            {
                cout<<"NO";
            }
        }
    }

    
    cout<<endl;
    return ;

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