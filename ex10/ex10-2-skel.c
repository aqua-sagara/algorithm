#include <stdio.h>

#define N 10

void printdata(void);
int binarysearch(int v);
int interpolationsearch(int v);

 int a[N]={ 4, 8, 10, 13, 16, 17, 19, 20, 23, 25 }; 

int main(){
  int key, ret;

  printdata();

  printf("Input key for binary search:  ");
  scanf("%d", &key);

  ret=binarysearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }
  printf("\n");

  printf("Input key for interpolation search:  ");
  scanf("%d", &key);

  ret=interpolationsearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }

  return 0;
}

int binarysearch(int v){

  /* ここにプログラムを追加 */
  int l=1,r=N-1,m;
  while(r>=l){
    m=(l+r)/2;
    if(v<a[m])r=m-1;
    else l=m+1;
      if(v==a[m])return a[m];
  }
  return -1;
}

int interpolationsearch(int v){

 /* ここにプログラムを追加 */ 
  int l=1,r=N-1,m;
  while(r>=l){
    m=l+(v-a[l])/(a[r]-a[l]);
    if(v<a[m])r=m-1;
    else l=m+1;
      if(v==a[m])return a[m];
  }
  return -1;
}

void printdata(void){
  int i;

  printf("data:  ");
  for( i=0; i<N; i++){
    printf("%d ", a[i]);
  }
  printf("\n\n");
}
