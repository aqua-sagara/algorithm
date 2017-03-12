#include <stdio.h>
#include <stdlib.h>

#define M 5

struct node {
  int key;
  struct node *next;
};
typedef struct node * NodePointer;

void hashlistinitialize(void);
void append_to_list(NodePointer head, char c);
int hash(char c);
void display_list(NodePointer head);


NodePointer heads[M], tail;

int main(){
  int i;
  char c;

  hashlistinitialize();

  printf("Input data: ");
  while( 1 ){
    c = getchar();
    if( c == '\n' ){
      break;
    }
    append_to_list(heads[hash(c)], c);
  }

  /* display all lists */
  for(i=0; i<M; i++){
    printf("%2d: ", i);
    display_list(heads[i]);
  }

  exit(0);
}

void hashlistinitialize(void){
  int i;
  tail = malloc(sizeof(struct node));
  tail->next = tail;
  for (i=0; i<M; i++){
    heads[i] = malloc(sizeof(struct node));
    heads[i]->next = tail;
  }
}


void append_to_list(NodePointer head, char c){
  
  /* ここにプログラムを追加 */
  NodePointer x;
  x=head->next;
  head->next=malloc(sizeof(struct node));
  head->next->key=c;
  head->next->next=x;
}

int hash(char c){
  
  /* ここにプログラムを追加 */
 return (int)(c-64)%M;
}


void display_list(NodePointer head){
  NodePointer node;

  node = head->next;
  while( node!=tail ) {
    printf("%c ", node->key);
    node = node->next;
  }
  printf("\n");
}
