#include <stdio.h>

int main()	{
	int flag = 0;
	char c;
	while( ( c = getchar() ) != EOF )	{
		if( c == '"' && flag == 0 )	{
			printf( "``" );
			flag = 1;
		}
		else if( c == '"' && flag == 1 )	{
			printf( "\'\'" );
			flag = 0;
		}
		else putchar( c );
	}
	return 0;
}