/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int m1,m2,y1,y2,totalmonths,ofs;
  char line[LINE_LENGTH], month[3],month1[3],month2[3],*data;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
      totalmonths=0;
      data = strtok(line,";");
      
      while (data!=NULL){
	  sscanf(data,"%s %d-%s %d",month1,&y1,month2,&y2);
	  
	  if(strcmp(month1,"Jan")==0){
	      m1=1;
	  }else if(strcmp(month1,"Feb")==0){
	      m1=2;
	  }else if(strcmp(month1,"Mar")==0){
	      m1=3;
	  }else if(strcmp(month1,"Apr")==0){
	      m1=4;
	  }else if(strcmp(month1,"May")==0){
	      m1=5;
	  }else if(strcmp(month1,"Jun")==0){
	      m1=6;
	  }else if(strcmp(month1,"Jul")==0){
	      m1=7;
	  }else if(strcmp(month1,"Aug")==0){
	      m1=8;
	  }else if(strcmp(month1,"Sep")==0){
	      m1=9;
	  }else if(strcmp(month1,"Oct")==0){
	      m1=10;
	  }else if(strcmp(month1,"Nov")==0){
	      m1=11;
	  }else if(strcmp(month1,"Dec")==0){
	      m1=12;
	  }
	  
	  if(strcmp(month2,"Jan")==0){
	      m2=1;
	  }else if(strcmp(month2,"Feb")==0){
	      m2=2;
	  }else if(strcmp(month2,"Mar")==0){
	      m2=3;
	  }else if(strcmp(month2,"Apr")==0){
	      m2=4;
	  }else if(strcmp(month2,"May")==0){
	      m2=5;
	  }else if(strcmp(month2,"Jun")==0){
	      m2=6;
	  }else if(strcmp(month2,"Jul")==0){
	      m2=7;
	  }else if(strcmp(month2,"Aug")==0){
	      m2=8;
	  }else if(strcmp(month2,"Sep")==0){
	      m2=9;
	  }else if(strcmp(month2,"Oct")==0){
	      m2=10;
	  }else if(strcmp(month2,"Nov")==0){
	      m2=11;
	  }else if(strcmp(month2,"Dec")==0){
	      m2=12;
	  }

	  data =strtok(NULL,";\n");
      }
      if(m2_max>m1_min){
	  printf("%d\n", (y2_max-y1_mi)*12 + m2-m1+1 );
      }else{
	  printf("%d\n", (y2-y1-1)*12 + 12 + m2 - m1 + 1 );
      }

  }
  
  fclose(input);
  return; 
}
