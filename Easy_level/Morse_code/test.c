/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 6000
#define BASE 32

unsigned long hash(const char *s, unsigned long m) {
     unsigned long h;
     unsigned const char *us;
     /* cast s to unsigned const char * */
     /* this ensures that elements of s will be treated as having values >= 0 */
     us = (unsigned const char *) s; 
     h = 0;
     while(*us != '\0') {
         h = (h * BASE + *us) % m;
         us++;
     } 
     return h;
 }

void Sep(char *line){
 int flag=0,i;
 for(i=0;i<strlen(line);i++){
   if(line[i]!=' ')flag=0;
   if(line[i]==' ' && flag==1){
     line[i]='|';
     flag=0;
   }
   if(line[i]==' ')flag=1;   
 }
}
  
int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int i;
  char line[LINE_LENGTH];
  char *a;
  struct code{
   char letter;
   char *morse;
  }c[36] = {
    'A',".-",'B',"-...",'C',"-.-.",'D',"-..",'E',".",'F',"..-.",'G',"---.", 
    'H',"....",'I',"..",'J',".---",'K',"-.-",'L',".-..",'M',"--",'N',"-.",
    'O',"---",'P',".--.",'Q',"--.-",'R',".-.",'S',"...",'T',"-",'U',"..-",
    'V',"...-",'W',".--",'X',"-..-",'Y',"-.--",'Z',"--..",'1',".----",
    '2',"..---",'3',"...--",'4',"....-",'5',".....",'6',"-....",'7',"--...",
    '8',"---..",'9',"----.",'0',"-----"
  };
  char table[501];
  for(i=0;i<36;i++){
    table[hash(c[i].morse,501)]=c[i].letter;
//     printf("%d\n",hash(c[i].morse,301)); 
  }
//   printf("\n");
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    i=0;
    Sep(line);
    a=strtok(line," \n");
    while(a!=NULL && a!="\n"){
      if(a[0]=='|'){
	printf(" ");
	a++;
// 	a=strtok(NULL," \n");
      }else{
	printf("%c",table[hash(a,501)]);
	//       printf("%d\n",hash(a,199));
	a=strtok(NULL," \n");
      }
      
    }
    printf("\n");
  }

  
  fclose(input);
  return 0; 
}
