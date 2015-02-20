#include<stdio.h>
#include<string.h>

int main() {
	int		t,  i,  k,  p, alen,  blen;
	char	a[84], b[84], print[84];
	scanf("%d", &t);
	for(k=1; k<=t; k++) {
		scanf("%s %s", a, b);
		memset(print, '0', sizeof(print));
		alen = strlen(a)-1;
		blen = strlen(b)-1;
		for(i=0;;i++) {
			if(alen-i>=0 && blen-i>=0)
				p = a[alen-i]+b[blen-i]+print[i] - 144;
			else if(alen-i>=0)
				p = a[alen-i]+print[i] - 96;
			else if(blen-i>=0)
				p = b[blen-i]+print[i] - 96;
			else break;
			if(p>=2) print[i+1]='1';
			p %= 2;
			print[i] = p+48;
		}
		printf("%d ", k);
		for(;print[i]=='0';i--) ;
		i++;
		while(i--) {
			printf("%c", print[i]);
		}
		printf("\n");
			
	}
}