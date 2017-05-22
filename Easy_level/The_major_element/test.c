/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#define N 101
#define LINE_LENGTH 80000

char *clean(char *str){
  int i;
  for(i=0;i<strlen(str);i++){
    if(str[i]==',')str[i]=' ';
  }
  return str;
}

void push(int v[N][2],int a,int *c){
  int i;
  for(i=0;i<*c;i++){
    if(v[i][0]==a){
      v[i][1]++;
      *c=*c+1;
      return;
    }
  }
  v[i][0]=a;
  v[i][1]++;
  *c=*c+1;
  return;
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];
  int v[N][2];
  int a,ofs,i,j,c,flag;
  char *data;
  
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    c=0;
    flag=0;
    data=line;
    data=clean(data);
    for(j=0;j<N;j++){
      v[j][0]=0;v[j][1]=0;
    }
    while(sscanf(data,"%d%n",&a,&ofs)!=EOF){
      push(v,a,&c);
      data+=ofs;
    }
    printf("%d ",c);
    for(i=0;i<c;i++){
      if(v[i][1]>c/2){
	printf("%d\n",v[i][0]);
	flag=1;
      }
    }
    if(flag==0) printf("None\n");
  }
  fclose(input);
  return; 
}
