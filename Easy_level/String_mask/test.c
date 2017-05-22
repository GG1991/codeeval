/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*a,*b;
    int sum,i;
    
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        
        sum=0;
        a=strtok(line," ");
        b=strtok(NULL," \n");
        
        for(i=0;i<strlen(a);i++){
            if(b[i]=='1'){
                printf("%c",a[i]-'a'+'A');
            }else{
                printf("%c",a[i]);
            }
        }
        printf("\n");
        
    }
    fclose(input);
    return;  
}