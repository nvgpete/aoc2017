#include <stdio.h>
#include <string.h>
int x[60],y[60],last=0,best=0,lng=0,lngbest=0;

void find(int n,int count,int clng) {
  int xs,ys,i,fnd=0;
  for (i=0;i<last;i++) {
    if(x[i]==n || y[i]==n) {
      fnd=1;
      xs=x[i];
      x[i]=-1;
      ys=y[i];
      y[i]=-1;
      if (n==xs) find(ys,count+xs+ys,clng+1);
      else find(xs,count+xs+ys,clng+1);
      x[i]=xs;
      y[i]=ys;
    }
  }
  if(!fnd) {
    if (count>best) best=count;
    if (clng>lng) {
      lng=clng;
      lngbest=count;
    } else if (clng==lng && count>lngbest) lngbest=count;
  }   
}
      
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  f=fopen("d24.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"%d/%d",x+last,y+last);
    last++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  find(0,0,0);
  printf("Strongest=%d\n",best);
  printf("Longest strongest=%d\n",lngbest);
}
