#include <iostream>
#include <cmath>

int main()
{
    std::string password;
    
    int rangeSize[4]; // lower case = 26 ; upper case = 26 ; numbers = 10 ; simbols = 32
    int characterRange = 0;
    
    std::cin >> password;
    
    for (char x : password) {
        int ASCIIx = int(x);
        if (ASCIIx >= 97 && ASCIIx <= (97+25)) { // lower case
            rangeSize[0] = 26;
        }
        else if (ASCIIx >= 65 && ASCIIx <= (65+25)) { // upper case
            rangeSize[1] = 26;
        }
        else if (ASCIIx >= 48 && ASCIIx <= (48+9)) { // numbers
            rangeSize[2] = 10;
        }
        
        else { // simbols
            rangeSize[3] = 32;
        }
    }

    characterRange = rangeSize[0] + rangeSize[1] + rangeSize[2] + rangeSize[3];
    
    double potent = pow(characterRange, int(password.length()));

    std::cout << "Total of all characteres possibles " << characterRange << std::endl << "length is " << password.length() << std::endl;
    std::cout << "Math: " << potent << std::endl;
    std::cout << "Entropy in bits: " << log2(potent) << std::endl;
    
    double T = potent / pow(10,9);
    
    std::cout << "It's takes " << T << " seconds; " << T/60 << " minutes; " << T/60/60 << " hours; " << T/60/60/24 << " days and ";
    std::cout << T/60/60/24/365 << " years ";
    std::cout << "to guess your password" << std::endl;
    std::cout << password;

    return 0;
}
