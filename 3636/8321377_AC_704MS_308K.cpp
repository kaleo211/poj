#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
	int length;
	int	weight;
};
node	stict[20000];

bool cmp(node a, node b) {
	if(a.length != b.length)
		return a.length<b.length?true:false;
	return a.weight>b.weight?true:false;
}

int main() {
	int		t, i, j, n;
	bool	visit[20000];

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d %d", &stict[i].length, &stict[i].weight);

		sort(stict,stict+n,cmp);
		memset(visit, 0, sizeof(visit));

		int count = 0;

		for(i=0; i<n; i++) {
			if(visit[i]) continue;
			count++;
			int	length=0, weight=0;
			for(j=i; j<n; j++) 
				if( (stict[j].length > length)  &&  (stict[j].weight > weight) && !visit[j]) {
					visit[j] = 1;
					length = stict[j].length;
					weight = stict[j].weight;
				}
		}
		printf("%d\n", count);
	}
	return 0;
}