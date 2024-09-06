typedef struct ip
{
    int a,b,c,d;
    int R1[8],R2[8],R3[8],R4[8];
    int mask1[8] , mask2[8] , mask3[8] , mask4[8];
    int m1 , m2 , m3 , m4;
}ip;

/*-----------------------------------------------------*/
/*entrer l'adresse ip a l'ecran*/
void get_ip(char *argv ,ip *address);

/*-----------------------------------------------------*/
void objet();

/*-----------------------------------------------------*/
void verifie(ip address , int bits);

/*-----------------------------------------------------*/
/*l'execution du programme*/
void usage(int argc ,char *argv);

/*-----------------------------------------------------*/
/*notation decimale en notation binaire*/
void bin(int a , int *R);

/*-----------------------------------------------------*/
/*Le cidr*/
void cidr(ip *address , int bits);

/*-----------------------------------------------------*/
int input_bits();

/*-----------------------------------------------------*/
/*transformer un nombre en notation decimale*/
int revert_bin(int *rest);

/*-----------------------------------------------------*/
/*affichage du netmask*/
void display_netmask(ip address);

/*-----------------------------------------------------*/
void get_NMSK(ip *address);