/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 1024

typedef struct node{
  char str[LENGTH];
  int len;
  struct node *next;
}node_t;

typedef struct list{
  node_t * head;
}list_t;

int strlen_g(char *str){
 int i=0;
 while(str[i]!='\n' && str[i]!='\0'){
   i++;
 }
 return i;
}

void InsertSort(list_t *list,char *line){

  node_t *aux;
  node_t *dw,*up;

  aux=(node_t*)malloc(sizeof(node_t));
  strcpy(aux->str,line);
  aux->len=strlen_g(line);
  
  if(list->head==NULL){
    list->head=aux;
    return;
  }
  if(list->head->len < aux->len){
    aux->next=list->head;
    list->head=aux;
    return;
  }
  
  dw=list->head;
  up=list->head->next;
  
  while(up!=NULL){
    if(aux->len >= up->len){
      aux->next=up;
      dw->next=aux;
      return;
    }
    up=up->next;
    dw=dw->next;
  }
  dw->next=aux;
  return;
}

char *clean(char *str){
  int i;
  for(i=0;i<strlen(str);i++){
    if(str[i]=='\n')str[i]=' '; 
  }
  return str;
}



int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LENGTH];
  int n,i;
  list_t *list = (list_t*)malloc(sizeof(list_t));
  node_t *aux;
  
  if(fgets(line,LENGTH,input)!= NULL){
    sscanf(line,"%d",&n);
  }
  
  while(fgets(line,LENGTH,input)!= NULL ){    
    InsertSort(list,line);
  }
  fclose(input);
  
  aux=list->head;
//   printf("%d\n",n);
  for(i=0;i<n;i++){
      printf("%d %s\n",aux->len,clean(aux->str));
      aux=aux->next;
  }
  return; 
}
