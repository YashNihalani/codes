#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[]={6,2,5,4,5,1,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    vector<int>left;
    stack<pair<int,int>>s;
    for(int i=0; i<size; i++)
    {
         if(s.size()==0)
         {
             left.push_back(-1); 
         }
         else if(s.size()>0 && s.top().first<arr[i] )
         {
             left.push_back(s.top().second);
             
         }
         else if(s.size()>0 && s.top().first>=arr[i])
         {
             while(s.size()>0 && s.top().first>=arr[i])
             {
                 s.pop();
             }
             if(s.size()==0)
             {
                 left.push_back(-1);
             }
             else
             {
                 left.push_back(s.top().second);
             }
         }
         s.push({arr[i],i});
    }
    
    
    vector <int> right;
    stack<pair<int,int>>S;
    
    for(int i=size-1; i>=0; i--)
    {
         if(S.size()==0)
         {
             right.push_back(7); 
         }
         else if(S.size()>0&&S.top().first<arr[i])
         {
             right.push_back(S.top().second);
             
         }
         else if(S.size()>0 && S.top().first>=arr[i])
         {
             while(S.size()>0 && S.top().first>=arr[i])
             {
                 S.pop();
             }
             if(S.size()==0)
             {
                 right.push_back(7);
             }
             else
             {
                 right.push_back(S.top().second);
             }
         }
         S.push({arr[i],i});
    }
    
    reverse(right.begin(),right.end());

    for(auto x : left)
    cout << x << " ";
    cout<<endl;
    for(auto x : right)
    cout << x << " ";
    cout<<endl;
    
    vector <int> width(size);
    
    for(int i=0; i<size; i++)
    {
        width[i]=right[i]-left[i]-1;
    }
    
    for(auto x : width)
    cout<< x <<" ";
    cout<<endl;
    
    int area=INT_MIN;
    
    for(int i=0; i<size; i++)
    {
        area=max(area,arr[i]*width[i]);
    }
   cout<<area<<endl;
    
    
   
    
    

    return 0;
}