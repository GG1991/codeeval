/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int v[26],ofs,flg,i;
  char line[LINE_LENGTH];
  char c,*data;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    data=line;
    for(i=0;i<26;i++){
      v[i]=0;
    }
    flg=0;
    while(sscanf(data,"%c%n",&c,&ofs)!=EOF){
      if(65<=c && c<=90 ){
	v[c-65]=1;
      }
      if(97<=c && c<=122 ){
	v[c-97]=1;
      }
      data+=ofs;
    }
    for(i=0;i<26;i++){
      if( v[i]==0 ){
	printf("%c",i+97);
	flg=1;
      }
    }
    if(flg==0){
      printf("NULL");
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
