#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char	judge[263000];

struct clock {
	char	time[10];
	char	flag[10];
	struct	clock *next;
};

int change(char *flag) {
	int		num=0, i;
	for(i=0; i<9; i++)
		num = num*4 + flag[i]-48;
	return num;
}

void plus(int a,char *clo) {
	if( clo[a]=='3' )	clo[a]='0';
	else	clo[a] += 1;
}


void move(int i, char *clo) {
	if(i==1)	  {plus(0,clo);plus(1,clo);plus(3,clo);plus(4,clo);}
	else if(i==2) {plus(0,clo);plus(1,clo);plus(2,clo);}
	else if(i==3) {plus(1,clo);plus(2,clo);plus(4,clo);plus(5,clo);}
	else if(i==4) {plus(0,clo);plus(3,clo);plus(6,clo);}
	else if(i==5) {plus(1,clo);plus(3,clo);plus(4,clo);plus(5,clo);plus(7,clo);}
	else if(i==6) {plus(2,clo);plus(5,clo);plus(8,clo);}
	else if(i==7) {plus(3,clo);plus(4,clo);plus(6,clo);plus(7,clo);}
	else if(i==8) {plus(6,clo);plus(7,clo);plus(8,clo);}
	else if(i==9) {plus(4,clo);plus(5,clo);plus(7,clo);plus(8,clo);}
}


main () {
    int		i, j, kk=0;
	char	newclo[10], clo[10];
	struct clock	*start, *Q, *u, *Qend, *p, *help;
	
	memset(judge,'0',sizeof(judge));
	judge[0] = '1';
	start = (struct clock *)malloc(sizeof(struct clock));
	start->next = NULL;
	Q = Qend = start;
	for(i=0; i<9; i++) 
		start->flag[i] = '0';
	start->flag[9] = '\0';
	
	for(i=0; i<9; i++) {
		scanf("%d", &j);
		if(j==1)	  start->time[i]='0';
		else if(j==2) start->time[i]='1';
		else if(j==3) start->time[i]='2';
		else		  start->time[i]='3';
	}
	start->time[9] = '\0';

	help = (struct clock *)malloc(sizeof(struct clock));

	while(Q!=NULL) {
		u = Q;
		
		strcpy(clo,u->time);

		for(i=1; i<=9; i++) {

			

			if(u->flag[i-1]>='3') continue;

			for(j=0; j<10; j++)
				help->flag[j] = u->flag[j];

			help->flag[i-1] = u->flag[i-1] + 1;

			if(judge[ change(help->flag) ]=='1') continue;

			judge[ change(help->flag) ] = '1';


			strcpy(newclo, clo);
			move(i, newclo);

			if(strcmp(newclo,"333333333")==0) {
				Q->next = NULL;
				break;
			}

			else {
				p = (struct clock *)malloc(sizeof(struct clock));
				for(j=0; j<10; j++)
					p->flag[j] = help->flag[j];

				strcpy(p->time, newclo);				
				p->next = NULL;

				Qend->next = p;
				Qend = p;
			}
		}
		Q = Q->next;
	}
	
	for(i=0; i<9; ) {
		if(help->flag[i]!='0')	{
			if(kk==0) {
				printf ("%d", i+1);
				kk=1;
			}
			else {
				printf (" %d", i+1);
			}
			help->flag[i]--;
		}
		else i++;
	}
	printf("\n");
    exit (0);
}
