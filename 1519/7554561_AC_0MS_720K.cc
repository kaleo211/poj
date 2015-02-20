#include <iostream>
#include <string.h>
 
using namespace std;
 
int main()
{
	int root;
	string n;
	while(1)
	{
		cin >> n;
		if (n == "0") break;
 
		root = 0;
		for (int i = 0; i < n.length(); i++)
		{
			root += n[i] - '0';
		}
 
		root %= 9;
 
		cout << (root == 0 ? 9 : root) << endl;
	}
	//system("pause");
	return 0;
}