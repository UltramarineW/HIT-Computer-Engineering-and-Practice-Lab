/*编程题
题目内容：基于文件的矩阵计算——求鞍点

对于一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
你的任务是编程实现鞍点查找函数:
struct point FindSaddle(int *p, int n)

n为输入矩阵的大小,函数的返回值是结构体类型：
struct POS
{
   int  row;
   int  col;
}

输入格式:
从文本文件in.txt读入所有输入数据，该文件的第一行是矩阵的行数（读入到n中即可），随后是的每一行对应矩阵的一行，数值之间用空格分隔，形如：
4 
2 7 9 5 
4 8 7 6 
5 7 8 9
3 6 5 2 
对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
如果找不到，就输出
NO Saddle Point
题目所给的数据保证了不会出现多个鞍点。

输出样例：
3 1

【说明与提示】：不限定矩阵的大小，应该在读入n的数值后，用动态内存分配的方法创建数组。
输出格式：

正确的答案代码：
*/
#include <stdio.h>
#include <conio.h> 
 
struct point
{
	int row;
	int col;
};
struct point FindSaddle(int *p, int n);
int ReadArray(int **p);
int main()
{
  int *pArray=NULL;
  int n,i,j;
  struct point result;
  
  n = ReadArray(&pArray);
  OutputArray(pArray,n);
  exit(0);
  
  if( n > 0)
  {
	  result = FindSaddle(pArray,n);	  
	  if(result.col<0 || result.row<0) 
	     printf("NO Saddle Point");
	  else
	     printf("%d %d",result.row, result.col);
	     
	  free(pArray);    	
  }
  else
     printf("\nRead file fail!\n");

  return 0;
}

int ReadArray(int **pArray)
{
  int n,i,j;
  int *p;
  FILE *fp;
  
  fp = fopen("in.txt","r");
  if(fp == NULL)
     return -1;

  fscanf(fp,"%d,",&n);
  p = (int *)malloc(n*n*sizeof(int)) ;
  if( p== NULL )
    return -2;
  
  for(i=0;i<n;i++)
  { 
     for(j=0;j<n;j++)
        fscanf(fp,"%d,",&*(p+i*n+j));	
	
  } 
  *pArray = p;
  fclose(fp) ;
  return n; 
} 
int OutputArray(int *pArray,int n)
{
  int i,j;
  printf("n=%d\n",n);		
  for(i=0;i<n;i++)
  { 
     for(j=0;j<n;j++)
        printf("%d ,",*(pArray+i*n+j));	
	printf("\n");		
  } 
  return n; 
} 
struct point FindSaddle(int *p, int n)
{
	int i,j,iMaxRow,iMaxCol,k;
	int iFound=0;
	struct point result;
	result.col = -1;//表示没有鞍点 
	result.row = -1;//表示没有鞍点 
	
	i=0;
	while( !iFound && i<n)
	{
		//find the max value in row i
		iMaxRow = i;
		
		//在第i行找最大值，肯定有 
		iMaxCol = 0;
		for(j=1;j<n;j++)
	    {
		   if( *(p+i*n+j)> *(p+i*n+ iMaxCol)) 
		      iMaxCol = j;
		}
		
		//验证第i行找到的最大值，在iMaxCol列中是否最小：不一定成立 
		//先假设找到了
		iFound = 1; 
		for(j=0;j<n;j++) 
		{
		   if(*(p+j*n+ iMaxCol) <*(p+i*n+ iMaxCol))
		      iFound = 0;			
		}
		i++;
	}
	if( iFound )
	{
		result.col = iMaxCol;
		result.row = iMaxRow;
	}
	return result;	 
}
