/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MESSAGE 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int num[MESSAGE],i,j,n,ofs;
  char line[LINE_LENGTH];
  char *a,*b;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,"|");
    b=strtok(NULL,"|");
    i=0;
    while( sscanf(b,"%d%n",&n,&ofs) != EOF ){
      num[i]=n-1;
      b+=ofs;
      i++;
    }
    for(j=0;j<i;j++){
      printf("%c",a[num[j]]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
