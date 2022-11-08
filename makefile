projet:utilisateur.o main1.o
	gcc main1.o utilisateur.o -o projet -g	
main1.o:main1.c
	gcc -c main1.c -g
utilisateur.o:utilisateur.c
	gcc -c utilisateur.c -g
