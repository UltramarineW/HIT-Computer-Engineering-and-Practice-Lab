#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main(int argc, char * argv)
{
  int i, n=0,k[100];
  fp = fopen("Number.dat","rb");
  /*rb �����������ļ��ķ�ʽ�����ļ������ڣ����ʧ�� ��fp == NULL 
   rb+ ������д�������ı��ļ��ķ�ʽ������ļ������ڣ����ʧ�ܣ�fp == NULL 
  */

  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }  
  
  printf("pos of file on open:%d\n",ftell(fp));
    //ftell(fp)��ȡ�ļ��ĵ�ǰ��дָ��λ��ֵ
  
  fseek(fp,0,SEEK_SET );//SEEK_END, �趨�ļ���дָ��λ��
  printf("pos of file after fseek:%d\n",ftell(fp));
  for(i=0; i<10; i++)
  {
	if(fread(&n,sizeof(int),1,fp) == 1)//��һ��������n��
		printf("%d\n",n);//����Ļ�����ʾn�ж�������ֵ
	else
	    printf("Fail to read");
  }
  fread(k, sizeof(int), 100, fp);
  
  printf("pos of file after fscanf:%d\n",ftell(fp));  
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


