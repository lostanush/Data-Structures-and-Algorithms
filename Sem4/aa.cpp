#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert subnet mask to prefix length
int subnetToPrefixLength(const char* subnetMask) {
    int octets[4];
    sscanf(subnetMask, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    
    int prefixLength = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 7; j >= 0; --j) {
            if (octets[i] & (1 << j)) {
                ++prefixLength;
            } else {
                break;
            }
        }
    }
    return prefixLength;
}

int main() {
    char ipAddress[] = "192.168.1.10";
    char subnetMask[] = "255.255.255.0";
    
    // Convert subnet mask to prefix length
    int subnet = subnetToPrefixLength(subnetMask);
    
    // Print the subnet prefix length
    printf("Subnet Prefix Length: %d\n", subnet);

    // Calculate network address
    char networkAddress[16];
    sscanf(ipAddress, "%*d.%*d.%*d.%*d", &networkAddress);
    strcat(networkAddress, "/");
    strncat(networkAddress, subnetMask, strlen(subnetMask) - 2);

    printf("Network Address: %s\n", networkAddress);

    // Calculate broadcast address
    char broadcastAddress[16];
    sscanf(ipAddress, "%*d.%*d.%*d.%*d", &broadcastAddress);
    strcat(broadcastAddress, "/");
    for (int i = 0; i < subnet; ++i) {
        strcat(broadcastAddress, "1");
    }
    for (int i = subnet; i < 32; ++i) {
        strcat(broadcastAddress, "0");
    }
    printf("Broadcast Address: %s\n", broadcastAddress);

    // Calculate number of hosts
    int numHosts = (1 << (32 - subnet)) - 2;
    printf("Number of Hosts: %d\n", numHosts);

    // Print all hosts in the network
    printf("\nAll Hosts in the Network:\n");
    char hostAddress[16];
    for (int i = 1; i <= numHosts; ++i) {
        sscanf(ipAddress, "%*d.%*d.%*d.%*d", &hostAddress);
        strcat(hostAddress, "/");
        for (int j = 0; j < subnet; ++j) {
            strcat(hostAddress, "0");
        }
        for (int j = subnet; j < 32; ++j) {
            if (i & (1 << (31 - j))) {
                strcat(hostAddress, "1");
            } else {
                strcat(hostAddress, "0");
            }
        }
        printf("%s\n", hostAddress);
    }
    
    return 0;
}
