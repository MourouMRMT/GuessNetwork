/*  Application MIROIR  : cote clientent        */

#include "commun.h"
#include "QCM.h"


void reponse(char *chaine);

int main (int argc, char **argv)
{

    /*---------------------------------------------- les variables */

    /* pour le client */
    int point_acces_client; /* le point d'acc�s */

    /* pour l'exp�dition */
    struct hostent *adIP_serveur;   /* syst�me o� est le serveur */
    /*int port;*/
    struct sockaddr_in adUDP_serveur;   /* pour mettre l'adresse de son point d'acc�s */

    /* pour l'envoi  */
    char envoyer[100];
    int emis;

    /* pour la r�ception  */
    struct sockaddr_in adresse_expediteur;
#ifdef  __osf__
    int lg_expediteur;
#else
    socklen_t lg_expediteur;
#endif
    char recu[500];
    int recus;

    /*---------------------------------------------- l'algorithme */

    /* v�rification des arguments */
    if (argc != 3)
    {
        printf ("Usage : %s nom_systeme port\n", argv[0]);
        exit (-1);
    }
    /* r�cup�ration des adresses-IP du syst�me o� est le serveur */
    if ((adIP_serveur = gethostbyname (argv[1])) == NULL)
    {
        herror("gethostbyname ");
        exit (-1);
    }
    /* cr�ation d'un point d'acc�s */
    point_acces_client = socket (PF_INET, SOCK_DGRAM, 0);
    if (point_acces_client < 0)
    {
        perror ("ERREUR-socket ");
        exit (-1);
    }

    /* pr�paration de l'adresse destinataire (serveur) */
    bzero (&adUDP_serveur, sizeof (adUDP_serveur));
    adUDP_serveur.sin_family = AF_INET;
    adUDP_serveur.sin_port = htons (atoi (argv[2]));
    memcpy (&adUDP_serveur.sin_addr, adIP_serveur->h_addr, 4);
    while(1)
    {
        /* lecture d'une ligne au clavier */
		reponse(recu,envoyer);

	
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

            /* r�ception de l'�cho */
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
            }
        }
		
		
		
	}


        exit (0);
    
 
}

void reponse(char* chaine_recu,char *chaine)
{
	if(strcmp("oui",chaine_recu)==0)
	{
		printf("%s",&questions[1].question);
	}else
	{
	    printf ("Que faut-il envoyer ? \n\t");
        scanf("%99[^\n]",chaine);
        getchar();
	}
}