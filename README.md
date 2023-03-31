# GuessNetwork
Projet de jeu en réseau sur environnement linux

## Le Jeu
Guess Network est un jeu de culture générale qui utilise le protocole de réseau UDP pour permettre au client de se connecter à un serveur. Le serveur pose une question de manière aléatoire à partir de sa base de données de questions. Le client dispose de deux tentatives pour y répondre.

##Procedure

Afin de jouer il sera nécessaire de faire un make a partir du dossier **Projet_UDP** cela generera les 2 éxecutables nécessaires au lancement du client et du serveur.

L'éxecutable serveur sera de la forme : serveur_UDP-Nom_de_la_machine [Port] 
Le port peut-etre facilement obtenu grace à la command **id-u**

L'éxecutable client sera de la forme : client_UDP-nom_de_la_machine nom_de_la_machine_serveur [Port] 


