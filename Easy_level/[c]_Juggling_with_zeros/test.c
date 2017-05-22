/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define LINE_LENGTH 2048

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int fl,i,n,dec,number[254],aux,j;
  char line[LINE_LENGTH],*data;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    data=strtok(line," ");
    n=0;
    while(data!=NULL){
	
	fl = (strcmp(data,"0")==0)?1:0;
	
	data=strtok(NULL," \n");
	if(fl==0){
	    for(i=0;i<strlen(data);i++){
		number[n]=1;
		n++;
	    }
	}else{
	    for(i=0;i<strlen(data);i++){
		number[n]=0;
		n++;
	    }
	}
	data=strtok(NULL," ");
    }
    dec=0;
    for(i=n-1;i>=0;i--){
	aux=1;
	for(j=0;j<i;j++){
	    aux *= 2;
	}
	dec+=number[i]*aux;
    }
    printf("%d\n",dec);
  }
  
  fclose(input);
  return; 
}
