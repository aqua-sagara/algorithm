#include<stdio.h>
main()
{
  int sum=0,sum2=0;
  int i,j,k,n=100;
  for(i=0;i<n;i++){sum2=0;
    for(j=0;j<i;j++){sum2++;
      sum++;
  printf("%d\n",sum2);
    }
  }
  printf("%d\n",sum);

}
