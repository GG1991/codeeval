/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define SUDO_MAX 9
#define LINE_LENGTH 256

void clean(char *str){
  int i;
  for(i=0;i<strlen(str);i++){
    if(str[i]==';'||str[i]==',')str[i]=' ';
  }
  return ;
}

void PrintSudo(int v[SUDO_MAX][SUDO_MAX],int N){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%d ",v[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH], *data;
  int v[SUDO_MAX][SUDO_MAX],N,offset,i,j;
  int iw,flag;
  
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    clean(line);
    data=line;
    sscanf(data,"%d%n",&N,&offset);
    
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
	data+=offset;
	sscanf(data,"%d%n",&v[i][j],&offset);
      }
    }
    
    flag=0;
    //barremos cada fila y anotamos apariciones
    for(i=0; i<N ;i++){
      iw=0;
      for(j=0;j<N;j++){ 
	iw=iw|(1<<(v[i][j]-1));
      }
      if(N==4 && iw!=15)flag=1;
      if(N==9 && iw!=511)flag=1;
    }
    //barremos cada columna y anotamos apariciones    
    for(i=0; i<N ;i++){
      iw=0;
      for(j=0; j<N ;j++){ 
	iw=iw|(1<<(v[j][i]-1));
      }
      if(N==4 && iw!=15)flag=1;
      if(N==9 && iw!=511)flag=1;
    }
    //barremos los N cuadrados y buscamos apariciones adentro 
    for(i=0; i<N ;i++){
      iw=0;
      for(j=0; j<N ;j++){
	if(N==4){ iw=iw|(1 << ( v[2*(i/2)+j/2][2*(i%2)+j%2]-1));}
	if(N==9){ iw=iw|(1 << ( v[3*(i/3)+j/3][3*(i%3)+j%3]-1));}
// 	 printf("( %d %d )",(3*(i/3)+j/3),(3*(i%3)+j%3));
      }
      if(N==4 && iw!=15)flag=1;
      if(N==9 && iw!=511)flag=1;
    }
    
    if(flag==0){
      printf("True\n");
    }else{
      printf("False\n");
    }    
    //PrintSudo(v,N);
    //printf("\n");
  }
  fclose(input);
  return; 
}
