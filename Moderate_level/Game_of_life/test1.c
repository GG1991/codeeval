/* Author Guido Giuntoli
 * 
 */
#include <stdio.h>
#define SIDE 100
#define NSTEPS 10

void PrintGame(char v[SIDE][SIDE]){
  int i,j;
  for(i=0;i<SIDE;i++){
    for(j=0;j<SIDE;j++){
      printf("%c",v[i][j]);
    }
    printf("\n");
  }
}

int HowManyNeighbors(char v[SIDE][SIDE],int i,int j){
  int count=0,n;
  int ni[8]={+1, +0, -1, -1, -1, +0, +1, +1};
  int nj[8]={+1, +1, +1, +0, -1, -1, -1, +0};
  for(n=0;n<8;n++){
    if((i+ni[n]>=0)&&(i+ni[n]<SIDE)&&(j+nj[n]>=0)&&(j+nj[n]<SIDE)){
      if(v[i+ni[n]][j+nj[n]]=='*')count++;
    }
  }
  return count;
}

int main(int argc,char **argv){
  int i,j,s,offset;
  char v_n[SIDE][SIDE];
  char v_o[SIDE][SIDE];
  FILE *input = fopen(argv[1],"r");
  char line[SIDE+2]; // hay que tomar el \n\0 por eso +2
  char *data;
  
  for(i=0;i<SIDE;i++){
    fgets(line,SIDE+2,input);
    data=line;
    for(j=0;j<SIDE;j++){
      sscanf(data,"%c%n",&v_n[i][j],&offset);
      sscanf(data,"%c%n",&v_o[i][j],&offset);
      data+=offset;
    }
  }
  //PrintGame(v_n);
  //printf("\n");
  for(s=0;s<NSTEPS;s++){
    for(i=0;i<SIDE;i++){
      for(j=0;j<SIDE;j++){
	if((v_o[i][j]=='*')&&(HowManyNeighbors(v_o,i,j)==2)){
	  v_n[i][j]='*';
	}else if(HowManyNeighbors(v_o,i,j)==3){
	  v_n[i][j]='*';
	}else{
	  v_n[i][j]='.';
	}
      }
    }
    for(i=0;i<SIDE;i++){
      for(j=0;j<SIDE;j++){
	v_o[i][j]=v_n[i][j];
      }
    }
    //PrintGame(v_n);
    //printf("\n");    
  }
  PrintGame(v_n);
  //printf("\n");
  fclose(input);
  return 0;
}

