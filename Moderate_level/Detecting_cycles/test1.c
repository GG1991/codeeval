/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAX_NUM 1024

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int ofs, i, n;
  char line[LINE_LENGTH], *data;
  int num[MAX_NUM];
  int a, b, a0, b0, flg, mu, lamda, k, ka;

  while( fgets(line, LINE_LENGTH, input) != NULL ){
    data=line;
    i=0;lamda=0;
    while(sscanf(data,"%d%n",&n,&ofs)!=EOF){
      num[i]=n;
      data+=ofs;
      i++;
    }
    a=0; 
    b=a+1;
    while(b<i){
      if(num[a]==num[b]){
	break;
      }
      a=a+1;
      b=b+2;
    } 
    if(num[a]==num[b]){
      b=b-a;
      a=0;
      mu=0;
      while( num[a]!=num[b] ){	
	a++;
	b++;
	mu++;
      }
      b=a+1;
      lamda=1;
      while( num[a]!=num[b] ){	
	b=b+1;
	lamda++;
      }
      
    }else{
      b=i-1;
      a=b-1;
      while(a > 0 && num[a]!=num[b]){
	a--;
      }
      if(num[a]==num[b]){
	lamda=b-a;
	while(num[a]==num[b]){
	  a--;
	  b--;
	}
	mu=a+1;
      }      
    }
    for(i=mu;i<mu+lamda;i++){
	printf("%d ",num[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
