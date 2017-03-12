#include<stdio.h>
#include<math.h>
#define N 4
double a[N+1]={1,2,3,4,5};
int b=0;
int k=10;
 double f;
int kaijo(int );
int touhi(int );
int fibonacci(int );
double hona(double ,int );
main(){
  int mx;
  mx=kaijo(10);
  printf("10! = %d\n",mx);
  int e;
  b=0;
  e=touhi(9);
  printf("2^0+2^1+2^2+...+2^9 = %d\n",e);
  int f;
  f=fibonacci(19);
  printf("fibonacci 20: %d\n",f);
  double g;
  g=hona(2,N);
  printf("f(2) = %.2f\n",g);
}
int kaijo(int n){

  if(n==0){
    return k;
  }else{
    k*=n;
    return kaijo(n-1);
  }
}
int touhi(int n){
  int c=1,i;
  if(n==0){
    b+=1;
    return b;
  }else{
    b+=pow(2,n);
  }
  return touhi(n-1);
}
int fibonacci(int n){
  int f;
  if(n==0||n==1){
    f=1;
  }else{
  f=fibonacci(n-1)+fibonacci(n-2);
  }
  return f;
}
double hona(double n,int j){
 
  if(j==0){
    return 1;
  }
  f=f+a[j];
  return hona(n,j-1)*n+a[j];
}


