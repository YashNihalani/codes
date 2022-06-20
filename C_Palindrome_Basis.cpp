#include <bits/stdc++.h>
using namespace std;
#define ll  long long
// #define makedp memset(dp,-1,sizeof(dp))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
// #define MAX(a,b,c) max((int )a,max((int )b,(int )c))
// #define MIN(a,b,c) min((int )a,min((int )b,(int )c)) 
// #define cord4(x,y) vector<int > x={1,0,-1,0},y={0,1,0,-1};
// #define cord8(x,y) vector<int > x={1,0,-1,0,1,1,-1,-1},y={0,1,0,-1,1,-1,-1,1};
#define mod 1000000007
ll  n;
// vector <int > vec;
map <int , int > prime;
vector <int > pal;
int  dp[40004][500];
ll rec(ll  sum, int  i)
{
    
    if(sum<0)
    return 0;
    if(sum==0)
    return 1;
    if(i>=500)
    return 0;

  if(dp[sum][i]!=-1)
  return dp[sum][i];

    if(n-pal[i]>=0)
    {
        return dp[sum][i]=(rec(sum-pal[i],i)%mod+rec(sum,i+1)%mod)%mod;

    }
    else if(n-pal[i]<0)
    return  dp[sum][i]=0;

    return dp[sum][i]= 0;
}
bool check( int  num )
{
    vector <int > dig;
    while(num>0)
    {
        int  d=num%10;
        num=num/10;
        dig.push_back(d);
    }
    int  i=0;
    int  j=dig.size()-1;
    
    while(i<j)
    {
        if(dig[i]!=dig[j])
        return false;
        i++;
        j--;
    }
   
    return true;
}
void solve()
{
    cin>>n;
    cout<<rec(n,0)<<endl;
}
int main()
{
    fast
    int  t;
    cin>>t;
   
    for(int  i=1;i<=40004;i++)
    {
       
        if(check(i))
        {
            pal.push_back(i);
          
        }
    }
    // cout<<pal.size()<<endl;
    // for(int i=0;i<198;i++)
    // {
    //     cout<<pal[i]<<" ";
    // }
    // cout<<endl;
    memset(dp,-1,sizeof(dp));
      
    while(t--)
    {
        // vec.clear();
         
     
        solve();
    }
 return 0;

}