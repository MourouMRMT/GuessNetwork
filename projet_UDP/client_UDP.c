/*  Application MIROIR  : cote clientent        */

#include "commun.h"
#include "QCM.h"

int flag=0;
void reponse(char* chaine_recu,char *chaine);
void jeu(char* chaine_recu,char *chaine);
int main (int argc, char **argv)
{

    /*---------------------------------------------- les variables */

    /* pour le client */
    int point_acces_client; /* le point d'accès */

    /* pour l'expédition */
    struct hostent *adIP_serveur;   /* système où est le serveur */
    /*int port;*/
    struct sockaddr_in adUDP_serveur;   /* pour mettre l'adresse de son point d'accès */

    /* pour l'envoi  */
    char envoyer[100];
    int emis;

    /* pour la réception  */
    struct sockaddr_in adresse_expediteur;
#ifdef  __osf__
    int lg_expediteur;
#else
    socklen_t lg_expediteur;
#endif
    char recu[500];
    int recus;

    /*---------------------------------------------- l'algorithme */

    /* vérification des arguments */
    if (argc != 3)
    {
        printf ("Usage : %s nom_systeme port\n", argv[0]);
        exit (-1);
    }
    /* récupération des adresses-IP du système où est le serveur */
    if ((adIP_serveur = gethostbyname (argv[1])) == NULL)
    {
        herror("gethostbyname ");
        exit (-1);
    }
    /* création d'un point d'accès */
    point_acces_client = socket (PF_INET, SOCK_DGRAM, 0);
    if (point_acces_client < 0)
    {
        perror ("ERREUR-socket ");
        exit (-1);
    }

    /* préparation de l'adresse destinataire (serveur) */
    bzero (&adUDP_serveur, sizeof (adUDP_serveur));
    adUDP_serveur.sin_family = AF_INET;
    adUDP_serveur.sin_port = htons (atoi (argv[2]));
    memcpy (&adUDP_serveur.sin_addr, adIP_serveur->h_addr, 4);
    while(1)
    {
        /* lecture d'une ligne au clavier */
		switch(flag)
		{
			case 0:reponse(recu,envoyer);
			case 1:jeu(recu,envoyer);
		}//getchar();

	
        /* envoi d'un bloc d'octets */
        emis = sendto (point_acces_client,
                   envoyer, strlen (envoyer) + 1, 0,
                   (struct sockaddr *) &adUDP_serveur,
                   sizeof (adUDP_serveur));
                  
        if (emis < 0)
        {
            perror ("ERREUR-sendto ");
        }
        else
        {
            printf ("ENVOI %d octets\n", emis);
            printf ("\t%s\n", envoyer);

            /* réception de l'écho */
            lg_expediteur = sizeof (adresse_expediteur);
            recus = recvfrom (point_acces_client,
                      recu, sizeof (recu), 0,
                      (struct sockaddr *) &adresse_expediteur,
                      &lg_expediteur);
            if (recus < 0)
            {
                perror ("ERREUR-recvfrom ");
            }
            else
            {
                printf ("RECU  %d octets\n", recus);
                printf ("\t%s\n", recu);
				printf("\t%d\n",flag);
            }
        }
		
		
		
	}


        exit (0);
    
 
}

void reponse(char* chaine_recu,char *chaine)
{
	printf("on est dans reponse");
	if(strcmp("oui",chaine_recu)==0)
	{
		flag=1;
		
	}else
	{
	    printf ("Que faut-il envoyer ? \n\t");
        scanf("%99[^\n]",chaine);
        getchar();
	}
}

void jeu(char* chaine_recu,char *chaine)
{
	printf("on est dans jeu");
	int index=atoi(chaine_recu);
	printf("**index: %d **",index);
	if(flag==1){
		printf("%s",questions[index].question);
		
	    printf ("Que faut-il envoyer ? \n\t");
        scanf("%99[^\n]",chaine);
		getchar();
		
	}
}