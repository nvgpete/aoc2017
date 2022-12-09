#include <stdio.h>
#include <string.h>
int get(char *s,int k) {
  int i,n=0;
  for (i=0;i<k*k;i++) {
    if (*s=='/') s++;
    n=n*2+(*s=='#');
    s++;
  }
  return n;
}
int rot2(int x) {
  int i,n=0,xl[4]={1,3,0,2};
  for (i=0;i<4;i++) n+=((x>>i)&1)<<xl[i];
  return n;
}
int rot3(int x) {       
  int i,n=0,xl[9]={2,5,8,1,4,7,0,3,6};
  for (i=0;i<9;i++) n+=((x>>i)&1)<<xl[i];
  return n;
}
int fl3(int x) {       
  int i,n=0,xl[9]={2,1,0,5,4,3,8,7,6};
  for (i=0;i<9;i++) n+=((x>>i)&1)<<xl[i];
  return n;
}

char xy[2187][2187]={".#.","..#","###"},xy2[2187][2187];

int main(int argc,char **argv) {
  FILE *f;
  int xlat23[16],xlat34[512];
  char s[100],*s2;
  int a,b,sz=3,i,j,k,ni,nj,np;
  f=fopen("d21.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    if(s[2]=='/') {
      a=get(s,2);
      b=get(s+9,3);
      xlat23[a]=b;
      a=rot2(a);
      xlat23[a]=b;
      a=rot2(a);
      xlat23[a]=b;
      xlat23[rot2(a)]=b;
    } else {
      a=get(s,3);
      b=get(s+15,4);
      xlat34[a]=b;
      a=rot3(a);
      xlat34[a]=b;
      a=rot3(a);
      xlat34[a]=b;
      xlat34[rot3(a)]=b;
      a=fl3(a);
      xlat34[a]=b;
      a=rot3(a);
      xlat34[a]=b;
      a=rot3(a);
      xlat34[a]=b;
      xlat34[rot3(a)]=b;
    }       
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for(k=0;k<18;k++) {
    if(sz&1) {
      memset(xy2,'.',sizeof(xy2));
      np=sz/3;
      for (ni=0;ni<np;ni++) for (nj=0;nj<np;nj++) {
        a=0;
        for (i=ni*3;i<ni*3+3;i++) for (j=nj*3;j<nj*3+3;j++) a+=a+(xy[i][j]=='#');
        a=xlat34[a];
        for (i=0;i<4;i++) for (j=0;j<4;j++) if ((a>>(15-(i*4+j)))&1) xy2[4*ni+i][4*nj+j]='#'; // backward numbering
      }
      memmove(xy,xy2,sizeof(xy));
      sz=sz*4/3;
    } else {
      memset(xy2,'.',sizeof(xy2));
      np=sz/2;
      for (ni=0;ni<np;ni++) for (nj=0;nj<np;nj++) {
        a=0;
        for (i=ni*2;i<ni*2+2;i++) for (j=nj*2;j<nj*2+2;j++) a+=a+(xy[i][j]=='#');
        a=xlat23[a];
        for (i=0;i<3;i++) for (j=0;j<3;j++) if ((a>>(8-(i*3+j)))&1) xy2[3*ni+i][3*nj+j]='#'; // backward numbering
      }
      memmove(xy,xy2,sizeof(xy));
      sz=sz*3/2;
    }
    if (k==4) {  
      np=0;
      for (i=0;i<sz;i++) for (j=0;j<sz;j++) np+=(xy[i][j]=='#');
      printf("After 5 iterations %d pixels on.\n",np);
    }    
  }
  k=0;
  for (i=0;i<sz;i++) for (j=0;j<sz;j++) k+=(xy[i][j]=='#');
  printf("After 18 iterations %d pixels on.\n",k);  
}
