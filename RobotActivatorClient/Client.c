/*
 * Client.c
 *
 *  Created on: 16 juin 2015
 *      Author: florian
 */

#include "Client.h"

int main(){

	//Initialisation du robot
	struct Robot r;
	r.etat=false;
	r.identification=-1;

	//Lancement du robot : choix de l'action
	puts("Lancement du Robot ...\n\n");
	int choix = -1;

	do{
		choix = afficherMenu();
		lancerAction(choix, r);
	}
	while(choix<1 || choix>4);

	return 0;
}

void lancerAction(int choix, struct Robot r){
	switch (choix){

	//Connexion au serveur
	case 1:
		break;
	//Deconnexion du serveur
	case 2:
		break;
	//Changer l'état du robot
	case 3:
		changerEtat(r);
		break;
	//Envoyer le changement d'état
	case 4:
		break;
	}
}

int afficherMenu(){

	int choix = 0;

	puts("\n--- Menu des fonctionnalités du robot ---\n");
	puts("\t 1- Connexion au serveur");
	puts("\t 2- Deconnexion du serveur");
	puts("\t 3- Changer l'état du robot");
	puts("\t 4- Envoyer l'état du robot au serveur");
	puts("\n\n");

	do{
		puts("Votre choix (1-4) :\t");
		scanf("%d", &choix);
	}
	while(choix < 1 || choix > 4);

	return choix;
}

void changerEtat(struct Robot r){
	if(r.etat==false)
		r.etat=true;
	else
		r.etat=false;
	puts("Changement d'état réalisé");
}


void connexionServeur(){

	/* Données de connexion au serveur */


}

void deconnexionServeur(){

}

void envoyer_etat(int etat){

}
