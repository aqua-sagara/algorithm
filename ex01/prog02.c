/* s1220194 相楽 尚之 */
#include<stdio.h>
main()
{
  int a[9],sum;
  printf("Input ISBN:");
  scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]);
  sum=a[0]*1+a[1]*2+a[2]*3+a[3]*4+a[4]*5+a[5]*6+a[6]*7+a[7]*8+a[8]*9;
  printf("Check Number: %d\n",sum%11);
    }
