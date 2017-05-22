/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char c, *data;
  char line[1024];
  int ofs,flg;
  
  while( fgets(line,1024,input) != NULL ){
    data=line;
    flg=1;
    while(sscanf(data,"%c%n",&c,&ofs) != EOF){
      if( flg==1 && 'a' <= c && c <= 'z' ){
	c=c-32;
	flg=0;
      }
      printf("%c",c);      
      data+=ofs;
      if( c <= 'a' || c >= 'z' ){
	flg = 0;
      }
      if( ' ' == c ){
	flg = 1;
      }
    }
  }
  printf("\n");  
  fclose(input);
  return; 
}
