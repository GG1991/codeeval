/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char c, *data;
  char line[1024];
  int ofs;
  
  while( fgets(line,32,input) != NULL ){
    data=line;
    while(sscanf(data,"%c%n",&c,&ofs) != EOF){
      if( 97 <= c && c <= 122 ){
	printf("%c",c-32);
      }else if( 65 <= c && c <= 90 ){
	printf("%c",c+32);
      }else{
	printf("%c",c);
      }
      data+=ofs;
    }
  }
  printf("\n");  
  fclose(input);
  return; 
}
