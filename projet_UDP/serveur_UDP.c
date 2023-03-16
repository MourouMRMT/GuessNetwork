/*  Application MIROIR  : cote serveur      */

#include "commun.h"
#include "QCM.h"
void begin (char *chaine);
void reponse (char *chaine);
int flag=0;
int num_q=0;

main (int argc, char **argv) {

    /*---------------------------------------------- les variables */

        /* pour le serveur */
    struct sockaddr_in adUDP_serveur;   /* pour mettre l'adresse de son point d'accès */
    int point_acces_serveur;

        /* pour le service */
    struct sockaddr_in adresse_expediteur;
#ifdef  __osf__
    int lg_expediteur;
#else
    socklen_t lg_expediteur;
#endif
    char message[100];
    int recus, emis;

        /* divers */
    int retour;

    /*---------------------------------------------- l'algorithme */

        /* vérification des arguments */
    if (argc != 2) {
        printf("Usage : %s port\n",argv[0]);
        exit(-1);
    }
        /* création d'un point d'accès */
    point_acces_serveur = socket (PF_INET,SOCK_DGRAM,0);
    if (point_acces_serveur < 0) {
        perror("ERREUR-socket ");
        exit(-1);
    }

        /* préparation de l'adresse du point d'accès */
    bzero(&adUDP_serveur,sizeof(adUDP_serveur));
    adUDP_serveur.sin_family = AF_INET;
    adUDP_serveur.sin_port = htons(atoi(argv[1]));
    adUDP_serveur.sin_addr.s_addr = INADDR_ANY;

        /* attribution de l'adresse au point d'accès */
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
        else {
            printf("RECU %d octets de %s:%d\n", recus,
                inet_ntoa(adresse_expediteur.sin_addr),
                ntohs(adresse_expediteur.sin_port));
            printf("\t%s\n",message);

                /* on calcule la réponse */
            switch(flag)
            {
                case 0:reponse(message);
                case 1:begin(message);
            }
                /* et on lui renvoie */
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

        }

    }
}

void reponse(char *chaine) {

    if (strcmp("begin",chaine)==0)
    {
		strcpy(chaine,"Bienvenue sur GuessNetwork !!!\n\tVoulez vous commencez ? (oui/non)");
		flag=1;
	}
    else
    {
		strcpy(chaine,"Commencez le jeu en saisissant begin ");
	}
}
void begin(char *chaine)
{
    if(strcmp("oui",chaine)==0)
	{
		strcpy(chaine,questions[1].question);
		
		if(strcmp(questions[1].correctOption,chaine)==0)
        {
            strcpy(chaine,"GG tu as WIN!");
			if(num_q==(NUM_QUESTIONS-1))
			{
				num_q=0;
			}else{num_q++;}
        }else{strcpy(chaine,"essaie encore...");}
	}

}
