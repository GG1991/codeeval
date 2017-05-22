/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define LINE_LENGTH 256

void clean_line(char str[],int n){
  int i;
  for(i=0;i<n;i++)
    if(str[i]=='(' || str[i]==')' || str[i]==',') str[i]=' ';
  return;
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int i,p[4];
  int dist,offset;
  char *data;
  char line[LINE_LENGTH];
  
  while( fgets(line, LINE_LENGTH, input) != NULL ){
    clean_line(line,strlen(line));
    data=line;
    for(i=0;i<4;i++){
       sscanf(data,"%d%n",&p[i],&offset);
       data+=offset;
    }
    i=round(sqrt(pow(p[0]-p[2],2)+pow(p[1]-p[3],2)));
    printf( "%d\n",i);
  }
  fclose(input);
  return 0; 
}
