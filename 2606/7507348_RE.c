#include<stdio.h>
#include<malloc.h>

struct	in {
	int		point;
	struct	in *next;
};

struct doub {
	double	K;
	int		sum;
	struct	in *next; 
};

struct doub	save[201];
int		count=0;


int		isIn(double k, int i, int j) {
	int		m, iused, jused; 
	struct	in *p;
	for(m=0; m<count; m++)
		if(k == save[m].K)   {

			p = save[m].next;
			iused = jused = 1;

			while(p) {
				if(p->point==i) iused = 0;
				else if(p->point==j) jused = 0;
				p = p->next;
			}

			if(iused==1) {
				p = (struct in *)malloc(sizeof(struct in));
				p->point = i;
				p->next = save[m].next;
				save[m].next = p;
			}
			if(jused==1) {
				p = (struct in *)malloc(sizeof(struct in));
				p->point = j;
				p->next = save[m].next;
				save[m].next = p;
			}

			save[m].sum += iused + jused;
			return 1;
		}

	save[count].sum += 2;
	save[count++].K = k;

	p = (struct in *)malloc(sizeof(struct in));
	p->point = i;
	p->next = save[m].next;
	save[m].next = p;

	p = (struct in *)malloc(sizeof(struct in));
	p->point = j;
	p->next = save[m].next;
	save[m].next = p;

	return -1;
}

int main() {
	int		i, j, max, x[201], y[201], n;
	double	k[201][201];
	while(scanf("%d", &n)!=EOF) {
		for(i=1; i<=n; i++)
			scanf("%d %d", &x[i], &y[i]);

		for(i=1; i<=n; i++)
			for(j=1; j<i; j++) {
				if(x[i]==x[j])		k[i][j] = 2147483647;
				else				k[i][j] = (double)(y[i] - y[j]) / (x[i] - x[j]);
			}

		for(i=1; i<=n; i++)
			for(j=1; j<i; j++) 
				isIn(k[i][j], i, j);


		for(i=0; i<count; i++)
			if(save[i].sum > max) max = save[i].sum;
		printf("%d\n", max);
	}

	return 1;
}