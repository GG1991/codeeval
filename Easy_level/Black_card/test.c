/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int HowWeHave(int iw[MAXN],int n){
    int i,c;
    c=n;
    for(i=0;i<n;i++)
        if(iw[i])c--;
    return c;
}

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*a,*a1,*b,names[MAXN][32];
    int n,n1,i,j,iw[MAXN];
    
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        
        n=0;
        a=strtok(line," ");
        
        while(a[0]!='|'){
            strcpy(names[n],a);
            n++;
            a=strtok(NULL," ");
        }
        a=strtok(NULL," ");
        sscanf(a,"%d",&n1);
        
        for(i=0;i<n;i++)
            iw[i]=0;
        
        while(HowWeHave(iw,n)>1){
            i=0;
            j=-1;
            while(i<n1){
                j++;
                if(j>=n)j=0;
                if(!iw[j])i++;                
            }
            iw[j]=1;
        }
        for(i=0;i<n;i++)
            if(!iw[i])printf("%s\n",names[i]);
        
    }
    fclose(input);
    return;  
}