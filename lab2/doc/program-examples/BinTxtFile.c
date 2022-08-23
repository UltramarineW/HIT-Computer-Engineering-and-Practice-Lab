#include<stdio.h>
#include<stdlib.h>
FILE *fp;

int main(int argc, char * argv)
{
  int i, n;
  fp = fopen("Number.dat","wb");
  

  if(fp==NULL) 
  {
  	printf("Can't open file\n");
    exit(1);
  }
  
  printf("pos of file on open:%d\n",ftell(fp));
  
  fseek(fp,0,SEEK_END);    
  for(i=0; i<10; i++)
  {
	printf("%d\n",scanf("%d",& n));   
	fwrite(&i, sizeof(int), 1, fp);
	//fprintf(fp,"%d",i);
	
  }
  fclose(fp);
  printf("Finish!\n");
  return 0;
}

