#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class credits
{
int size;
int stoi1[16];// string after converted to Integer
string cardnum;// card number
// verification of card number whether the number is Entered properly
int verify()
{
string tem; // temprorary variable for chararcter storage
size = cardnum.length();
for (int i = 0; i < cardnum.length(); i++)
{
 tem = cardnum[i];
int asc = (int)cardnum[i];
if (asc < 58 && asc > 47 && size >= 11 && size <= 16)
{
stoi1[i] = stoi(tem);
}
else
{
return 0; // for wrong entry
}
}
return 1;
}
public:
void cardtype()
{
if (stoi1[0] == 3)
{
cout << "\nAMERICAN EXPRESS CARD\n";
}
else if (stoi1[0] == 4)
{
cout << "\nVISA CARD\n";
}
else if (stoi1[0] == 5)
{
cout << "\nMASTERCARD\n";
}
else if (stoi1[0] == 6)
{
cout << "\nDISCOVER\n";
}
else
{
cout << "\nUNKNOWN CREDIT CARD TYPE\n\n";
}
}
//  constructor to initialize ..............
credits()
{
// The first digit is an industry identifier
// American Express credit card numbers are 15 digits long and begin with the number 3
// Visa credit card numbers are 16 digits long and begin with the number 4
// Mastercard credit card numbers are 16 digits long and most begin with the number 5
// Discover credit card numbers are 16 digits long and begin with the number 6
cout << "\n\nEnter you credit card number : ";
cin >> cardnum;
}
//  luhn alogorithm function.............
int luhnalgo()
{
int sum1 = 0;
size = cardnum.length();
if (verify() == 1)
{
for (int i = 0; i < size; i++)
{
if (size % 2 != i % 2)
{
sum1 = sum1 + stoi1[i];
}
else if (stoi1[i] > 4)
{
sum1 = sum1 + 2 * stoi1[i] - 9;
}
else
{
sum1 = sum1 + 2 * stoi1[i];
}
}
return sum1 % 10 + 1;
}
else
{
return 0;
}
}
};
int main()
{
system("CLS");
credits us;
if (us.luhnalgo() == 1)
{
us.cardtype();
cout << "\n\n...This is the valid Credit Card Number...\n\n";
}
else
{
cout << ".\n.\n.\n.\n.\n.\n\nError Error :Invalid Card Number\n\nPlease Enter the valid Card Number...\n.\n.\n";
}
return 0;
}
