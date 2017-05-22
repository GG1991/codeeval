/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int n,n1,n2,n3;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%d",&n);
    if(n<=26){
      printf("%c",n+64);
    }else if(26<n && n<=26+26*26){
      n1=(n-1)%26;
      n2=(n-1)/26;
      printf("%c%c",n2+64,n1+65);
    }else if(26+26*26<n && n<=26+26*26+26*26*26){
      n1=(n-1)%26;
      n2=(n-n1)/26 % 26;
      n3=(n-1)/(26*26);
      printf("%c%c%c",n3+64,n2+64,n1+65);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
