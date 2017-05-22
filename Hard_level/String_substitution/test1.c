/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 8096
#define MAX 100
#define NMAX 150

int c,k,NM;
typedef struct {
  unsigned int stat : 2;
}binvec_t;

typedef struct {
  binvec_t data[MAX];
  int I;
  int size;
}arrayvec_t;

binvec_t ba[MAX];
binvec_t bb1[MAX];
binvec_t bb2[MAX];

arrayvec_t pert[NMAX];

int Comp( int i, int sb1, int sba ){
  int j,m=0;
  if(i+sb1>sba)return 0;
  for(j=0;j<sb1;j++){
    if(ba[i+j].stat==2)return 0;
    m = (ba[i+j].stat ^ bb1[j].stat);
    if(m>0)break;
  }
  return (m==0)?1:0;
}

void Ordena(void){
  int i,j;
  arrayvec_t aux;
  for (i=1;i<NM;i++){
    for (j=0; j<NM-1 ;j++){
      if (pert[j].I > pert[j+1].I){
	aux=pert[j];
	pert[j]=pert[j+1];
	pert[j+1]=aux;
      }
    }
  } 
}

void Replace(int sba, int sb1, int sb2){
  int i=0,j;
  while( i < sba ){
    if( Comp( i , sb1 , sba ) ){
      
      for( j=0 ; j<sb2 ; j++ )
	pert[NM].data[j].stat=bb2[j].stat;
      for( j=0 ; j<sb1 ; j++ )
	ba[i+j].stat=2;
      
      pert[NM].I=i;
      pert[NM].size=sb2;
      NM++;  
      i=i+sb1-1;
    }
    i++;
  }
  return;
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char *a,*b1,*b2;
  char line[LINE_LENGTH];
  int i,j,n;
  
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,";");
    for(j=0;j<strlen(a);j++)
      ba[j].stat=a[j]-48;
    
    b1=strtok(NULL,",\n");
    b2=strtok(NULL,",\n");
        
    NM=0;
    while( b1!=NULL && b2!=NULL ){
      
      for(j=0;j<strlen(b1);j++)
	bb1[j].stat=b1[j]-48;
      for(j=0;j<strlen(b2);j++)
	bb2[j].stat=b2[j]-48;
      
      Replace(strlen(a),strlen(b1),strlen(b2));
      b1=strtok(NULL,",\n");
      b2=strtok(NULL,",\n");
      
    }
    Ordena();
    n=0;
    for(j=0;j<strlen(a);j++){
      if(ba[j].stat!=2){
	printf("%c",ba[j].stat+48);
      }else{
	if(n<NM&&j==pert[n].I){
	  for(i=0;i<pert[n].size;i++)
	    printf("%c",pert[n].data[i].stat+48);
	  n++;
	}
      }      
    }
    printf("\n");
    
  }  
  fclose(input);
  return; 
}
