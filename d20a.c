#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct part {
  int x,y,z,vx,vy,vz,ax,ay,az;
  };
void move(struct part *p) {
  p->vx+=p->ax;
  p->vy+=p->ay;
  p->vz+=p->az;
  p->x+=p->vx;
  p->y+=p->vy;
  p->z+=p->vz;
}  
int dist( struct part *p) {
  return abs(p->x)+abs(p->y)+abs(p->z);
}  
    
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  struct part pts[1000],*p;
  int i,j,best,k,d;
  p=pts;
  f=fopen("d20.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d>",&p->x,&p->y,&p->z,&p->vx,&p->vy,&p->vz,&p->ax,&p->ay,&p->az);
    p++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for (j=0;j<1000;j++) {
    best=999999999;
    for (i=0;i<1000;i++) {
      move(pts+i);
      d=dist(pts+i);
      if (d<best) {
        best=d;
        k=i;
      }     
    }
    printf("%d ",k);
  }     
}
