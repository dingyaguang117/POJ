#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace::std;

void string2vecint(string in,vector<int> &out);
void func_power(vector<int> &out,vector<int> base,int exp);
vector<int> func_multi(vector<int> a,vector<int> b);
vector<int> func_multi(vector<int> a,int b);
void func_add(vector<int> &sum,vector<int> a,int n);
void print(const vector<int> &sum,int nlog);



int main()
{
  string s;
  vector<int> vecint_A,out;
  int n,nlog=0;
  string::size_type i;
  while(cin>>s>>n)
  {
    vecint_A.clear();
    out.clear();
  //==化简原数
    if(s.find('.')==string::npos)//整数
    {
    //删除前面的0
      i=s.find_first_not_of('0');
      s.erase(0,i);
    //删除后面的0
      i=s.find_last_not_of('0');
      nlog=s.size()-i-1;
      s.erase(i+1,nlog);
      string2vecint(s,vecint_A);// 保证vecint_A是空
    }
    else
    {
    //删除后面的0
      i=s.find_last_not_of('0');
      s.erase(i+1,s.size()-i-1);
    //删除点
      i=s.find('.');
      nlog=(s.size()-i-1);
      nlog=-nlog;
      s.erase(i,1);
    //删除前面的0
      //如果只剩0 即0.0情况 s置0
      i=s.find_first_not_of('0');
      if(i==string::npos) s="0";
      //否则删除多余的0
      else
      {
        s.erase(0,i);
      }
    //s存储到vecint
      string2vecint(s,vecint_A);// 保证vecint_A是空
    }
  //==开始整数计算
    out.push_back(1);
    cout<<"s="<<s<<" nlog="<<nlog<<endl;
    print(vecint_A,nlog);
    func_power(out,vecint_A,n);
    nlog*=n;
    print(out,nlog);
  }
}

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

void func_power(vector<int> &out,vector<int> base,int exp)
{
  int i;
  for(i=0;i<exp;i++)
  {
    out=func_multi(out,base);
  
  }
}

vector<int> func_multi(vector<int> a,vector<int> b)
{
  vector<int> r,tmp;
  int i;
  for(i=0;i<b.size();i++)
  {
    tmp=func_multi(a,b[i]);
    func_add(r,tmp,i);
  }
  
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
      a[i+1]=a[i]/10000;
      a[i]=a[i]%10000;
    }
  }
  return a;
}

void func_add(vector<int> &sum,vector<int> a,int n)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
    sum[i+n]=a[i];
  }
  for(i=0;i<sum.size();i++)
  {
    if(sum[i]>=10000)
    {
      if(i==sum.size()-1) sum.push_back(0);
      sum[i+1]=sum[i]/10000;
      sum[i]=sum[i]%10000;
    }
  }
}

void print(const vector<int> &sum,int nlog)
{ vector<int>::size_type i;
  for(i=0;i<sum.size();i++)
  {
    cout<<sum[i]<<",";
  }
}


