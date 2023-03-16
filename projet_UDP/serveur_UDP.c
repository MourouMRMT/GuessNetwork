/*  Application MIROIR  : cote serveur      */

#include "commun.h"
#include "QCM.h"
void begin (char *chaine);
void reponse (char *chaine);
int J=0;
int flag=0;

struct sockaddr_in adresse_expediteur;
struct sockaddr_in sock1;
struct sockaddr_in sock2;
int point_acces_serveur;
int recus, emis;
char message[100];

main (int argc, char **argv) {

    /*---------------------------------------------- les variables */

        /* pour le serveur */
    struct sockaddr_in adUDP_serveur;   /* pour mettre l'adresse de son point d'acc�s */
    

        /* pour le service */

	
	sock1.sin_family=0;
	sock1.sin_port=0;
	sock1.sin_addr.s_addr=0;
	
	sock2.sin_family=0;
	sock2.sin_port=0;
	sock2.sin_addr.s_addr=0;
#ifdef  __osf__
    int lg_expediteur;
#else
    socklen_t lg_expediteur;
#endif
    
        /* divers */
    int retour;

    /*---------------------------------------------- l'algorithme */

        /* v�rification des arguments */
    if (argc != 2) {
        printf("Usage : %s port\n",argv[0]);
        exit(-1);
    }
        /* cr�ation d'un point d'acc�s */
    point_acces_serveur = socket (PF_INET,SOCK_DGRAM,0);
    if (point_acces_serveur < 0) {
        perror("ERREUR-socket ");
        exit(-1);
    }

        /* pr�paration de l'adresse du point d'acc�s */
    bzero(&adUDP_serveur,sizeof(adUDP_serveur));
    adUDP_serveur.sin_family = AF_INET;
    adUDP_serveur.sin_port = htons(atoi(argv[1]));
    adUDP_serveur.sin_addr.s_addr = INADDR_ANY;

        /* attribution de l'adresse au point d'acc�s */
    retour = bind(point_acces_serveur,
            (struct sockaddr *)&adUDP_serveur, sizeof(adUDP_serveur));
    if (retour < 0 ) {
        perror("ERREUR-bind ");
        exit(-1);
    }


        /* phase de transfert */
    while(1) {
        lg_expediteur=sizeof(adresse_expediteur);
        recus = recvfrom(point_acces_serveur,
            message, sizeof(message), 0,
            (struct sockaddr *) &adresse_expediteur, &lg_expediteur);
        if (recus < 0) {
            perror("ERREUR-recvfrom ");
        }
        /*else {
            printf("RECU %d octets de %s:%d\n", recus,
                inet_ntoa(adresse_expediteur.sin_addr),
                ntohs(adresse_expediteur.sin_port));
            printf("\t%s\n",message);/*
			
                /* on calcule la r�ponse */
			if( flag!=1){reponse(message);}
            else{
				begin1(message);
				begin2(message);
			}
                /* et on lui renvoie */
 /*           emis =  sendto (point_acces_serveur,
                message, strlen(message)+1, 0,
                (struct sockaddr *) &adresse_expediteur, sizeof(adresse_expediteur));
            if (emis < 0) {
                perror("ERREUR-sendto ");
            }
            else {
                printf("ENVOI %d octets\n", strlen(message)+1);
                printf("\t%s\n",message);
                }
*/
        }

    }


void reponse(char *chaine) {

    if (strcmp("begin",chaine)==0)
    {
		if(sock1.sin_port==0)
		{
			sock1.sin_port=adresse_expediteur.sin_port;
			sock1.sin_family=adresse_expediteur.sin_family;

			inet_ntoa(adresse_expediteur.sin_addr),
			ntohs(adresse_expediteur.sin_port);
			//strcpy(message,"1");
			strcpy(chaine,"Bienvenue sur GuessNetwork !!!\n\tVoulez vous commencez ? (oui/non)");
			//J=1;
		}else if(adresse_expediteur.sin_port!=sock1.sin_port && sock2.sin_port==0)
		{
			sock2.sin_port=adresse_expediteur.sin_port;
			sock2.sin_family=adresse_expediteur.sin_family;

			inet_ntoa(adresse_expediteur.sin_addr),
			ntohs(adresse_expediteur.sin_port);
			//strcpy(message,"1");
			strcpy(chaine,"Bienvenue sur GuessNetwork !!!\n\tVoulez vous commencez ? (oui/non)");
			flag=1;
		}
		
	}
    else
    {
		strcpy(chaine,"Commencez le jeu en saisissant begin ");
	}
}
void begin1(char *chaine)
{
	int valide=0;
    if(strcmp("oui",chaine)==0){valide=1;}
	if(valide==1)
	{
		strcpy(chaine,questions[1].question);
		emis =  sendto (point_acces_serveur,
                message, strlen(message)+1, 0,
                (struct sockaddr *) &adresse_expediteur, sizeof(adresse_expediteur));
		if (emis < 0) {
			perror("ERREUR-sendto ");
		}
		else {
			printf("ENVOI %d octets\n", strlen(message)+1);
			printf("\t%s\n",message);
			}
		if(strcmp("A",chaine)==0)
        {
            strcpy(chaine,"GG tu as WIN!");
        }
	}

}

void begin2(char *chaine)
{
	int valide=0;
    if(strcmp("oui",chaine)==0){valide=1;}
	if(valide==1)
	{
		strcpy(chaine,questions[1].question);
		emis =  sendto (point_acces_serveur,
                message, strlen(message)+1, 0,
                (struct sockaddr *) &adresse_expediteur, sizeof(adresse_expediteur));
		if (emis < 0) {
			perror("ERREUR-sendto ");
		}
		else {
			printf("ENVOI %d octets\n", strlen(message)+1);
			printf("\t%s\n",message);
			}
		if(strcmp("A",chaine)==0)
        {
            strcpy(chaine,"GG tu as WIN!");
        }
	}

}

