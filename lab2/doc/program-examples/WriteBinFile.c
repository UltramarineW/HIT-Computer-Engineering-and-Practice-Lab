#include<stdio.h>
#include<stdlib.h>
FILE *fp;
 
int main(int argc, char * argv)
{
  int i, n;
  int k[100];
  fp = fopen("Number.dat","wb");
  /*wb����д�������ļ��ķ�ʽ�����ļ��Ѿ����ڣ����Զ������ԭ�����ݱ��0�ֽ�  
  ab����׷�Ӷ������ļ��ķ�ʽ�����ļ��Ѿ����ڣ����������Զ������ԭ�����ݱ��0�ֽ�  ��
                            ����ļ������ڣ��ᴴ���ļ� 
  rb+ ������д�������ļ��ķ�ʽ������ļ������ڣ����ʧ�ܣ�fp == NULL 
  */
  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }
  for(i=0;i<100;i++)
  {
	  k[i] = i+i*i;
  }
  
  for(i=0; i<10; i++)
  {
	 fwrite(&i, sizeof(int), 1, fp);
  }
  fwrite(k, sizeof(int), 100, fp);
  
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


