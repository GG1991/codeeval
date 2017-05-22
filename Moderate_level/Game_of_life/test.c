/* Author Guido Giuntoli
 * 
 */
#include <stdio.h>
#define SIDE 10
#define NSTEPS 0

void PrintGame(char v[SIDE*SIDE]){
  int i,j;
  for(i=0;i<SIDE;i++){
    for(j=0;j<SIDE;j++){
      printf("%c",v[j+i*SIDE]);
    }
    printf("\n");
  }
}

int IsAlive(char c){
  if(c=='.'){
    return 1;
  }else{
    return 0;
  }  
}
int Belongs(int i){
  if(i<0||i>(SIDE*SIDE-1)){
    return 1;
  }else{  
    return 0;
  }
}
int NeighborsNum(int i,int n){
    if(n<3)return i-SIDE+1-n;
    if(3<=n&&n<5){
      if(i%SIDE==0&&n==3){
	return -1;
      }else if((i+1)%SIDE==0&&n==4){
	return -1;
      }
      return i+1-2*(4-n);
    }
    if(5<=n)return i+SIDE-1+(n-5);
}

int HowMuchNeighbors(char v[SIDE],int i){
  int count=0,n;
  for(n=0;n<8;n++){
    if(!Belongs(NeighborsNum(i,n))){
      if(!IsAlive(v[NeighborsNum(i,n)]))count++;
    }
  }
  return count;
}

int main(int argc,char **argv){
  int i,j,offset;
  char v_n[SIDE*SIDE];
  char v_o[SIDE*SIDE];
  FILE *input = fopen(argv[1],"r");
  char line[SIDE+2]; // hay que tomar el \n\0 por eso +2
  char *data;
  
  for(i=0;i<SIDE;i++){
    fgets(line,SIDE+2,input);
    data=line;
    for(j=0;j<SIDE;j++){
      sscanf(data,"%c%n",&v_n[j+i*SIDE],&offset);
      sscanf(data,"%c%n",&v_o[j+i*SIDE],&offset);
      data+=offset;
    }
  }
  //PrintGame(v_n);
  //printf("\n");
  for(i=0;i<NSTEPS;i++){
    for(j=0;j<SIDE*SIDE;j++){
      if(!IsAlive(v_o[j])&&HowMuchNeighbors(v_o,j)==2){
	v_n[j]='*';
      }else if(HowMuchNeighbors(v_o,j)==3){
	v_n[j]='*';
      }else{
	v_n[j]='.';
      }
    }
    for(j=0;j<(SIDE*SIDE);j++)v_o[j]=v_n[j];
    //PrintGame(v_n);
    //printf("\n");    
  }
  PrintGame(v_n);
  printf("\n");
  fclose(input);
  return 0;
}

