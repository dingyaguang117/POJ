#include <stdio.h>
int m,n,b[10000][2],a[100][100],tmax=1,c[10000];
int main(){
    void jump(int x,int y,int max);
    int i,j,x,y;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      scanf("%d",a[i]+j);
      for(i=0;i<m;i++){
          printf("\n");
       for(j=0;j<n;j++)
        printf("%4d ",a[i][j]);}
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        jump(i,j,0);
        printf("\n最长路径步数：%d\n",tmax);
        printf("最长路径：",c[i]);
        for(i=0;i<tmax;i++) printf("%d ",c[i]);
        printf("\n");
    getchar();   
    system("pause");
    }


void jump(int x,int y,int max){
     max+=1;int i; 
     b[max-1][0]=x;b[max-1][1]=y;
     //printf("jump(%d,x=%d,y=%d)\n",a[x][y],x,y); 
        
     if(x-1>=0&&a[x-1][y]<a[x][y])  jump(x-1,y,max);
     if(x+1<m&&a[x+1][y]<a[x][y])  jump(x+1,y,max);    
     if(y-1>=0&&a[x][y-1]<a[x][y])  jump(x,y-1,max); 
     if(y+1<n&&a[x][y+1]<a[x][y])  jump(x,y+1,max); 
     if(max>tmax) {tmax=max;
     for(i=0;i<max;i++) c[i]=a[b[i][0]][b[i][1]];
     }
    // printf("到头!\n");
         }
