#include <stdio.h>
#include <stdlib.h>

#define M 11

struct node{
  char key;
};

void hashinitialize(void);
void hashinsert(char v);
int hash(char c);
int hash2(char c);
void hashprint(void);

struct node a[M];

int main(){
  char c;

  hashinitialize();

  printf("Input data: ");
  while( 1 ){
    c = getchar();
    if( c == '\n' ){
      break;
    }
    hashinsert(c);
    hashprint();
  }

  return 0;
}

void hashinitialize(void){
  int i;

  for( i=0; i<M; i++ ){
    a[i].key = ' ';
  }
}

void hashinsert(char v){
  
  int x = hash(v), u = hash2(v);
  while(1){if(a[x].key==' ')break;
     x = (x+u) % M;
  }
   a[x].key = v;
}
/* ここにプログラムを追加 */



int hash(char c){

 return (int)(c-64)%M;
  /* ここにプログラムを追加 */

}

int hash2(char c){

 return (int)8-(c-64)%8;
  /* ここにプログラムを追加 */

}

void hashprint(void){
  int i;

  for( i=0; i<M; i++ ){
    printf("%c ", a[i].key);
  }
  printf("\n");
}
