/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

char *clean_line(char *str){
  int i;
  for(i=0;i<strlen(str);i++)
    if(str[i]==',') str[i]=' ';
  return str;
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a,b,ofs,fs,fp;
  char line[128];
  char *data;

  while(fgets(line,128,input)!= NULL ){ 
    fs=1;b=0;fp=1;
    data=clean_line(line);
    while(sscanf(data,"%d%n",&a,&ofs)!=EOF){
      if( b!=a && !fs){
	if(fp){
	  printf("%d",b);
	}else{
	  printf(",%d",b);
	}
	fp=0;
      }    
      b=a;
      fs=0;
      data+=ofs;
    }
    if(fp){
      printf("%d",b);
    }else{
      printf(",%d",b);
    }
    printf("\n");    
  }
  
  fclose(input);
  return; 
}
