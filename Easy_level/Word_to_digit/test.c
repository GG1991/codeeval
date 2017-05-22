/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024


int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char *a;
  char line[LINE_LENGTH];
  char s[]=";\n";

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok( line , s );
    while(a!=NULL){
      if(strcmp("one",a)==0) {
	printf("1");
      }else if(strcmp("two",a)==0) {
	printf("2");
      }else if(strcmp("three",a)==0) {
	printf("3");
      }else if(strcmp("four",a)==0) {
	printf("4");
      }else if(strcmp("five",a)==0) {
	printf("5");
      }else if(strcmp("six",a)==0) {
	printf("6");
      }else if(strcmp("seven",a)==0) {
	printf("7");
      }else if(strcmp("eight",a)==0) {
	printf("8");
      }else if(strcmp("nine",a)==0) {
	printf("9");
      } else if(strcmp("zero",a)==0) {
	printf("0");
      }
      a=strtok( NULL , s );
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
