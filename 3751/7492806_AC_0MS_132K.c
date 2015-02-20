#include<stdio.h>

int main() {
	int		t;
	int		year, month, day, hour, minute, second;
	char	fla;

	scanf("%d", &t);

	while(t--) {
		scanf("%d/%d/%d-%d:%d:%d", &year, &month, &day, &hour, &minute, &second);

		if(hour>=12) {
			hour -= 12;
			fla = 'p';
		}
		else {
			fla = 'a';
		}
		if(hour==0) hour = 12;

		if(month<10) printf("0%d/",month);
		else printf("%d/",month);

		if(day<10) printf("0%d/",day);
		else printf("%d/", day);
	
		if(year>999) printf("%d-", year);
		else if(year<1000 && year>99) printf("0%d-", year);
		else if(year<100 && year>9) printf("00%d-", year);
		else if(year<10) printf("000%d-", year);
		
		if(hour<10) printf("0%d:",hour);
		else printf("%d:", hour);

		if(minute<10) printf("0%d:",minute);
		else printf("%d:", minute);

		if(second<10) printf("0%d",second);
		else printf("%d", second);

		if(fla=='a') printf("am\n");
		else printf("pm\n");
	}
	return 1;
}