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
	r.estConnecte = false;

	//Lancement du robot : choix de l'action
	puts("Lancement du Robot ...\n\n");
	int choix = -1;
	bool state = false;

	do{
		choix = afficherMenu();
		state = lancerAction(choix, r);
	}
	while((choix<1 && choix>4) || continuer==true);

	return 0;
}

bool lancerAction(int choix, struct Robot r){
	bool state = false;

	switch (choix){

	//Connexion au serveur
	case 1:
		state = connexionServeur(r);
		break;

	//Deconnexion du serveur
	case 2:
		state = deconnexionServeur(r);
		break;

	//Changer l'état du robot
	case 3:
		changerEtat(r);
		state = true;
		break;

	//Envoyer le changement d'état
	case 4:
		state = envoyer_etat(r);
		break;

	//Quitter
	case 5:
		continuer = false;
		break;
	default:
		puts("Erreur dans le choix de l'action");
		state = false;
	}

	return state;
}

int afficherMenu(){

	int choix = 0;

	puts("\n--- Menu des fonctionnalités du robot ---\n");
	puts("\t 1- Connexion au serveur");
	puts("\t 2- Deconnexion du serveur");
	puts("\t 3- Changer l'état du robot");
	puts("\t 4- Envoyer l'état du robot au serveur");
	puts("\t 5- Quitter");
	puts("\n\n");

	do{
		puts("Votre choix (1-5) :\t");
		scanf("%d", &choix);
	}
	while(choix < 1 || choix > 5);

	return choix;
}

/**
 * Cette fonction permet de changer l'état d'un robot passé en paramètre
 * Un message est affiché à l'utilisateur
 */
void changerEtat(struct Robot r){
	if(r.etat==false)
		r.etat=true;
	else
		r.etat=false;
	puts("Changement d'état réalisé");
}


/*
 * Cette fonction permet au robot de se connecter sur le serveur
 *
 */
int connexionServeur(struct Robot r){
	/* Données de connexion au serveur */

	int sock = creationSocket(AF_INET, SOCK_STREAM, 0);
	int executionSock = 0;
	if(sock != -1){

		struct sockaddr_in sin;
		sin.sin_family = AF_INET; /* La famille du protocole */
		sin.sin_port = htons(2000); /* Le port au format reseau htons = Host To Network Short */
		struct in_addr sin_addr;
		sin_addr.s_addr = inet_addr("127.0.0.1"); /* Peut etre n'importe qu'elle adresse IP, 127.0.0.1 = localhost = Pc utilise */
		sin.sin_addr = sin_addr;

		/* Connect, connect prend en parametre la socket, la structure sockaddr_in qui doit etre convertie en sockaddr et la taille de sockaddr*/
		if(connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			return(errno);
		}

		//déclaration du message à envoyer
		char buffer[1024]= "robot connection";

		executionSock = write(sock, buffer, sizeof(buffer));

		/* Envoi buffer chez le serveur, write prend en parametre la socket, ce qui doit etre envoye et sa taille ) */
		if( executionSock == -1)
		{
			perror("write message in socket");
			return errno;
		}
	}
	else{
		return(errno);
	}
	close(sock);
	return executionSock;
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

int deconnexionServeur(struct Robot r){
	/* Données de connexion au serveur */

	int sock = creationSocket(AF_INET, SOCK_STREAM, 0);
	int executionSock = 0;
	if(sock != -1){

		struct sockaddr_in sin;
		sin.sin_family = AF_INET; /* La famille du protocole */
		sin.sin_port = htons(2000); /* Le port au format reseau htons = Host To Network Short */
		struct in_addr sin_addr;
		sin_addr.s_addr = inet_addr("127.0.0.1"); /* Peut etre n'importe qu'elle adresse IP, 127.0.0.1 = localhost = Pc utilise */
		sin.sin_addr = sin_addr;

		/* Connect, connect prend en parametre la socket, la structure sockaddr_in qui doit etre convertis en sockaddr et la taille de sockaddr*/
		if(connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			return(errno);
		}

		//déclaration du message à envoyer
		char buffer[1024]= "robot deconnection";

		executionSock = write(sock, buffer, sizeof(buffer));

		/* Envoi buffer chez le serveur, write prend en parametre la socket, ce qui doit etre envoye et sa taille ) */
		if( executionSock == -1)
		{
			perror("write message in socket");
			return errno;
		}
	}
	else{
		return(errno);
	}
	close(sock);
	return executionSock;
}

int envoyer_etat(struct Robot r){
	/* Données de connexion au serveur */

	int sock = creationSocket(AF_INET, SOCK_STREAM, 0);
	int executionSock = 0;
	if(sock != -1){

		struct sockaddr_in sin;
		sin.sin_family = AF_INET; /* La famille du protocole */
		sin.sin_port = htons(2000); /* Le port au format reseau htons = Host To Network Short */
		struct in_addr sin_addr;
		sin_addr.s_addr = inet_addr("127.0.0.1"); /* Peut etre n'importe qu'elle adresse IP, 127.0.0.1 = localhost = Pc utilise */
		sin.sin_addr = sin_addr;

		/* Connect, connect prend en parametre la socket, la structure sockaddr_in qui doit etre convertis en sockaddr et la taille de sockaddr*/
		if(connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			return(errno);
		}

		//déclaration du message à envoyer
		char buffer[1024]= "send state";

		executionSock = write(sock, buffer, sizeof(buffer));

		/* Envoi buffer chez le serveur, write prend en parametre la socket, ce qui doit etre envoye et sa taille ) */
		if( executionSock == -1)
		{
			perror("write message in socket");
			return errno;
		}
	}
	else{
		return(errno);
	}
	close(sock);
	return executionSock;
}
