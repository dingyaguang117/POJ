#include <stdio.h>
int m,n,b[10000][2],a[100][100],tmax=1,c[10000],step[100][100]={0};
int main(){
    freopen("1.txt","r+",stdin);
    freopen("2.txt","w+",stdout);
    void jump(int x,int y,int max);
    int i,j,x,y;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      scanf("%d",a[i]+j);
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        jump(i,j,0);
        printf("%d",tmax);
        system("pause");
    }


void jump(int x,int y,int max){
     max+=1;int i; 
     if(step[x][y]!=0) max+=step[x][y];
     else{
     if(x-1>=0&&a[x-1][y]<a[x][y])  jump(x-1,y,max);
     if(x+1<m&&a[x+1][y]<a[x][y])  jump(x+1,y,max);    
     if(y-1>=0&&a[x][y-1]<a[x][y])  jump(x,y-1,max); 
     if(y+1<n&&a[x][y+1]<a[x][y])  jump(x,y+1,max); 
     step[x][y]=max;
     }
     if(max>tmax) {tmax=max;
   
     }
 
         }
