#include<bits/stdc++.h>
using namespace std;
int main()

{
	int i, n, ch;
	char input[20];
	FILE *in;
	printf("\n\t\t Stop and Wait Protocol \n");
	printf("\n 1. Send \n2. Check ACK\n3.EOT\n");
	while(1)
	{
		printf("Enter your choice….");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
		in = fopen("data.txt", "w");
		printf("Enter the Data:");
		scanf("%s", input);
		n = strlen(input);
		for(i=0; i<n+1; i++)
		fprintf(in, "%s", input);
		fclose(in);
		printf("——->Data Sent\n");
		break;
		}
	}
}

