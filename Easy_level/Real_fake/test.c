/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*a;
    int sum,i,j;
    
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        
        sum=0;
        a=strtok(line," ");
        for(j=0;j<4;j++){            
            for(i=0;i<4;i++){
                if(i%2==0){
                    sum+=2*(a[i]-'0');
                }else{
                    sum+=1*(a[i]-'0');
                }
            }
            a=strtok(NULL," \n");
        }
        if(sum%10==0){
            printf("Real\n");
        }else{
            printf("Fake\n");
        }
        
    }
    fclose(input);
    return;  
}