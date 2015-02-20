#include<stdio.h>

int main() {
  char isbn[12];
  int i, mark, sum, fla;
  while(scanf("%s",isbn)!=EOF) {
     for(sum=0,fla=0,i=0;i<10;i++)	{
        if(isbn[i]!='?')	{
            if(isbn[i]=='X') sum=sum+(isbn[i]-78)*(10-i);
            else sum=sum+(isbn[i]-48)*(10-i);
        }
        else mark=10-i;
     }
    if(mark==1)
        for(i=0;i<=10;i++)	{
          if((sum+i)%11==0) {
              if(i==10) printf("X\n");
              else printf("%d\n",i);
              fla=1;
              break;
          }
        }
    else
        for(i=0;i<=9;i++)	{
          if((sum+i*mark)%11==0)	{
              printf("%d\n",i);
              fla=1;
              break;
          }
        }
     if(fla==0) printf("-1\n");
  }
 return 0;
}