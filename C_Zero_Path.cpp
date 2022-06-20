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
int dp[1001][1001][3];
int solve(int i , int j , int sum ,  vector <vector <int> > &vec)
{
  
    if(i==vec.size()-1 && j==vec[0].size()-1)
    {
        sum+=vec[i][j];
        if(sum%3==0)
        return 1;

        return 0;
    }

    if(dp[i][j][sum]!=-1)
    return dp[i][j][sum];
    

    int op1,op2;
    op1=op2=0;
    sum= (sum+vec[i][j])%3;

   if(i+1<vec.size())
   {
      op1= solve(i+1,j,sum,vec);
   }
   if(j+1<vec[0].size())
   {
     op2=solve(i,j+1,sum,vec);
   }
   return dp[i][j][sum]= op1 | op2 ;
}
void find()
{
    int n,m;
    cin>>n>>m;
    vector <vector <int> > vec(n, vector <int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
            if(vec[i][j]==-1)
            {
                vec[i][j]=2;
            }
        }
    }
    makedp;
    if (solve(0,0,0,vec))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    cout<<"\n";
    return ;
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
       
        find();
    }
 return 0;

}