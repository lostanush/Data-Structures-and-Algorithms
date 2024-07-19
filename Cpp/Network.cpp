#include <iostream>
#include <cstring>
using namespace std;

// Function to find out the Class
char findClass(const char str[]){
    char arr[4];
    int i = 0;
    while (str[i] != '.')
    {
        arr[i] = str[i];
        i++;
    }
    i--;

    // converting str[] variable into number for
    // comparison
    int ip = 0, j = 1;
    while (i >= 0)
    {
        ip += (str[i] - '0') * j;
        j = j * 10;
        i--;
    }

    // Class A
    if (ip >=1 && ip <= 126)
        return 'A';

    // Class B
    else if (ip >= 128 && ip <= 191)
        return 'B';

    // Class C
    else if (ip >= 192 && ip <= 223)
        return 'C';

    // Class D
    else if (ip >= 224 && ip <= 239)
        return 'D';

    // Class E
    else
        return 'E';
}

// Function to separate Network ID as well as
// Host ID and print them
void separate(const char str[], char ipClass)
{
    // Initializing network and host array to NULL
    char network[12], host[12];
    for (int k = 0; k < 12; k++)
        network[k] = host[k] = '\0';

    // for class A, only first octet is Network ID
    // and rest are Host ID
    if (ipClass == 'A')
    {
        int i = 0, j = 0;
        while (str[j] != '.')
            network[i++] = str[j++];
        i = 0;
        j++;
        while (str[j] != '\0')
            host[i++] = str[j++];
        cout << "Network ID is " << network << endl;
        cout << "Host ID is " << host << endl;
    }

    // for class B, first two octet are Network ID
    // and rest are Host ID
    else if (ipClass == 'B')
    {
        int i = 0, j = 0, dotCount = 0;

        // storing in network[] up to 2nd dot
        // dotCount keeps track of number of
        // dots or octets passed
        while (dotCount < 2)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;

        while (str[j] != '\0')
            host[i++] = str[j++];

        cout << "Network ID is " << network << endl;
        cout << "Host ID is " << host << endl;
    }

    // for class C, first three octet are Network ID
    // and rest are Host ID
    else if (ipClass == 'C')
    {
        int i = 0, j = 0, dotCount = 0;

        // storing in network[] up to 3rd dot
        // dotCount keeps track of number of
        // dots or octets passed
        while (dotCount < 3)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }

        i = 0;
        j++;

        while (str[j] != '\0')
            host[i++] = str[j++];

        cout << "Network ID is " << network << endl;
        cout << "Host ID is " << host << endl;
    }

    // Class D and E are not divided in Network
    // and Host ID
    else
        cout << "In this Class, IP address is not divided into Network and Host ID" << endl;
}

// Driver function to test above functions
int main()
{
    const char str[] = "192.226.12.11";
    char ipClass = findClass(str);
    cout << "Given IP address belongs to Class " << ipClass << endl;
    separate(str, ipClass);
    return 0;
}
fgh