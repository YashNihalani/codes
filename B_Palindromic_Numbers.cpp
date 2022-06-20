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
    string s;
    cin>>s;
    string target;
    if(s[0]=='9')
    {
         target="1";
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1)
            {
                target.push_back('1');
            }
            else
            target.push_back('8');
        }

      int c=0;
    //   cout<<target<<endl;
     vector <int>ans;
      
      int i=n-1;
      int j=target.size()-1;

      while(i>=0)
      {
        int num=s[i]-'0';
        int t;
        if(num+c<=8)
        {
            t=8;
        }
        else
        {
            t=18;
        }
        if(i==1)
        {
            // cout<<c<<" yash"<<endl;
        }
        if(i==n-1)
        {
          if(num>1)
          {
            t=11;
          }
          else{
            t=1;
          }
        }

        int x=t-(num+c);
        int f=x%10;
        int cc=target[i]-'0';
        ans.push_back(f);
        // cout<<t<<" "<<num<<" "<<c<<" "<<f<<endl;

        if(num+c>cc)
        c=1;
        else
        c=0;

        i--;
        j--;
        
      
      }
      for(int i=ans.size()-1;i>=0;i--)
      {
        cout<<ans[i];

      }
      cout<<endl;
      
    }
    else
    {
        vector <int> ans;
        for(int i=n-1;i>=0;i--)
        {
            int num=s[i]-'0';
            ans.push_back(9-num);
        }
       for(int i=ans.size()-1;i>=0;i--)
      {
        cout<<ans[i];

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