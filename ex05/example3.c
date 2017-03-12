#include <stdio.h>
#include <sys/time.h>

int main(){
  int i,n,sum,j;
  hrtime_t start,finish;
  for(n=500;n<=10000;n=n+500){
  printf("%d ",n);
  start=gethrtime(); /* 計測開始 */

  sum=0;
 for( i=0; i<n; i++)
  for( j=0; j<i; j++) sum++;


  finish=gethrtime(); /* 計測終了 */
  printf("%f\n", (double)(finish-start)/NANOSEC);
  }

  return 0;
}
