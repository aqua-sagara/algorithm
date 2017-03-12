#include<stdio.h>
main()
{
  char c[]="PUDING";
  int i;
  for(i=0;i<6;i++){
    printf("%c:%d\n",c[i],(c[i]-'A'+1)%9);
  }
}
