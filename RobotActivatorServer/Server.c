/*
 * Server.c
 *
 *  Created on: 16 juin 2015
 *      Author: florian
 */

#include "Server.h"

int main(){

	puts("Lancement du serveur");

	int sock = creationSocket(AF_INET, SOCK_STREAM, 0);

	if(sock == -1)
	{
		puts("Erreur lors de la création du socket");
		perror("socket");
		return errno;
	}

	puts("Socket crée");

	//Configuration du socket
	struct sockaddr_in sin;
	sin.sin_family = AF_INET; /* La famille du protocole */
	sin.sin_port = htons(2000); /* Le port au format reseau htons = Host To Network Short */
	sin.sin_addr.s_addr = htonl(INADDR_ANY);

	puts("Configuration du socket ... ok");

	/* Bind sert a lier la socket sur un port, elle prend les memes parametres que connect */
	if(bind(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		return errno;
	}

	/* Listen ecoute sur le port, cette fonction prend en parametre la socket et le nombre de client qu'il veut */
	if(listen(sock, 2) == -1)
	{
		perror("listen");
		return errno;
	}

	int csock; /* La socket du client */
	struct sockaddr_in csin; /* La structure du client */
	int sinsize = sizeof(csin);

	/* accept en parametre la socket serveur, la structure du client convertis en sockaddr qu'elle remplira, la taille de la structure du client, elle renvois la socket client */
	if((csock = accept(sock, (struct sockaddr *)&csin, &sinsize)) < 0)
	{
		perror("accept");
		return errno;
	}

	/*
	 * Lecture du socket
	 */
	char nom[20]; /* Nom du client */

	/* read lit sur la socket mise en parametre, elle prends en parametre la socket que l'on veuire, la variable a remplir et la taille de cette variable */
	if(read(csock, nom, sizeof(nom)) == -1)
	{
		perror("read nom");
		return errno;
	}

	printf("%s s'est connecte.\n", nom);

	char buffer[1024];

	bool continuer = true;
	do
	{
		if(read(csock, buffer, sizeof(buffer)) == -1)
		{
			perror("read");
			return errno;
		}

		if(strcmp(buffer, "robot deconnection") == 0)
			continuer = false;
		else
			printf("%s: %s.\n", nom, buffer);

		//readStr(buffer, sizeof(buffer));

	}while(continuer == true);

	printf("%s s'est deconnecte.\n", nom);

	close(sock);

	return EXIT_SUCCESS;
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

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

int readStr(char *str, int len){
    char *pos = NULL;

    if (fgets(str, len, stdin) != NULL){
        pos = strchr(str, '\n');
        if (pos != NULL)
        {
            *pos = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    viderBuffer();
    return 0;
}
