/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int SegCollide( double *V1, double *V2, double *V3, double *V4, double *PA ){
  double v1[2];
  double v2[2];
  double det,t;
  v1[0]= (V2[0]-V1[0]);
  v1[1]= (V2[1]-V1[1]);
  v2[0]= (V4[0]-V3[0]);
  v2[1]= (V4[1]-V3[1]);
  det = -v1[0]*v2[1] + v1[1]*v2[0]; 
  if(det==0.0) return 0;
  t = ( -(V3[0]-V1[0])*v2[1] + (V3[1]-V1[1])*v2[0] )/det;
  if ( t >= -1 && t <=1 ){
    PA[0]=V1[0]+v1[0]*t;
    PA[1]=V1[1]+v1[1]*t;
    return 1;
  }else{
    return 0;
  }
}

int line_side ( double a[2], double b[2], double p[2] ){
  if ( (p[0] - a[0])*(b[1] - a[1]) - (p[1] - a[1])*(b[0] - a[0]) == 0 ){
    return 0; 
  }
  if ( (p[0] - a[0])*(b[1] - a[1]) - (p[1] - a[1])*(b[0] - a[0]) > 0 ){
    return 1;
  }else{
    return -1;
  }
}

int IsInTri( double *V1, double *V2, double *V3, double *P ){
  if ( (line_side (V1,V2,P) * line_side (V1,V3,P) <= 0) && (line_side (V2,V1,P) * line_side (V2,V3,P) <= 0) ){
    return 1;
  }else{
    return 0;
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  double V1[2];
  double V2[2];
  double V3[2];
  double V4[2];
  double P[2];
  double PA[2];
  char line[LINE_LENGTH];
  char *a,*b;
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,"|");
    b=strtok(NULL,"|");
    if(sscanf(a,"%lf %lf, %lf %lf, %lf %lf, %lf %lf",&V1[0],&V1[1],&V2[0],&V2[1],&V3[0],&V3[1],&V4[0],&V4[1])!=EOF && sscanf(b,"%lf %lf",&P[0],&P[1])!=EOF){
      if( SegCollide( V1,V2,V3,V4,PA ) ){
	if( IsInTri(PA,V2,V3,P) || IsInTri(PA,V1,V4,P) ){
	  printf("Prisoner\n");
	}else{
	  printf("Citizen\n");
	}
      }else if( SegCollide( V3,V2,V1,V4,PA ) ){
	if( IsInTri(PA,V1,V2,P) || IsInTri(PA,V3,V4,P) ){
	  printf("Prisoner\n");
	}else{
	  printf("Citizen\n");
	}
      }else{
	if( IsInTri(V1,V2,V3,P) || IsInTri(V3,V4,V1,P) ){
	  printf("Prisoner\n");
	}else{
	  printf("Citizen\n");
	}
      }
    }
  }  
  fclose(input);
  return 0; 
}
