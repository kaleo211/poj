#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
	int length;
	int	weight;
};
node	stict[5000];

bool cmp(node a, node b) {
	if(a.length != b.length)
		return a.length<b.length?true:false;
	return a.weight<b.weight?true:false;
}

int main() {
	int		t, i, j, n;
	bool	visit[5000];

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d %d", &stict[i].length, &stict[i].weight);

		sort(stict,stict+n,cmp);
		memset(visit, 0, sizeof(visit));

		int count = 0;

		for(i=0; i<n; i++) {
			if(visit[i])
				continue;
			visit[i] = 1;
			count++;
			for(j=i+1; j<n; j++) {
				if(visit[j]) continue;
				if( (stict[j-1].length <= stict[j].length)  &&  (stict[j-1].weight <= stict[j].weight) )
					visit[j] = 1;
				else
					break;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}