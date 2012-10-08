#include <stdio.h>

int main()
{
  float a,b;
  int n,i;
  scanf("%f",&a);
  while(a>0.001)
  {
    b=0;
    for(i=1;;i++)
    {
      b+=1/(float)(i+1);
      if(b>a){printf("%d card(s)\n",i);break;}
    }
  
  
  
    scanf("%f",&a);
  }
}
