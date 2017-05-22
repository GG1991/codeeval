/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int h;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%d",&h);
    if(0<=h && h<=2){
      printf("Still in Mama's arms\n");
    }else if(3<=h && h<=4){
      printf("Preschool Maniac\n");
    }else if(5<=h && h<=11){
      printf("Elementary school\n");
    }else if(12<=h && h<=14){
      printf("Middle school\n");
    }else if(15<=h && h<=18){
      printf("High school\n");
    }else if(19<=h && h<=22){
      printf("College\n");
    }else if(23<=h && h<=65){
      printf("Working for the man\n");
    }else if(65<=h && h<=100){
      printf("The Golden Years\n");
    }else{
      printf("This program is for humans\n");
    }
  }
  
  fclose(input);
  return; 
}
