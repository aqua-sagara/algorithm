#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  char key;
  struct node *left;
};
typedef struct node * NodePointer;

void treeinitialize(void);
NodePointer makenode(char c);
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

NodePointer head, tail;

int main(){
  treeinitialize();

  /* テスト用の木を作成 */
  head->right=makenode('+');
  head->right->left=makenode('1');
  head->right->right=makenode('*');
  head->right->right->left=makenode('2');
  head->right->right->right=makenode('3');


  /* トラバース */
  printf("preorder:  ");
  preorder(head->right);
  printf("\n");

  printf("inorder:   ");
  inorder(head->right);
  printf("\n");

  printf("postorder: ");
  postorder(head->right);
  printf("\n");

  return 0;
}

void treeinitialize(void){
  head=makenode(-1);
  tail=makenode(-1);
  head->right=tail;
  head->left=tail;
}

/*
 * ノードを作成し、そのノードへのポインタを返す。
 */
NodePointer makenode(char c){
  NodePointer x;

  x=malloc(sizeof(struct node));
  x->key=c;
  x->right=tail;
  x->left=tail;

  return x;
}

void preorder(NodePointer node){
  printf("%c ",node->key);
  printf("%c ",node->left->key);
  printf("%c ",node->right->key);
 printf("%c ",node->right->left->key);
 printf("%c ",node->right->right->key);
}

void inorder(NodePointer node){
 printf("%c ",node->left->key);
  printf("%c ",node->key);
printf("%c ",node->right->left->key);
 printf("%c ",node->right->key);
 printf("%c ",node->right->right->key);
}

void postorder(NodePointer node){
 printf("%c ",node->left->key);
 printf("%c ",node->right->left->key);
printf("%c ",node->right->right->key);
 printf("%c ",node->right->key);
printf("%c ",node->key);
}
