#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct trans {
	char	english[11];
	char	foreign[11];
}dict[100000];

int	total;

bool cmp(const struct trans a, const struct trans b) {
	for(int i=0; ; i++) {
		if(a.foreign[i]<b.foreign[i]) 
			return true;
		else if(a.foreign[i]>b.foreign[i])
			return false;
		if(a.foreign[i]=='\0')
			return true;
		else if(b.foreign[i]=='\0')
			return false;
	}
}

int binSearch(char *foreign) {
	int		low=0, high=total, mid=total/2;
	while(low<=high) {
		mid = (low + high) / 2;
		if(strcmp(foreign,dict[mid].foreign)==0)
			return	mid;
		if(strcmp(foreign,dict[mid].foreign)>0)
			low = mid+1;
		else if(strcmp(foreign,dict[mid].foreign)<0)
			high = mid-1;
	}
	return -1;
}


int main() {
	int		i = 0, end ;
	char	buff[50], foreign[11];
	
	total = 0;
	while( gets(buff) && strcmp(buff, "")!=0)	{
		sscanf( buff, "%s%s", dict[total].english, dict[total].foreign);
		total++;
	}

	sort(dict, dict+total, cmp);

	while(scanf("%s", foreign)!=EOF) {
		end = binSearch(foreign);
		if(end==-1)
			printf("eh\n");
		else
			printf("%s\n", dict[end].english);
	}

	return 0;
}