#include<stdio.h>
#include<string.h>

int main () {
	char	a;
	char	s[20];
	char	start[9]={"START"}, end[4]={"END"}, allend[11]={"ENDOFINPUT"};
	
	while(scanf("%s",s)) {
		if(strcmp(s,allend)==0) break;
		scanf("%c",&a);
		while(scanf("%c", &a) && a!=10) {
			if(a<='Z'&&a>='A') printf("%c", (a - 44 )%26 + 65);
			else printf("%c", a);
		}
		printf("\n");
		scanf("%s",s);
	}


	return 1;
}