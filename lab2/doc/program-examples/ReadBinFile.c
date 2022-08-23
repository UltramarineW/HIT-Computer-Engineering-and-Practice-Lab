#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main(int argc, char * argv)
{
  int i, n=0,k[100];
  fp = fopen("Number.dat","rb");
  /*rb —读二进制文件的方式，如文件不存在，会打开失败 ：fp == NULL 
   rb+ ——读写二进制文本文件的方式，如果文件不存在，会打开失败：fp == NULL 
  */

  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }  
  
  printf("pos of file on open:%d\n",ftell(fp));
    //ftell(fp)获取文件的当前读写指针位置值
  
  fseek(fp,0,SEEK_SET );//SEEK_END, 设定文件读写指针位置
  printf("pos of file after fseek:%d\n",ftell(fp));
  for(i=0; i<10; i++)
  {
	if(fread(&n,sizeof(int),1,fp) == 1)//读一个整数到n中
		printf("%d\n",n);//在屏幕输出显示n中读到的新值
	else
	    printf("Fail to read");
  }
  fread(k, sizeof(int), 100, fp);
  
  printf("pos of file after fscanf:%d\n",ftell(fp));  
  fclose(fp);
  printf("Finish!\n");
  return 0;
}


