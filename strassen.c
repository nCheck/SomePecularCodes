#include <stdio.h>
#include <malloc.h>


void getInput(int n , int **a)  //Taking Input
{
int i , j;
for( i = 0 ; i < n ; i++)
  {
    for( j = 0 ; j < n ; j++ )
      scanf("%d" , &a[i][j]);
  }
}

void giveOutput(int n , int **a)  //Giving Output
{
int i , j;
for( i = 0 ; i < n ; i++)
  {
    for( j = 0 ; j < n ; j++ )
      printf("%d " , a[i][j]);
    printf("\n");
  }
}

int **add(int **a , int **b , int n)  //Adding Two Mat of Order n
{
  int i , j;
  int **sum = (int **)malloc(64 *sizeof(int*));

  for( i = 0 ; i < 64 ; i++)
  sum[i] = (int *)malloc(sizeof(int*));

  for( i = 0 ; i < n ; i++)
  {
    for( j = 0 ; j < n ; j++)
      sum[i][j] = a[i][j] + b[i][j];
  }
  return sum;
}

int **sub(int **a , int **b , int n )   //Subtracting Two Mat ; ;
{
  int i , j;


  int **sum = (int **)malloc(64 *sizeof(int*));

  for( i = 0 ; i < 64 ; i++)
  sum[i] = (int *)malloc(sizeof(int*));

  for( i = 0 ; i < n ; i++)
  {
    for( j = 0 ; j < n ; j++)
      sum[i][j] = a[i][j] - b[i][j];
  }
  return sum ;
}


//Creating Copy of a part from Mat
//i.e extracting A , B , C , D , E ,F ,G ,H
/*
i.e from
3 2 | 1 2
1 2 | 2 2
- - - - - 
2 2 | 1 2
3 2 | 1 2

taking  1 2 , storing it and returning it.
        1 2
        (depending on i and j sent)

*/
void copy(int i1 , int j1 , int i2 , int j2 ,int **a , int **b)
{
  int i , j , k , l = 0;
  for(i = i1 ; i < i2 ; i++)
  {
    k = 0;
    for(j = j1 ; j < j2 ; j++)
    {
      a[l][k] = b[i][j];
      k++;
    }
    l++;
  }

}


/*
This copy is for storing and calculations of 
p1 , p2 ... p7 in respective side of matrices
and returning it.
*/

void copy2(int i1 , int j1 , int **a , int **b, int n)
{
  int i , j , k , l = 0;
  for(i = i1 ; i < i1+n ; i++)
  {
    k = 0;
    for(j = j1 ; j < j1+n ; j++)
    {
      a[i][j] = b[l][k];
      k++;
    }
    l++;
  }

}


/*
mul func takes starting index and order of matrices
to be multplied.
if n = 2
  normal integer formula is applied
else
  matrices are broken down to 4 parts
*/

