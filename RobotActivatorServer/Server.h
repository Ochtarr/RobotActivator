/*
 * Server.h
 *
 *  Created on: 16 juin 2015
 *
 *  Author: florian
 *
 *  Summary :
 *      Le serveur doit gérer une liste de robots.
 *      Il doit pouvoir réaliser les actions suivantes :
 *
 */

#ifndef SERVER_H_
#define SERVER_H_

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
 * 		PROTOTYPES DES ACTIONS
 * ---------------------------------------
 */

int main();

void ecouterPort(int port);

int creationSocket(int domaine, int type, int protocol);
void viderBuffer();
int readStr(char *str, int len);

#endif /* SERVER_H_ */
