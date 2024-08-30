#include <stdio.h>
#include <stdlib.h>
#include "address_ip_msr.h"

/*----------------------------------------------------------------------------------------------------------------------------*/

void usage(int argc ,char *argv)
{
    if(argc==1)
    {
        fprintf(stderr,"Usage : %s xxx.xxx.xxx.xxx (ip adress)\n\n",argv);
        exit(EXIT_SUCCESS);
    }
}


/*----------------------------------------------------------------------------------------------------------------------------*/


void objet()
{
    printf("Verifie si c'est un address ip\n\n");
}


/*----------------------------------------------------------------------------------------------------------------------------*/


void get_ip(char *argv ,ip *address)
{
    address->a = -1,address->b = -1,address->c = -1, address->d =-1;
    sscanf(argv,"%d.%d.%d.%d\n\n",&address->a,&address->b,&address->c,&address->d);
    printf("%s\n\n",argv);
    if(address->a > 255 || address->b > 255 || address->c > 255 || address->d > 255 || address->a < 0 || address->b < 0 || address->c < 0 || address->d < 0)
    {
        printf("Ce n'est pas un adresse ip\n\n");
        exit(EXIT_SUCCESS);
    }
}


/*----------------------------------------------------------------------------------------------------------------------------*/


void verifie(ip address)
{
    if(address.a >= 0 && address.a < 128)
    {
        printf("                              ___ \n");
        printf("L'adresse ip est de class  : | A | \n\n");
        printf("                                 ___________\n");
        printf("Le masque de sous reseau est  : | 255.0.0.0 |\n\n");
        printf("                           _________ \n");
        printf("L'adresse du Reseau est : |%d.0.0.0 |\n\n",address.a);
        printf("                               ________________ \n");
        printf("L'adresse du broadcast est  : | %d.255.255.255 |\n\n",address.a);
        printf("                                                            ____________\n");
        printf("Le nombre de machine disponible sur ce reseau est alors  : | 16.777.214 |\n\n");
    }

    else if(address.a >= 128 && address.a < 192)
    {
        printf("                              ___ \n");
        printf("L'adresse ip est de class  : | B |\n\n");
        printf("                                  __________\n");
        printf("Le masque de sous reseau est  : | 255.0.0.0 |");
        printf("                            _________ \n");
        printf("L'adresse du Reseau est  : |%d.%d.0.0|\n\n",address.a,address.b);
        printf("                               _____________ \n");
        printf("L'adresse du broadcast est  : |%d.%d.255.255|\n\n",address.a,address.b);
        printf("                                                             _______ \n");
        printf("Le nombre de machine disponible sur ce reseau est alors  : | 65.534 |\n\n");
    }

    else if(address.a >= 192 && address.a < 224)
    {
        printf("                              ___ \n");
        printf("L'adresse ip est de class  : C \n\n");
        printf("                              ___ \n");
        printf("Le masque de sous reseau est  : 255.255.255.0");
        printf("                              ___ \n");
        printf("L'adresse du Reseau est  : %d.%d.%d.0\n\n",address.a,address.b,address.c);
        printf("                              ___ \n");
        printf("L'adresse du broadcast est  : %d.%d.%d.255\n\n",address.a,address.b,address.c);
        printf("                              ___ \n");
        printf("Le nombre de machine disponible sur ce reseau est alors :  254\n\n");
    }

    else if(address.a >= 224 && address.a < 240)
    {
        printf("                              ___ \n");
        printf("L'adresse ip est de class D \n\n");
        printf("                              ___ \n");
        printf("Le masque de sous reseau est 255.255.255.255");
    }

    else if(address.a >= 240 && address.a < 255)
    {
        printf("                              ___ \n");
        printf("L'adresse ip est de class E \n\n");
        printf("                              ___ \n");
        printf("Le masque de sous reseau est 255.255.255.255");
    }
}
/*----------------------------------------------------------------------------------------------------------------------------*/
