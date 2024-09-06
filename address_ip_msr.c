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


void verifie(ip address , int bits)
{
    if(address.a >= 0 && address.a < 128)
    {
        printf("-----------------------------------\n");
        printf("L'adresse ip est de class  : | A | \n");
        printf("-----------------------------------\n");
        printf("------------------------------------\n");
        printf("L'adresse du Reseau est : |%d.0.0.0 |\n",address.a);
        printf("----------------------------------------------\n");
        printf("L'adresse du broadcast est  : | %d.255.255.255 |\n",address.a);
        printf("------------------------------------------------------------------------\n");
        printf("Le nombre de machine disponible sur ce reseau est alors  : | 16.777.214 |\n");
        printf("------------------------------------------------------------------------\n");
    }

    else if(address.a >= 128 && address.a < 192)
    {
        printf("-----------------------------------\n");
        printf("L'adresse ip est de class  : | B |\n");
        printf("-----------------------------------\n");
        printf("-------------------------------------\n");
        printf("L'adresse du Reseau est  : |%d.%d.0.0|\n",address.a,address.b);
        printf("-------------------------------------\n");
        printf("--------------------------------------------\n");
        printf("L'adresse du broadcast est  : |%d.%d.255.255|\n",address.a,address.b);
        printf("--------------------------------------------\n");
        printf("--------------------------------------------------------------------\n");
        printf("Le nombre de machine disponible sur ce reseau est alors  : | 65.534 |\n");
        printf("-------------------------------------------------------------------\n");
    }

    else if(address.a >= 192 && address.a < 224)
    {
        printf("--------------------------------\n");
        printf("L'adresse ip est de class  :| C |\n");
        printf("--------------------------------\n");
        printf("----------------------------------------\n");
        printf("L'adresse du Reseau est  : |%d.%d.%d .0 |\n",address.a,address.b,address.c);
        printf("----------------------------------------\n");
        printf("--------------------------------------------\n");
        printf("L'adresse du broadcast est  : |%d.%d.%d.255 |\n",address.a,address.b,address.c);
        printf("--------------------------------------------\n");
        printf("---------------------------------------------------------------\n");
        printf("Le nombre de machine disponible sur ce reseau est alors :  |254|\n");
        printf("--------------------------------------------------------------\n");
    }

    else if(address.a >= 224 && address.a < 240)
    {
        printf("                          ___ \n");
        printf("L'adresse ip est de class| D |\n\n");
        printf("                              _______________ \n");
        printf("Le masque de sous reseau est |255.255.255.255|");
    }

    else if(address.a >= 240 && address.a < 255)
    {
        printf("                          ___ \n");
        printf("L'adresse ip est de class| E |\n\n");
        printf("                              _______________ \n");
        printf("Le masque de sous reseau est |255.255.255.255|");
    }
}


/*----------------------------------------------------------------------------------------------------------------------------*/

int input_bits()
{
    int bits;
    char b[3];
    bits = -1;
    printf("Entrer le nombre de bits reseau :");
    scanf("%s",b);
    sscanf(b ,"%d",&bits);
    return bits;
}


/*----------------------------------------------------------------------------------------------------------------------------*/


void cidr(ip *address , int bits)
{
    int rest[8];
    int i;
    int netmask[32];
    printf("CIDR est %d.%d.%d.%d/%d\n\n",address->a,address->b,address->c,address->d,bits);
    printf("\n\n");
    printf("Selon le nombre de bits reseau : %d\n",bits);

    for(i = 0 ; i < 32 ; i++)
    {
        if(i < bits)
        {
            netmask[i] = 1;
        }
        else
        {
            netmask[i] = 0 ;
        }
    }

  for(i = 0 ; i < 32 ; i++)
    {
        if(i < 8)
        {
            address->mask1[i] = netmask[i] ;
        }

        else if(i>=8 && i < 16)
        {
            address->mask2[i-8] = netmask[i];
        }

        else if(i>=16 && i < 24)
        {
            address->mask3[i-16] = netmask[i];
        }
        
        else if(i>=24 && i < 32)
        {
            address->mask4[i-24] = netmask[i];
        }
    }
    
    printf("\n\nLe netmask est\n");

    printf("---------------------------------------------------------------------------------------------\n");
    printf("En notation binaire : |");
    for(i = 0 ; i < 32 ; i++)
    {
        if(i % 8 == 0)
        {
            printf(".");
            printf("%d ",netmask[i]);
        }
        else
        {
            printf("%d ",netmask[i]);
        }
    }
    printf(" |\n");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\n\n");


}


/*----------------------------------------------------------------------------------------------------------------------------*/



void bin(int a , int *R)
{
    int power[8];
    int rest[8];
    int temp = 0;
    int i;
    power[0] = 128 ;
    
    for(i = 1 ; i < 8 ; i++)
    {
        power[i] = power[i - 1]  / 2;
    }
    
    for(i = 0 ; i < 8 ; i++)
    {
        rest[i] = 0 ; 
    }

    for(i = 0 ; i < 8 ; i++)
    {
        temp += power[i] ;
        if(a > temp)
        {
                rest[i] = 1;
        }
        else if(temp > a)
        {
            temp -= power[i] ;
        }
        else if (temp == a)
        {
            rest[i] = 1 ;
        }
    }

    if(a % 2 == 0)
    {
        rest[7] = 0 ;
    }
    
    else if(a % 2 == 1)
    {
        rest[7] = 1 ;
    }

    for(i = 0 ; i < 8 ; i++)
    {
        printf("%d ",rest[i]);
        rest[i] = R[i];
    }
}



/*----------------------------------------------------------------------------------------------------------------------------*/

/*La fonction pour transformer un nombre en notation decimale*/

int revert_bin(int *rest)
{
    int to_dec;
    int power[8];
    int temp = 0;
    int i;
    int a;
    power[0] = 128 ;
        
    for(i = 1 ; i < 8 ; i++)
    {
        power[i] = power[i - 1]  / 2;
    }
    
    for(i = 0 ; i < 8 ; i++)
    {
        if(rest[i] == 1)
        {
            temp += power[i] ;
        }
    }
    to_dec = temp;

    return to_dec;
}


/*----------------------------------------------------------------------------------------------------------------------------*/


void get_NMSK(ip *address)
{
    address->m1 = revert_bin(address->mask1);
    address->m2 = revert_bin(address->mask2);
    address->m3 = revert_bin(address->mask3);
    address->m4 = revert_bin(address->mask4);

}


/*----------------------------------------------------------------------------------------------------------------------------*/


void display_netmask(ip address )
{
    printf("-----------------------------------------\n");
    printf("En notation decimale : |");
    printf("%d.",address.m1);
    printf("%d.",address.m2);
    printf("%d.",address.m3);
    printf("%d" ,address.m4);
    printf(" |\n");
    printf("-----------------------------------------\n");
    printf("\n\n");
}