#include<stdio.h>
int main()
{
 int t, a1, a2, a3, a4;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
  if(a2-a1==a3-a2&&a2-a1==a4-a3) printf("%d %d %d %d %d\n",a1,a2,a3,a4,2*a4-a3);
  else printf("%d %d %d %d %d\n",a1,a2,a3,a4,a4*a4/a3);
 }
 return 0;
}
