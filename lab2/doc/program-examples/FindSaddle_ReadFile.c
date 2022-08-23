/*�����
��Ŀ���ݣ������ļ��ľ�����㡪���󰰵�

����һ��n*n����A������A�İ�����һ��λ�ã�i��j�����ڸ�λ���ϵ�Ԫ���ǵ�i���ϵ����������j���ϵ���С����һ������AҲ����û�а��㡣
��������Ǳ��ʵ�ְ�����Һ���:
struct point FindSaddle(int *p, int n)

nΪ�������Ĵ�С,�����ķ���ֵ�ǽṹ�����ͣ�
struct POS
{
   int  row;
   int  col;
}

�����ʽ:
���ı��ļ�in.txt���������������ݣ����ļ��ĵ�һ���Ǿ�������������뵽n�м��ɣ�������ǵ�ÿһ�ж�Ӧ�����һ�У���ֵ֮���ÿո�ָ������磺
4 
2 7 9 5 
4 8 7 6 
5 7 8 9
3 6 5 2 
������ľ�������ҵ����㣬��������±ꡣ�±�Ϊ�������֣���һ���������кţ��ڶ����������кţ�����0��ʼ������
����Ҳ����������
NO Saddle Point
��Ŀ���������ݱ�֤�˲�����ֶ�����㡣

���������
3 1

��˵������ʾ�������޶�����Ĵ�С��Ӧ���ڶ���n����ֵ���ö�̬�ڴ����ķ����������顣
�����ʽ��

��ȷ�Ĵ𰸴��룺
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
	result.col = -1;//��ʾû�а��� 
	result.row = -1;//��ʾû�а��� 
	
	i=0;
	while( !iFound && i<n)
	{
		//find the max value in row i
		iMaxRow = i;
		
		//�ڵ�i�������ֵ���϶��� 
		iMaxCol = 0;
		for(j=1;j<n;j++)
	    {
		   if( *(p+i*n+j)> *(p+i*n+ iMaxCol)) 
		      iMaxCol = j;
		}
		
		//��֤��i���ҵ������ֵ����iMaxCol�����Ƿ���С����һ������ 
		//�ȼ����ҵ���
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
