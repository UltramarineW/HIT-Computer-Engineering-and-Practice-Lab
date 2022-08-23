#include<stdio.h>
#include<stdlib.h>
FILE *fp;
 
int main(int argc, char * argv)
{
  int i, n;
  int k[100];
  fp = fopen("Number.dat","wb");
  /*wb——写二进制文件的方式，如文件已经存在，会自动先清除原有内容变成0字节  
  ab——追加二进制文件的方式，如文件已经存在，【不】会自动先清除原有内容变成0字节  ‘
                            如果文件不存在，会创建文件 
  rb+ ——读写二进制文件的方式，如果文件不存在，会打开失败：fp == NULL 
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


