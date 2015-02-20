#include<stdio.h>

struct person {
	char	name[17];
	int		next;
	int		pre;
};

int	main () {
	int		n, w, s, next, i;
	struct person save[65];
		
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%s", save[i].name);
		save[i].next = i+1;
		save[i].pre = i-1;
	}
	save[n].next = 1;
	save[1].pre  = n;
	scanf("%d,%d", &w, &s);

	while(n--) {
		for(i=1; i<s; i++)
			w = save[w].next;
		printf("%s\n", save[w].name);

		save[save[w].pre].next = save[w].next;
		w = save[w].next;
	}

	return 1;
}