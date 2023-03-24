/*  Application MIROIR  : cote serveur      */

#include "commun.h"
#include "QCM.h"
void begin (char *chaine);
void reponse (char *chaine);
void jeu (char *chaine);
int flag=0;
int *num_q=0;

int main (int argc, char **argv) {

    /*---------------------------------------------- les variables */

        /* pour le serveur */
    struct sockaddr_in adUDP_serveur;   /* pour mettre l'adresse de son point d'acc�s */
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

	flag=0;
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

                /* on calcule la r�ponse */
            switch(flag)
            {
                case 0:
					reponse(message);
                case 1:
					begin(message);
				//case 2:
					//jeu(message);
				//default:
					//flag=3;
					//reponse(message);
            }
                /* et on lui renvoie */
            emis =  sendto (point_acces_serveur,
                message, strlen(message)+1, 0,
                (struct sockaddr *) &adresse_expediteur, sizeof(adresse_expediteur));
            if (emis < 0) {
                perror("ERREUR-sendto ");
            }
            else {
                printf("ENVOI %ld octets\n", strlen(message)+1);
                printf("\t%s\n",message);
                printf("\t%d\n",flag);
                }

        }

    }
}

void reponse(char *chaine) 
{
	printf("on est dans reponse\n ");

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
{	int rnd=0;
	printf("on est dans begin\n");
	//char cpt=0;

    if(strcmp("oui",chaine)==0)
	{
		//strcpy(chaine,&questions[1].question);
		strcpy(chaine,"oui");
		printf("%s\n","**begin**");
		//flag=1;
		//jeu(chaine);
		//if(strcmp("reponse",chaine)==0)
		rnd =1+ random() % (21 + 1 - 1);
		int rando[5];
		sprintf(rando, "%d", &rnd);
		printf("**index: %d **\n",rnd);
		//strcpy(chaine,rando);
		strcpy(chaine,questions[rnd].question);
			
	}
	char str[12];
	sprintf(str, "%s", &questions[rnd].correctOption);
	printf("reponse %s\n",str);
	if(strcmp(str,chaine)==0)
	{
		strcpy(chaine,"GG tu as WIN!");
		
	}
	/*else{cpt++;}
	
	if(cpt==2){strcpy(chaine,"Debile");}*/

}