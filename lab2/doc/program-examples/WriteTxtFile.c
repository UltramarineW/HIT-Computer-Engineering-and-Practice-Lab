#include<stdio.h>
#include<stdlib.h>
FILE *fp;
 
int main(int argc, char * argv)
{
  int i, n;
  int k[100];
  fp = fopen("Number.txt","r+");
  /*w——写文本文件的方式，如文件已经存在，会自动先清除原有内容变成0字节  
  a——追加文本文件的方式，如文件已经存在，【不】会自动先清除原有内容变成0字节  ‘
                             如果文件不存在，会创建文件 
  r+ ——读写文本文件的方式，如果文件不存在，会打开失败：fp == NULL 
  */
  
  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }
  printf("pos of file on open:%d\n",ftell(fp));
    
  fseek(fp,0,SEEK_END);//SEEK_SET );//SEEK_END, 设定文件读写指针位置

  printf("pos of file after fseek:%d\n",ftell(fp));
    
  for(i=0;i<100;i++)
  {
	  k[i] = i+i*i;
  }
  
  for(i=0; i<10; i++)
  {
	fprintf(fp,"%d ",i);
	//注意%d后面有个空格，如果没有空格打开看看会怎样？	在读入的时候会发生什么呢？ 
  }
 
  for(i=0; i<100; i++)
  {
	if( i%10==0 )
	     fprintf(fp,"\n");  
		 	
	fprintf(fp,"%d ",k[i]);//数组也只能逐个元素写入文件
   //注意%d后面有个空格，如果没有空格打开看看会怎样？	在读入的时候会发生什么呢？ 	
   
  }
  printf("pos of file after fprintf:%d\n",ftell(fp));
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


