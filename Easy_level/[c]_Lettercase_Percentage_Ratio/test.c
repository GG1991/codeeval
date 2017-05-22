/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int up,lw,i;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    up=lw=0;
    for(i=0;i<strlen(line);i++){
	if(line[i]>='a' && line[i]<='z')lw++;
	if(line[i]>='A' && line[i]<='Z')up++;
    }
    printf("lowercase: %.2f uppercase: %.2f\n",lw*100.0/(lw+up),up*100.0/(lw+up));
  }
  
  fclose(input);
  return; 
}
