systeme=`hostname -s`

GCC=cc

all: tcp

tcp: serveur_TCP client_TCP

serveur_TCP:serveur_TCP.c commun.h
	$(GCC) -o $@-$(systeme) serveur_TCP.c

client_TCP:client_TCP.c commun.h
	$(GCC) -o $@-$(systeme) client_TCP.c


clean: clean-TCP 

clean-TCP:
	rm -f serveur_TCP-$(systeme) client_TCP-$(systeme)