/*
 * Server.c
 *
 *  Created on: 16 juin 2015
 *      Author: florian
 */

#include "Server.h"

int main(){



}


/*
 *  Fonction permettant d'écouter un port spécifié
 */
void ecouterPort(int port){

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
