#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main(int argc, char * argv)
{
  int i, n=0;
  fp = fopen("Number222.txt","r+");
  /*r —读文本文件的方式，如文件不存在，会打开失败 ：fp == NULL 
   r+ ——读写文本文件的方式，如果文件不存在，会打开失败：fp == NULL 
  */


  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }  
  
  printf("pos of file on open:%d\n",ftell(fp));
    //ftell(fp)获取文件的当前读写指针位置值
  
  fseek(fp,10,SEEK_SET );//SEEK_END, 设定文件读写指针位置
  printf("pos of file after fseek:%d\n",ftell(fp));
  for(i=0; i<5; i++)
  {
	if(fscanf(fp,"%d",&n) == 1)//读一个整数到n中
		printf("%d\n",n);//在屏幕输出显示n中读到的新值
	else
	    printf("Fail to read");
  }
  printf("pos of file after fscanf:%d\n",ftell(fp));  
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


