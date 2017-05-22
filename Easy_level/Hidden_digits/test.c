/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*data;
    char c;
    int ofs,flg;
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        data=line;
        flg=0;
        while( sscanf(data,"%c%n",&c,&ofs)!=EOF ){
            if('a'<=c && c<='j'){
                printf("%d",c-'a');
                flg=1;
            }
            if('0'<=c && c<='9'){
                printf("%d",c-'0');
                flg=1;
            }
            data+=ofs;
        }
        if(flg==0)printf("NONE");
        printf("\n");
              
    }
    
    fclose(input);
    return; 
}