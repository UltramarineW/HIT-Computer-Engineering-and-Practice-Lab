#include<stdio.h>
#include<stdlib.h>
FILE *fp;
 
int main(int argc, char * argv)
{
  int i, n;
  int k[100];
  fp = fopen("Number.txt","r+");
  /*w����д�ı��ļ��ķ�ʽ�����ļ��Ѿ����ڣ����Զ������ԭ�����ݱ��0�ֽ�  
  a����׷���ı��ļ��ķ�ʽ�����ļ��Ѿ����ڣ����������Զ������ԭ�����ݱ��0�ֽ�  ��
                             ����ļ������ڣ��ᴴ���ļ� 
  r+ ������д�ı��ļ��ķ�ʽ������ļ������ڣ����ʧ�ܣ�fp == NULL 
  */
  
  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }
  printf("pos of file on open:%d\n",ftell(fp));
    
  fseek(fp,0,SEEK_END);//SEEK_SET );//SEEK_END, �趨�ļ���дָ��λ��

  printf("pos of file after fseek:%d\n",ftell(fp));
    
  for(i=0;i<100;i++)
  {
	  k[i] = i+i*i;
  }
  
  for(i=0; i<10; i++)
  {
	fprintf(fp,"%d ",i);
	//ע��%d�����и��ո����û�пո�򿪿�����������	�ڶ����ʱ��ᷢ��ʲô�أ� 
  }
 
  for(i=0; i<100; i++)
  {
	if( i%10==0 )
	     fprintf(fp,"\n");  
		 	
	fprintf(fp,"%d ",k[i]);//����Ҳֻ�����Ԫ��д���ļ�
   //ע��%d�����и��ո����û�пո�򿪿�����������	�ڶ����ʱ��ᷢ��ʲô�أ� 	
   
  }
  printf("pos of file after fprintf:%d\n",ftell(fp));
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


