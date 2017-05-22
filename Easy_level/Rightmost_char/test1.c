/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[256];
  char c,cr,*w;
  int a,b,fl,ofs;
  char s[]=",", *data;
  
  while(fgets(line,256,input)!= NULL ){ 
    w=strtok(line,s);
    data=strtok(NULL,s);
    c=data[0];
    data=w;
    a=0;
    fl=0;
    while(sscanf(data,"%c%n",&cr,&ofs) != EOF){
      if(cr==c){
	b=a;
	fl=1;
      }
      data+=ofs;
      a++;
    }
    if(fl==1){
      printf("%d\n",b);
    }else{
      printf("-1\n");
    }
  }
  fclose(input);
  return; 
}
