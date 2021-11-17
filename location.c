#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//enum
typedef enum etat{
	dispo,
	nonDispo
}Etat;

//structure
typedef struct voiture{
	int Model;
	char Matricule[10];
	int Kilometrage;
	Etat EtatVoiture;
}Voiture;

//fonction d remplissage

void Remplir(Voiture *voitures,int n){
	int nbr,i;
	for(i=0;i<n;i++){
		printf("Voiture Numero %d >>>>>>>>>\n",i+1);
		printf("Model : ");
		scanf("%d",&voitures[i].Model);
		printf("Matricule : ");
		scanf("%s",voitures[i].Matricule);
		printf("Kilometrage : ");
		scanf("%d",&voitures[i].Kilometrage);
		do{
		printf("Etat Voiture > \n 1 : Disp\n 2 : Non-Dispo\n");
		scanf("%d",&nbr);
			if(nbr == 1) voitures[i].EtatVoiture=dispo;
			else voitures[i].EtatVoiture=nonDispo;
		}while(nbr != 1 && nbr != 2);
	}
	
	printf("Le Remplissage est bien effectue \n");
}

// louer une voiture

int louer(char *matricule,Voiture *voitures,int n){
	int i ;
	
	for(i=0;i<n;i++){
		if(strcmp(voitures[i].Matricule,matricule)==0)
			{
				if(voitures[i].EtatVoiture == dispo){
					printf("La voiture est disponible !!! \n");
					printf("Model = %d \nMatricule : %s\nkilometrage : %d\n",voitures[i].Model,voitures[i].Matricule,voitures[i].Kilometrage,voitures[i].Kilometrage);
					return 1;
				}else{
					printf("La voiture est en location !!!\n");
					return 0;
				}
			}
		else
		{
			printf("Errroooooooooooooooooooooor\n");
			return -1;
			}	
	}
	
}

//menu

int menu(){
	int num;
	do{
	
		printf("1 : louer \n");
		printf("2 : Retour d'une Voiture \n");
		printf("3 : Etat d'une Voiture\n");
		printf("0 : Sauvegarder\n");
		printf("Votre Choix : ");
		scanf("%d",&num);
	}	while(num != 1 && num != 2 && num != 3 && num != 0);
			//test
			if(num == 0) return 0;
			else return num;
}

//retour d'une voiture

int retourVoiture(char *matricule,Voiture *voitures,int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(voitures[i].Matricule , matricule)==0){
			if(voitures[i].EtatVoiture==nonDispo){
				printf("Eeeuuuuuuuuuuur\n");
				return 404;
			}else{
				printf("Model = %d \nMatricule : %s\nkilometrage : %d\n",voitures[i].Model,voitures[i].Matricule,voitures[i].Kilometrage,voitures[i].Kilometrage);
				printf("Donner le nombre de kilometrage : ");
				scanf("%d",&voitures[i].Kilometrage);
				printf("Model = %d \nMatricule : %s\nkilometrage : %d\n",voitures[i].Model,voitures[i].Matricule,voitures[i].Kilometrage,voitures[i].Kilometrage);
				return 1;
		}
		}else{
			printf("La voitures n'existe pas \n");
			return 404;
		}
	}
}




//**********************************************Programme principal****************************************************
int main(int argc, char *argv[]) {
	char matri[10];
	Voiture *listVoiture = NULL;
	int n,option,lou;
		
		//nombre de voiture	
	printf("Donner Le nombre de Voiture : ");
	scanf("%d",&n);
		//test
			if(n>0){
				listVoiture=malloc(n*sizeof(Voiture));
					if(listVoiture == NULL)
						exit(0);
			}

	//appel du function Remplir
	
	Remplir(listVoiture,n);	
	system("pause");
	system("cls");	
	
	//Afficage d menu
	
	option=menu();	
	
	switch(option){
		case 1 :
				 printf("Donner le matricule du voiture : ");
				 scanf("%s",matri);
				 lou=louer(matri,listVoiture,n);
				 break;
		case 2 :
				 printf("Donner le matricule du voiture : ");
				 scanf("%s",matri);
				 lou=retourVoiture(matri,listVoiture,n);
				 break;	 
		case 3 :
				 
	}
					
	free(listVoiture);
	return 0;
}
