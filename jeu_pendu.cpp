#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#include"dico.h"
#include"dico.cpp"

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
int i = 0;
int bonneLettre = 0;

for (i = 0; motSecret[i] != '\0'; i++)
{
if (lettre == motSecret[i])
{
bonneLettre = 1;
motSecret[i] = 1;
}
}

return bonneLettre;
}

int gagne(int lettreTrouvee[], long tailleMot)
{
int i = 0;
int joueurGagne = 1;

for (i = 0; i < tailleMot; i++)
{
if (lettreTrouvee[i] == 0)
	joueurGagne = 0;
}

return joueurGagne;
}	

char lireCaractere()
{
char caractere = 0;

caractere = getchar();
caractere = toupper(caractere);

while(getchar() != '\n');

return caractere;
}

int main(int argc, char *argv[])
{
char lettre = 0;
char motSecret[100] = {0};
int *lettreTrouvee = NULL;
int coupsRestants = 10;
int i = 0;
int tailleMot = 0;

printf("Bienvenue dans le Pendu !\n\n");

if (!piocherMot(motSecret))
{
exit(0);
}
	
tailleMot = strlen(motSecret);

lettreTrouvee = (int*)malloc(tailleMot * sizeof(int));

if (lettreTrouvee == NULL)
	exit(0);
	
for (i = 0; i < tailleMot; i++)
	lettreTrouvee[i] = 0;		

while(coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
{
printf("\nVous etes %d coup à jouer", coupsRestants);
printf("\nmot secret : ");

for (i=0; i < tailleMot; i++)
{
if (lettreTrouvee[i])
	printf("%c",motSecret[i]);
else
	printf("*");
}

printf("\nPrposez une lettre : ");
lettre = lireCaractere();

if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
{
coupsRestants--;
}
}

if (gagne(lettreTrouvee, tailleMot))
	printf("\nGagne ! on trouve mot secret : %s",motSecret);
else
	printf("\nPerdu ! le mot secret est : %s\n",motSecret);
	
free(lettreTrouvee);				

return 0;
}
