#include<stdio.h>
#include<stdlib.h>
int stack[50];
int i=0;  int j;

int dtoi(char );
void push(int );
int pop();
void print_stack();
main(){
  char c;
  int a,b,d,e;
  while((c = getchar())!='\n'){
    if(c>='0'&&c<='9'){
      e=dtoi(c);
      push(e);
    }
    if(c=='+'){
      i--;
      a=pop();
      i--;
      b=pop();
      
      
      d=a+b;
      push(d);
    }
    if(c=='*'){
      i--;
      a=pop();
      i--;
      b=pop();
      
      d=a*b;
      push(d);
    }
    if(c=='/'){
   i--;
   a=pop();
   i--;
   b=pop();
   
   d=a/b;
   push(d);
    }
    print_stack();
    
  } printf("Answer: ");
  print_stack();
}
void push(int c){ 
  stack[i]=c;
  i++;
}
int pop()
{int c;
  c=stack[i];
  return c;
     
}
int isemptry(){}
int dtoi(char c){
  int a;
  a=c-48;
  return a;
}
void print_stack(){

  for(j=0;j<i;j++){
    printf("%d ",stack[j]);
  }
  printf("\n");
  
}

