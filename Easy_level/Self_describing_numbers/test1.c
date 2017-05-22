/* Author : Guido Giuntoli */

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a,nd,i,j,c,flag;
  int v[32];
  char line[32];
  
  while(fgets(line,32,input)!= NULL ){ 
    sscanf(line,"%d",&a);
    nd=0;
    while(a/(int)pow(10,nd)>=10){
      nd++;
    }
    for(i=nd;i>=0;i--){
      v[nd-i]=(a%(int)pow(10,i+1))/(int)pow(10,i);
    }
    flag=0;
    for(i=0;i<=nd;i++){
      c=0;
      for(j=0;j<=nd;j++){
	if(v[j]==i)c++;
      }
      if(c!=v[i])flag=1;
    }
    if(flag==1){
      printf("0\n");
    }else{
      printf("1\n");
    }       
  }    
  fclose(input);
  return; 
}
