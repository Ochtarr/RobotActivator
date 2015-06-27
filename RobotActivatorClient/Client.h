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
	int sin_family = AF_INET;
	int sin_port = htons(2000);
	int sin_addr = inet_addr("127.0.0.1");
*/


/*
 * ---------------------------------------
 * 		PROTOTYPES DES ACTIONS
 * ---------------------------------------
 */

int main();
int afficherMenu();
void lancerAction(int choix, struct Robot r);
int connexionServeur(struct Robot r);
int deconnexionServeur(struct Robot r);
int envoyer_etat(int etat, struct Robot r);
void changerEtat();


#endif /* CLIENT_H_ */
