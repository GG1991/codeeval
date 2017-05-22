/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 1024

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int L1[64],L2[64],n,i,ofs1,ofs2;
  char line[LINE_LENGTH];
  char *a,*b;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,"|");
    b=strtok(NULL,"|");
    n=0;
    while(  sscanf(a,"%d%n",&L1[n],&ofs1)!=EOF && sscanf(b,"%d%n",&L2[n],&ofs2)!=EOF ){
     a+=ofs1;
     b+=ofs2;
     n++; 
    }
    for(i=0;i<n;i++){
      printf("%d ",L1[i]*L2[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
