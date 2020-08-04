#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //declared variables with starting values
    int x = 0;
    string key;
    int keyLen = 0;
    bool isgoodkey = false;
    //prints total number of arguments(the name of program)
    printf("Number of Arguments %d\n", argc);
    //counts arguments and prints them
    for(int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    //if the number of arguments is not equal to 2, then the program will result in an error
    if (argc != 2)
    {
        printf("Please pass exactly one argument for the key, program will exit\n");
        return 1;
    }
    //converts second argument from alpha to integer and prints the key value
    int intkey = atoi(argv[1]);
    printf("keyvalue: %d\n", intkey);

    /*
    for (int y = 0; isgoodkey==false; y++)
    {
    */
        //key = get_string("./caesar ");
        // assigns variable key to the second argument
        key = argv[1];
        //uses the function strlen on the variable key to find the length
        keyLen = strlen(key);
        //if the key is not a digit, then an error will be printed and the program will exit
        for (x = 0; x < keyLen; x++)
        {
            if (!isdigit(key[x]))
            {
                printf("Usage: ./caesar key\n");
                isgoodkey = false;
                //break;
                return 1;
            }

        }// end of For-loop

    /*
        if (x==keyLen)
        {
            isgoodkey = true;
        }

    }// end of For-loop
    */
//if user inputs a negative number, the program will print an error and exit
if (intkey < 0)
    {
        printf("Key must be greater than 0\n");
        return 1;
    }
//converts the key variable from string to integer
    intkey = atoi(key);
    printf("Key is Good: %d\n", intkey);
//declared integer i
    int i, messagep;
    string plaintext = get_string("plaintext: ");
//declares many variables
    int mod;
    char chr;
    int diff;
    int chrascii;
    long sum;
    //if the plaintext is not equal to null, then the loop will keep running
    for(i = 0; plaintext[i] != '\0'; i++)
    {
       //assigns each character in the plaintext to the vriable chr
       chr = plaintext[i];
       //converts chr into integer and assigns it to variable chrascii
       chrascii = (int)chr;

       if(chr >= 'a' && chr <= 'z')
       {
           //adds key to each character in the text
           sum = chrascii + intkey;

           if(sum > 'z')
           {
               //if the resulting sum is greater than z, then the program will find the difference of the sum and the value of z
               diff = sum - 'z';
               printf("Diff %d\n", diff);
               //takes the difference and finds the remainder from dividing the difference and the number 26
               mod = diff % 26;
               printf("mod %d\n", mod);
               if(mod == 0)
               {
                   //if the remainder is 0, then the encrypted character will automatically be z
                   plaintext[i] = 'z';
               }
               else
               {
                   //if the remainder is not 0, then the program will use the remainder in the formula to get the encrypted character
                   sum = 'a' + mod - 1;
                   printf("chr %c\n", chr);
                   plaintext[i] = sum;
               }
           }

           else
           {   //assigns the sum value to each character to create a new encrypted character
               plaintext[i] = sum;
           }

       }
       else if(chr >= 'A' && chr <= 'Z')
       {
           //adds key to each character in the text
           sum = chrascii + intkey;

           if(sum > 'Z')
           {
               //if the resulting sum is greater than z, then the program will find the difference of the sum and the value of Z
               diff = sum - 'Z';
               printf("Diff %d\n", diff);
               //takes the difference and finds the remainder from dividing the difference and the number 26
               mod = diff % 26;
               printf("mod %d\n", mod);
               if(mod == 0)
               {
                   //if the remainder is 0, then the encrypted character will automatically be Z
                   plaintext[i] = 'Z';
               }
               else
               {
                   //if the remainder is not 0, then the program will use the remainder in the formula to get the encrypted character
                   sum = 'A' + mod - 1;
                   printf("chr %c\n", chr);
                   plaintext[i] = sum;
               }
           }
           else
           {
               //assigns the sum value to each character to create a new encrypted character
               plaintext[i] = sum;
           }
       } //if(chr >= 'a' && chr <= 'z')
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
