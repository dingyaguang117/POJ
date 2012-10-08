#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace::std;
int main()
{
  //freopen("1.txt","r+",stdin);
//  freopen("2.txt","w+",stdout);
  int i=0,j,k;
  string s0,s;
  map<string,int> chongfu;
  map<string,int>::iterator map_it;
  vector<string> index;
  vector<string>::iterator index_it;
  cin>>i;
  while(i--!=0)
  {
    s0.clear();
    s.clear();
    cin>>s0;
    for(j=0;j<s0.size();j++)
    { 
      if(s0[j]=='-') continue;
      else if(s0[j]<='9'&&s0[j]>='0')
      { 
        s+=s0[j];
        continue;
      }
      else if(s0[j]<'Q'&&s0[j]>='A')
      {
        s+='2'+(s0[j]-'A')/3;
      }
      else if(s0[j]<'Z'&&s0[j]>'Q')
      { 
        s+='7'+(s0[j]-'Q')/3;
      }
    }
 //   cout<<"s="<<s<<endl;
    //∑÷Œˆ
    index.push_back(s);
  }
  sort(index.begin(),index.end());
  index_it=index.begin();
  k=1;
  while(index_it!=index.end())
  {
    if(index_it+k!=index.end()&&*index_it==*(index_it+k))
    {
     k++;
    
    }
    else 
    {
      
      if(k>1)
      {
        chongfu[*index_it]=k;
      }
      index_it+=k;
      k=1;
      
    }
  }
  // ‰≥ˆ÷ÿ∏¥
  if(chongfu.size()==0) cout<<"No duplicates."<<endl;
  else
  {
  map_it=chongfu.begin();
  while(map_it!=chongfu.end())
  {
    s=map_it->first;
    s.insert(3,1,'-');
    cout<<s<<" "<<map_it->second<<endl;
    map_it++;
  }
  }
    cin>>k;
}
