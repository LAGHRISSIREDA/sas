#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct voiture{
	char Model[20];
	int Year;
}Voiture;

void Remplir(Voiture *listVoiture,int nbr){
	int i;
	
		for(i=0;i<nbr;i++){
		printf("Voiture Num %d : \n",i+1);
		printf("Model : ");
		scanf("%s",listVoiture[i].Model);
		printf("Year  : ");
		scanf("%d",&listVoiture[i].Year);
	}
}



void Affichage(Voiture *listVoiture ,int nbr){
	int i;
		for(i=0;i<nbr;i++){
			printf("Voiture Num %d > Model : %s > %d \n ",i+1,listVoiture[i].Model,listVoiture[i].Year);
		}
}
int main(int argc, char *argv[]) {
	int nbr,i,nbr2;
	Voiture *listVoiture=NULL;
	
	printf("Donner le Nombre de Voiture : ");
	scanf("%d",&nbr);
	
	if(nbr>0){
		listVoiture = malloc(nbr*sizeof(Voiture));
			if(listVoiture == NULL)
				exit(0);
	}
	
		Remplir(listVoiture,nbr);
	
		printf("****************************************DSIPLAY*****************************************\n ");
		
		//Affichage
		Affichage(listVoiture,nbr);
	
	//***************************************************************************************************************************
	system("pause");
	system("cls");
	printf("Donner un autre Nombre de Voiture : ");
	scanf("%d",&nbr2);
	
	listVoiture = realloc(listVoiture,nbr2*sizeof(Voiture));
	//remplir
	Remplir(listVoiture,nbr2);
	
	printf("****************************************DSIPLAY*****************************************\n ");
	//Affichage
	Affichage(listVoiture,nbr2);
	
	free(listVoiture);
	return 0;
}


