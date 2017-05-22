/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 10000

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

void clean(char *str){
  int i;
  for(i=0;i<strlen(str);i++)
    if( ( 48>str[i] || 57<str[i] ) ) str[i]=' '; 
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int ofs, num[1024],c,i;
  char line[LINE_LENGTH];
  char *data;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    clean(line);
    c=0;
    data=line;
    while( sscanf(data,"%d%n",&num[c],&ofs)!=EOF){
      data+=ofs;
      c++;
    }
    qsort( num , c , sizeof(int) , cmpfunc );
    if(c>0) printf("%d",num[0]);
    for(i=1;i<c;i++)
      printf(",%d",num[i]-num[i-1]);
    
    printf("\n");
  }
  
  fclose(input);
  return; 
}
