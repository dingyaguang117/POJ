#include <stdio.h>

int main()
{
  freopen("1.txt","r+",stdin);
  freopen("2.txt","w+",stdout);
  float a=0,b;
  int i;
  for(i=0;i<12;i++)
  {
    scanf("%f",&b);
    a+=b;
  }
  a/=12;
  a+=0.005;
  printf("$%.2f",a);

}
