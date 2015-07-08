/*
 * Client.h
 *
 *  Created on: 16 juin 2015
 *
 *  Author: florian
 *
 *  Summary : Client Robot
 *  - peut se connecter et se déconnecter à un serveur sur la meme machine
 *  - peut modifier son etat
 *  - peut envoyer son etat au serveur
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <poll.h>
#include <errno.h>

/*
 * ---------------------------------------
 * 		DEFINITION
 * ---------------------------------------
 */

#define bool int
#define true 1
#define false 0

/*
 * ---------------------------------------
 * 		STRUCTURE ROBOT
 * ---------------------------------------
 */

struct Robot{
	bool etat ;
	bool estConnecte;
	int identification ;
};

bool continuer = true;

/*
 * ---------------------------------------
 * 		PROTOTYPES DES ACTIONS
 * ---------------------------------------
 */

int main();
int afficherMenu();
bool lancerAction(int choix, struct Robot r);

int connexionServeur(struct Robot r);
int deconnexionServeur(struct Robot r);
int envoyer_etat(struct Robot r);
void changerEtat();

int creationSocket(int domaine, int type, int protocol);

#endif /* CLIENT_H_ */
