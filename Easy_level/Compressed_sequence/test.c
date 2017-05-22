/* Author : Guido Giuntoli */

#include <stdio.h>
#define LINE_LENGTH 4048

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int c,ofs,nn,no;
  char line[LINE_LENGTH];
  char *data;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    data=line;
    c=0;
    while(sscanf(data,"%d%n",&nn,&ofs)!=EOF){
      data+=ofs;
      if(c==0)no=nn;
      if(nn==no){
        c++;
      }else{
        printf("%d %d ",c,no);
        c=1; 
      }     
      no=nn;
    }       
    printf("%d %d ",c,no);
    printf("\n");
  }  
  fclose(input);
  return; 
}
