#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,opc[50],r1[50],r2[50];
  int pc,last=0;
  long rg[26]; //a-z
  long val[50],tone=0;
  memset(rg,0,sizeof(rg));
  f=fopen("d18.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    r1[last]=s[4]-'a';
    if (s[5]) {
      if(s[6]>='a' && s[6]<='z') r2[last]=s[6]-'a';
      else {
        r2[last]=-1;
        val[last]=atoi(s+6);
      }
    }    
    if (strncmp(s,"set",3)==0) opc[last]='s';
    else if (strncmp(s,"mul",3)==0) opc[last]='m'; 
    else if (strncmp(s,"mod",3)==0) opc[last]='d';
    else if (strncmp(s,"add",3)==0) opc[last]='a';
    else if (strncmp(s,"snd",3)==0) opc[last]='t';
    else if (strncmp(s,"rcv",3)==0) opc[last]='r';
    else if (strncmp(s,"jgz",3)==0) {
      if(r1[last]=='1') opc[last]='u';
      else opc[last]='j';
    }
    last++;  
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  pc=0;
  while (pc>=0 && pc<last) {
    switch (opc[pc]) {
      case 's': rg[r1[pc]]=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 'm': rg[r1[pc]]*=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 'd': rg[r1[pc]]%=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 'a': rg[r1[pc]]+=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 't': tone=rg[r1[pc]];
                break;
      case 'r': if (rg[r1[pc]]) {
                  rg[r1[pc]]=tone;
                  printf("Tone=%ld\n",tone);
                  exit(0);
                }  
                break;
      case 'j': if (rg[r1[pc]]<=0) break;
      case 'u': pc+=(r2[pc]>=0 ? rg[r2[pc]] : val[pc])-1;
    }
    pc++;
  }
}
