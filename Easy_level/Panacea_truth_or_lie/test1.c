/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int num, offset=0;
  int h,sum_h,sum_b;
  char line[LINE_LENGTH];
  char * hl, * bl;
  char b[32];
  char sg;
  char s[]="|";

  while( fgets(line, LINE_LENGTH, input) != NULL ){
    hl=strtok(line,s);
    bl=strtok(NULL,s);
    sum_h=0;sum_b=0;
    while(sscanf(hl,"%x%n",&h,&offset)!=EOF){
      sum_h+=h;
      hl+=offset;
    }
    while(sscanf(bl,"%s%n",&b,&offset)!=EOF){
      sum_b+=strtol(b,NULL,2);
      bl+=offset;
    }
//     printf("%d %d ",sum_h,sum_b);
    if(sum_h<=sum_b){
      printf("True \n");
    }else{
      printf("False \n");
    }
  }
  
  fclose(input);
  return; 
}