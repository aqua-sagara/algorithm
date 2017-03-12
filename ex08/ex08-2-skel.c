#include <stdio.h>

#define N 5

void print_array(int a[]);
void bubble(int a[]);
void insertion(int a[]);
void selection(int a[]);


int main(){
  int method;
  int a[N]={ 7, 1, 6, 5, 2 };
  void (*sort)(int []); /* 関数へのポインタ */

  printf("Before:  ");
  print_array(a);
  printf("\n");

  printf("Select a method (1:buble, 2:insertion: 3: selection) >  ");
  scanf("%d", &method);

  switch( method ){
  case 1:
    sort=bubble;
    break;
  case 2:
    sort=insertion;
    break;
  case 3:
    sort=selection;
    break;
  default:
    sort=bubble;
    break;
  }

  (*sort)(a);

  return 0;
}

void print_array(int a[]){
  int i;

  for( i=0; i<N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void bubble(int a[]){
  int i,j,temp,k;
  for(j=N-1;j>=1;j--){
    for(i=N-1;i>=0;i--){
      
      if(a[i]<a[i-1]){
	temp=a[i];
	a[i]=a[i-1];
	a[i-1]=temp;
      }
      
    } print_array(a);
    
  }  
  
}

void insertion(int a[]){
  int i,j,v;
  for(i=2;i<N;i++){
    v=a[i];
    j=i;
    while(a[j-1]>v){
      a[j]=a[j-1];
      j--;
    }
    a[j]=v;
    print_array(a);
  }
}
void selection(int a[]){
  int i,j,temp,min;
  for(i=0;i<N-1;i++){
    min=i;
    for(j=i+1;j<N;j++){
      if(a[min]>a[j]){
	min=j;

      }
      
    }temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    print_array(a);
    
  }
}
  
  
