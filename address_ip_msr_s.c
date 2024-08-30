#include <stdio.h>
#include <stdlib.h>
#include "address_ip_msr.h"

int main(int argc ,char *argv[])
{
    char add_ip[100];
    ip address;
    usage(argc ,argv[0]);
    objet();
    get_ip(argv[1] ,&address);
    verifie(address);
    return 0;
}