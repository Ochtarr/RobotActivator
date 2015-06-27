/*
 * Client.h
 *
 *  Created on: 16 juin 2015
 *      Author: florian
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
	int identification ;
};

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


#endif /* CLIENT_H_ */
