#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#ifndef HUGENUM
#define HUGENUM 
using namespace::std;

void string2vecint(string in,vector<int> &out);
vector<int> string2vecint(string in);

void func_power(vector<int> &out,vector<int> base,int exp);
vector<int> func_power(vector<int> base,int exp);

vector<int> func_multi(vector<int> a,vector<int> b);
vector<int> func_multi(vector<int> a,int b);

vector<int> func_add(vector<int> sum,vector<int> a,int n=0);
void func_added(vector<int> &sum,vector<int> a,int n=0);

void print(const vector<int> &sum,int nlog);

void mitoa(int a,char *s,int c);

void string2vecint(string in,vector<int> &out)
{
  string::size_type i;
  int int_A;
  string stmp;
  while((i=in.size())!=0)
  {
    if(i>=4)
    {
      stmp=in.substr(i-4);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(i-4,4);
    }
    else
    {
      stmp=in.substr(0);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(0,in.size());
    }
    
  }
}

vector<int> string2vecint(string in)
{
  string::size_type i;
  vector<int> out;
  int int_A;
  string stmp;
  while((i=in.size())!=0)
  {
    if(i>=4)
    {
      stmp=in.substr(i-4);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(i-4,4);
    }
    else
    {
      stmp=in.substr(0);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(0,in.size());
    }
    
  }
  return out;
}

void func_power(vector<int> &out,vector<int> base,int exp)
{
  int i;
  for(i=0;i<exp;i++)
  {
    out=func_multi(out,base);
  
  }
}
vector<int> func_power(vector<int> base,int exp)
{
  int i;
  vector<int> out;
  for(i=0;i<exp;i++)
  {
    out=func_multi(out,base);
  
  }
  return out;
}

vector<int> func_multi(vector<int> a,vector<int> b)
{
  vector<int> r,tmp;
  vector<int>::size_type i;
  for(i=0;i<b.size();i++)
  {
    tmp=func_multi(a,b[i]);
    func_add(r,tmp,i);
    
  }
  return r;
}

vector<int> func_multi(vector<int> a,int b)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    a[i]*=b;
  }
  for(i=0;i<a.size();i++)
  {
    if(a[i]>=10000)
    {
      if(i==a.size()-1) a.push_back(0);
      a[i+1]+=a[i]/10000;
      a[i]=a[i]%10000;
    }
  }
  return a;
}

void func_added(vector<int> &sum,vector<int> a,int n=0)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
    sum[i+n]+=a[i];
  }
 // cout<<"输出add函数中sum:"<<endl; 
 // print(sum,4);
  
  for(i=0;i<sum.size();i++)
  {
    if(sum[i]>=10000)
    {
      if(i==sum.size()-1) sum.push_back(0);
      sum[i+1]+=sum[i]/10000;
      sum[i]=sum[i]%10000;
    }
  }

}

vector<int> func_add(vector<int> sum,vector<int> a,int n=0)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
    sum[i+n]+=a[i];
  }
 // cout<<"输出add函数中sum:"<<endl; 
 // print(sum,4);
  
  for(i=0;i<sum.size();i++)
  {
    if(sum[i]>=10000)
    {
      if(i==sum.size()-1) sum.push_back(0);
      sum[i+1]+=sum[i]/10000;
      sum[i]=sum[i]%10000;
    }
  }
  return sum;
}

void print(const vector<int> &sum,int nlog)
{ 
  vector<int>::size_type i;
  string s;
  int tmp;
  char ss[10]={0};
  //取头 
  mitoa(sum[sum.size()-1],ss,10);
  s+=ss;
  if(sum.size()>1){
  //取中间 
  for(i=sum.size()-2;i>0;i--)
  {
    if(sum[i]<10)
    {
      s+="000";
    }
    else if(sum[i]<100)
    {
      s+="00";
    }
    else if(sum[i]<1000)
    {
      s+="0";
    }
    mitoa(sum[i],ss,10); 
    s+=ss;
  }
  //取尾 
  if(sum[0]<10)
    {
      s+="000";
    }
    else if(sum[0]<100)
    {
      s+="00";
    }
    else if(sum[0]<1000)
    {
      s+="0";
    }
    mitoa(sum[0],ss,10); 
    s+=ss;            }
    
    
  //处理小数点
  tmp=s.size();
  if(nlog==0)
  {
    
  }
  else if(nlog>0)
  {
    s.append(nlog,'0');     
  }
  else if(nlog>-tmp)
  {
    s.insert(tmp+nlog,1,'.');
    i=s.find_last_not_of('0');
    s.erase(i+1,s.size()-i-1);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
  }
  else
  {
    s.insert(0,-(tmp+nlog),'0');
    s.insert(0,"0.");
    i=s.find_last_not_of('0');
    s.erase(i+1,s.size()-i-1);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
  }
  //删除前面的0
  i=s.find_first_not_of('0');
  s.erase(0,i); 
  cout<<""<<s<<endl;
//  cin>>s; 
} 


#endif