int **mul(int **a , int **b , int l , int r , int n)
{
  if(n<=2)
  {
  int p1 , p2 , p3 , p4 , p5 , p6 , p7 ;
  int A , B , C , D , E , F , G , H;
  A = a[0][0];
  B = a[0][1];
  C = a[1][0];
  D = a[1][1];
  E = b[0][0];
  F = b[0][1];
  G = b[1][0];
  H = b[1][1];
  p1 = A*(F-H);
  p2 = (A+B)*H;
  p3 = (C+D)*E;
  p4 = D*(G-E);
  p5 = (A+D)*(E+H);
  p6 = (B-D)*(G+H);
  p7 = (A-C)*(E+F);


  int **res = (int **)malloc(64 *sizeof(int*));
  int i;
  for( i = 0 ; i < 64 ; i++)
  res[i] = (int *)malloc(sizeof(int*));

  res [0][0] = p6+p5+p4-p2;
  res [0][1] =  p1+p2;
  res [1][0] = p3+p4;
  res [1][1] = p1+p5-p3-p7;
  return res ;
  }
  else
  {
  int i;
  
  int **A = (int **)malloc(64 *sizeof(int*));
  int **B = (int **)malloc(64 *sizeof(int*));
  int **C = (int **)malloc(64 *sizeof(int*));
  int **D = (int **)malloc(64 *sizeof(int*));
  int **E = (int **)malloc(64 *sizeof(int*));
  int **F = (int **)malloc(64 *sizeof(int*));
  int **G = (int **)malloc(64 *sizeof(int*));
  int **H = (int **)malloc(64 *sizeof(int*));
  
  int **p1 = (int **)malloc(64 *sizeof(int*));
  int **p2 = (int **)malloc(64 *sizeof(int*));
  int **p3 = (int **)malloc(64 *sizeof(int*));
  int **p4 = (int **)malloc(64 *sizeof(int*));
  int **p5 = (int **)malloc(64 *sizeof(int*));
  int **p6 = (int **)malloc(64 *sizeof(int*));
  int **p7 = (int **)malloc(64 *sizeof(int*));
  
  int **ans1 = (int **)malloc(64 *sizeof(int*));
  int **ans2 = (int **)malloc(64 *sizeof(int*));
  int **ans3 = (int **)malloc(64 *sizeof(int*));
  int **ans4 = (int **)malloc(64 *sizeof(int*));

    for( i = 0 ; i < 64 ; i++)
    {
      A[i] = (int *)malloc(sizeof(int*));
      B[i] = (int *)malloc(sizeof(int*));
      C[i] = (int *)malloc(sizeof(int*));
      D[i] = (int *)malloc(sizeof(int*));
      E[i] = (int *)malloc(sizeof(int*));
      F[i] = (int *)malloc(sizeof(int*));
      G[i] = (int *)malloc(sizeof(int*));
      H[i] = (int *)malloc(sizeof(int*));
      
      p1[i] = (int *)malloc(sizeof(int*));
      p2[i] = (int *)malloc(sizeof(int*));
      p3[i] = (int *)malloc(sizeof(int*));
      p4[i] = (int *)malloc(sizeof(int*));
      p5[i] = (int *)malloc(sizeof(int*));
      p6[i] = (int *)malloc(sizeof(int*));
      p7[i] = (int *)malloc(sizeof(int*));
      
      ans1[i] = (int *)malloc(sizeof(int*));
      ans2[i] = (int *)malloc(sizeof(int*));
      ans3[i] = (int *)malloc(sizeof(int*));
      ans4[i] = (int *)malloc(sizeof(int*));
    }

  
  // DIVIDE
  
  n = n/2;
  copy(l , r , l+ n  , r+n , A , a);
  copy(l , r + n , l + n , r + 2*n , B , a);
  copy(l + n , r , l + 2*n , r + n , C , a);
  copy(l + n , r + n , l + 2*n , r + 2*n , D , a);

  copy(l , r , l+ n  , r+n , E , b);
  copy(l , r + n , l + n , r + 2*n , F , b);
  copy(l + n , r , l + 2*n , r + n , G , b);
  copy(l + n , r + n , l + 2*n , r + 2*n , H , b);
  
  p1 = mul( A , sub(F,H , n) , 0 , 0 , n);
  p2 = mul(add(A, B , n) , H , 0 , 0 , n);  
  p3 = mul(add(C , D , n) , E, 0 , 0 , n);
  p4 = mul( D , sub(G,E,n), 0 , 0 , n);
  p5 = mul(add(A , D,n) , add(E , H,n) , 0 , 0 , n);  
  p6 = mul( sub(B , D,n) , add(G , H,n) , 0 , 0 , n);  
  p7 = mul(sub(A , C,n) , add(E , F,n) , 0 , 0 , n);


  //Conquer
  
  ans1 = add(add(p6 , p5,n) , sub(p4 , p2,n) , n);
  ans2 = add(p1 , p2 ,n);
  ans3 = add(p3 , p4 ,n);
  ans4 = sub(add(p1 , p5 ,n) ,add(p3 , p7 ,n) , n);
  
  // Storing the answers
  copy2(l , r , A , ans1 , n);
  copy2(l , r+n , A  , ans2 , n);
  copy2(l+n , r , A  , ans3 , n);
  copy2(l+n , r+n , A  , ans4 , n);
  
  return A;
  }
}


int main()
{
int n , i , realn ,m;
printf("enter n\n");
scanf("%d" , &n );

int order[6] = { 2 , 4 , 8 , 16 , 32 , 64 };
//To make matrice easily divisible to 4 parts
for(i = 6 ; i > -1 ; i--)
{
  if(n <= order[i]) //Checking nearest order
    m = order[i];
}

int **a = (int **)malloc(n *sizeof(int*));
int **b = (int **)malloc(n *sizeof(int*));
int **res = (int **)malloc(n *sizeof(int*));

for( i = 0 ; i < 64 ; i++)
    {
      a[i] = (int *)malloc(sizeof(int*));
      b[i] = (int *)malloc(sizeof(int*));
      res[i] = (int *)malloc(sizeof(int*));
    }

printf("Enter Mat-1\n");
getInput( n , a);
printf("Enter Mat-2\n");
getInput( n , b);

realn = n;
n = m; //Changin order

res = mul(a , b , 0 , 0 , n);

n = realn;
printf("your output\n");
giveOutput(n , res);

}


/*
Some test cases to try:

1 2 1 1
2 1 1 1
1 1 1 2
0 0 0 1

0 1 0 1
1 1 1 1
0 0 0 0
2 1 2 1


1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
8 8 8 8 8 8 8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1


1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1


1 1 1 1 1 1 
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/
