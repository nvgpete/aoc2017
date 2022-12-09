#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,c,tape[1000000];
  int newstate[6][2],move[6][2],write[6][2];
  int i,j,k,steps,pos=sizeof(tape)/2,state=0;
  memset(tape,0,sizeof(tape));
  f=fopen("d25.txt","r");
  fgets(s,sizeof(s),f);
  sscanf(s,"Begin in state %c",&c);
  state=c-'A';
  fgets(s,sizeof(s),f);
  sscanf(s,"Perform a diagnostic checksum after %d",&steps);
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    fgets(s,sizeof(s),f);
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"In state %c",&c);
    i=c-'A';
    do {
      fgets(s,sizeof(s),f);
      sscanf(s,"  If the current value is %d",&j);
      fgets(s,sizeof(s),f);
      sscanf(s,"    - Write the value %d",write[i]+j);
      fgets(s,sizeof(s),f);
      sscanf(s,"    - Move one slot to the %c",&c);
      if (c=='l') move[i][j]=-1; else move[i][j]=1;
      fgets(s,sizeof(s),f);
      sscanf(s,"    - Continue with state %c",&c);
      newstate[i][j]=c-'A';
    } while (j!=1);
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
//  for (i=0;i<6;i++) for (j=0;j<2;j++) 
//    printf("State=%c, val=%d, wr=%d, go=%2d, new=%c\n",i+'A',j,write[i][j],move[i][j],newstate[i][j]+'A');
  for (k=0; k<steps; k++) {
    i=tape[pos];
    tape[pos]=write[state][i];
    pos+=move[state][i];
    state=newstate[state][i];
  }
  i=0;
  for (k=0;k<sizeof(tape);k++) i+=tape[k];
  printf("%d ones on tape\n",i);
}
