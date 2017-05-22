/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256

void clean(char *str,int n){
 int i;
 for(i=0;i<n;i++){
  if(str[i]==',')str[i]=' '; 
 }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int offset1,offset2,first_time;
  char line[LINE_LENGTH];
  char *lhs,*rhs;
  int a,b;
  char s[]=";";

  while(fgets(line,LINE_LENGTH,input)!=NULL){
    lhs=strtok(line,s);
    rhs=strtok(NULL,s);
    clean(lhs,strlen(lhs));
    clean(rhs,strlen(rhs));
    first_time=1;
    while(sscanf(lhs,"%d%n",&a,&offset1)!=EOF && sscanf(rhs,"%d%n",&b,&offset2)!=EOF){
      if(a==b){
	(first_time==1)?printf("%d",a):printf(",%d",a);
	lhs+=offset1;
	rhs+=offset2;
	first_time=0;
      }else if(b>a){
	lhs+=offset1;
      }else{
	rhs+=offset2;
      }
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
