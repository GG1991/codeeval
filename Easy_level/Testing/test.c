/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*a,*b;
    int errors,i;
    
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        a=strtok(line,"|");
        b=strtok(NULL,"|");
        b++;
        errors=0;
        
        for(i=0;i<strlen(a)-1;i++)
            if(a[i]!=b[i])errors++;
        
        if(errors==0){
            printf("Done\n");
        }else if(errors<=2){
            printf("Low\n");
        }else if(errors<=4){
            printf("Medium\n");
        }else if(errors<=6){
            printf("High\n");
        }else{
            printf("Critical\n");
        }
        
    }
    fclose(input);
    return;  
}