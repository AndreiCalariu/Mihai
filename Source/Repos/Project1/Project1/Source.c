#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
	int an;
	int durata;
	char titlu[50];
	char categorie[50];
	char premii[3];

}film;
film vector[100];



void main()
{
	FILE *fb;
	fb = fopen("filme.txt", "r");

	if (fb == NULL)
	{
		printf("Eroare");
		exit(1);
	}

	char *p;
	char buffer[100];
	fgets(buffer, 100, fb);
	int i, k = 0;
	while (fgets(buffer, 100, fb) != NULL)
	{
		i = 0;
		p = strtok(buffer, "\t");
		while (p != NULL)
		{
			if (i == 0)
				vector[k].an = atoi(p);
			if (i == 1)
				vector[k].durata = atoi(p);
			if (i == 2)
				strcpy(vector[k].titlu, p);
			if (i == 3)
				strcpy(vector[k].categorie, p);
			if (i == 4)
			{
				strcpy(vector[k].premii, p);
				break;
			}
			i++;
			p = strtok(NULL, "\t");
		}
		k++;
	}


	for (int j = 0; j < k; j++)
		printf("%d%d%s%s%s", vector[j].an, vector[j].durata, vector[j].titlu, vector[j].categorie, vector[j].premii);
}
