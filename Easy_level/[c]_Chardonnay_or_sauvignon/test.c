/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 1000

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int main(int argc, char **argv){
 
  FILE  *input = fopen(argv[1],"r");
  int   n,m,i,j,ofs,k;
  char  line[LINE_LENGTH];
  char  *a,*b;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    b=strtok(line,"|");
    b=strtok(NULL," \n");
    qsort(b, strlen(b), sizeof(char), cmpfunc);
    a=strtok(line," ");
    m=0;
    while(a!=NULL){
	n = 0;
	ofs = 0;
	k=0;
	//recorremos palabra por palabra
	for( i=0;i<strlen(b);i++ ){  
	    if(i>0){
		if(b[i]==b[i-1]){
		    ofs++;
		}else{
		    ofs=0;
		}
	    }
	    for( j=0;j<strlen(a);j++ ){  
		if(a[j]==b[i])k++;
		if(a[j]==b[i] && k>ofs){
		    n++;
		    ofs++;
		    break;
		}
	    }
	}
	if(n==strlen(b)) {
	    if(m==0){
		printf("%s",a);
	    }else{
		printf(" %s",a);
	    }
	    m++;
	}	    
	a=strtok(NULL," ");
    }
    if(m==0)
	printf("False");
    printf("\n");
  }
  
  fclose(input);
  return 0; 
}
