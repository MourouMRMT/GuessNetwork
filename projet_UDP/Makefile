systeme=`hostname -s`

GCC=cc

all: udp

#tcp: serveur_TCP client_TCP
udp: serveur_UDP client_UDP
serveur_UDP:serveur_UDP.c commun.h
	$(GCC) -o $@-$(systeme) serveur_UDP.c

client_UDP:client_UDP.c commun.h
	$(GCC) -o $@-$(systeme) client_UDP.c

clean: clean-UDP

clean-UDP:
	rm -f serveur_UDP-$(systeme) client_UDP-$(systeme)
