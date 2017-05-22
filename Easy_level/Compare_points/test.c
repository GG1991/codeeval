/* Author : Guido Giuntoli */

#include <stdio.h>

#define LINE_LENGTH 1024

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH];
    int O,P,Q,R;
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        
        sscanf(line,"%d %d %d %d",&O,&P,&Q,&R);  
        
        if( O==Q && P==R ){
            printf("here\n");
	}else if( O==Q ){
	   if( R-P>0 ){
	      printf("N\n");     
	   }else{
	      printf("S\n");
	   }
	}else if( P==R ){
	   if( Q-O>0 ){
	      printf("E\n");     
	   }else{
	      printf("W\n");
	   }
	}else if( R-P>0 && Q-O>0 ){
	      printf("NE\n");     
	}else if( R-P<0 && Q-O>0 ){
	      printf("SE\n");     
	}else if( R-P<0 && Q-O<0 ){
	      printf("SW\n");     
	}else if( R-P>0 && Q-O<0 ){
	      printf("NW\n");     
	}
    }
    
    fclose(input);
    return; 
}