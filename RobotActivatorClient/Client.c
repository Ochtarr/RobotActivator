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
		connexionServeur(r);
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


int connexionServeur(struct Robot r){
	/* Données de connexion au serveur */
	struct sockaddr_in sin;
	sin.sin_family = AF_INET; /* La famille du protocole */
	sin.sin_port = htons(2000); /* Le port au format reseau htons = Host To Network Short */
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Peut etre n'importe qu'elle adresse IP, 127.0.0.1 = localhost = Pc utilise */

	int sock = creationSocket(AF_INET, SOCK_STREAM, 0);
	if(sock != -1){
		/* Connect, connect prend en parametre la socket, la structure sockaddr_in qui doit etre convertis en sockaddr et la taille de sockaddr*/
		if(connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			return(errno);
		}

		//déclaration du message à envoyer
		char buffer[1024]= "robot connection";

		/* Envoi buffer chez le serveur, write prend en parametre la socket, ce qui doit etre envoye et sa taille ) */
		if(write(sock, buffer, sizeof(buffer)) == -1)
		{
			perror("write message in socket");
			return errno;
		}

	}
	else{
		return(errno);
	}
	close(sock);
}

/*
	Cree une socket
	parametre le domaine, le type et le protocole
	retourne un type errno
*/
int creationSocket(int domaine, int type, int protocol){
	int sock = socket(domaine, type, protocol);
	if(sock == -1)
	{
		perror("socket");
		return errno;
	}
	return sock;
}

void deconnexionServeur(){

}

void envoyer_etat(int etat){

}
