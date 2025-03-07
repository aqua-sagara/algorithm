#include <limits.h>

#define MaxNum 100		/* 行列の個数の最大値 */
#define Infinity UINT_MAX	/* 無限大 */

/* ２つの数のうち小さい値を返す */
#define min(x,y) ((x) < (y) ? (x) : (y))

void tableprint(unsigned int table[][MaxNum], int n);

unsigned int m[MaxNum][MaxNum];	/* 表 */

int main()
{
  unsigned int p[MaxNum+1];	/* 次元の列 */
  int n, i, j, k, l;
  unsigned int q;

  /* 行列の個数の入力 */
  scanf("%d",&n);
  /* 次元の列の入力（列の長さは行列の個数より１だけ長い） */
  for (i=0; i<=n; i++)
    scanf("%d",&p[i]);

  /* 表 m の計算 */
  int x;

  for( j=0; j<n; j++ ) {
    k=j;
    for( i=0; i<n-j; i++ ) {
      if( i==k ) {
        m[i][k] = 0;
      } else if( (k-i)==1 ) {
          m[i][k] = p[i]*p[i+1]*p[i+2];
      } else {
        for( l=0; l<k-i; l++ ) {
          x = m[i][l+i]+m[(l+i)+1][k]+p[i]*p[(l+i)+1]*p[k+1];
          if( 0<l ) {
            if( x < m[i][k]) {
              m[i][k] = x;
            }
          } else {
            m[i][k] = x;
          }
        }
      }
      k++;
    }
  }
  /* ここにプログラムを追加 */

  /* 以下の行のコメントを外すと、表 m の内容の確認ができる */
  //tableprint(m,n);

  /* 行列チェーン乗算の最小コストの出力 */
  printf("the least cost = %d\n", m[0][n-1]);

}

/* 表の内容の出力 */
void tableprint(unsigned int table[][MaxNum], int n)
{
  int i, j;

  for (i=0; i<n; i++)  {
    for (j=i; j<n; j++)
      printf("%d ",table[i][j]);
    putchar('\n');
  }
}

