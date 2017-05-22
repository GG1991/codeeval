/* Author : Guido Giuntoli */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int num;
  struct node *izq;
  struct node *der;
}node_t;

typedef struct list{
  node_t * head;
}tree_t;

int LowCommAnc( node_t *node , int a , int b ){
  node_t *LCA1=node;
  node_t *LCA2=node;
  node_t * LCA;
  while( LCA1 == LCA2 ){
    LCA = LCA1;
    if(LCA->num == a)return a;
    if(LCA->num == b)return b;
    LCA1 = (LCA->num<a) ? LCA->der : LCA->izq;
    LCA2 = (LCA->num<b) ? LCA->der : LCA->izq;    
  }
  return LCA->num;
}

void Insert(node_t *node, int n){
  if(node->num < n){
    if(node->der == NULL){
      node->der = (node_t*)malloc(sizeof(node_t));
      node->der->num = n;
      return;
    }else{
      Insert(node->der, n);
    }
  }else{
    if(node->izq == NULL){
      node->izq = (node_t*)malloc(sizeof(node_t));
      node->izq->num = n;
      return;
    }else{
      Insert(node->izq, n);
    }
  }  
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[32];
  int n[7]={30, 8, 52, 3, 20, 10, 29};
  int i,a,b;
  tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
  tree->head = (node_t*)malloc(sizeof(node_t));
  tree->head->num = n[0];
  for(i=1;i<7;i++){
    Insert(tree->head,n[i]);
  }
  while( fgets(line,32,input) != NULL ){
    sscanf(line,"%d %d",&a,&b);
    printf("%d\n", LowCommAnc(tree->head,a,b) );
  }
  

  return; 
}
