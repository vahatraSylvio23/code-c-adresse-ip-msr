#include <stdio.h>
#include <stdlib.h>
#include "address_ip_msr.h"

int main(int argc ,char *argv[])
{
    char add_ip[100];
    ip address;
    int bits;
    usage(argc ,argv[0]);
    objet();
    get_ip(argv[1] ,&address);
    bits = input_bits();
    cidr(&address , bits);    
    get_NMSK(&address);
    display_netmask(address);
    verifie(address , bits);
    return 0;
}