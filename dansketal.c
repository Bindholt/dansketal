#include <stdio.h>
#include <string.h>
#include "dansketal.h"

char *ones[] = {"", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"};
char *teens[] = {"ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
char *tens[] = {"", "ti", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};

void dansketal(int number, char *s) 
{
    if (number < 0) {
        printf("minus ");
        number = -number;
    }

    if (number == 0) {
        sprintf(s, "nul");
    } else if (number < 10) {
        write_ones(number, s);
    } else if (number < 20) {
        write_teens(number, s);
    } else if(number < 100) {
        write_tens(number, s);
    } else if(number < 1000) {
        write_hundreds(number, s);
    } else if(number < 1000000) {
        write_thousands(number, s);
    } else if(number < 1000000000) {
        write_millions(number, s);
    } else if(number < 2147483647) {
        write_billions(number, s);
    } else{
        sprintf(s, "Number is too large");
    }
}

void write_ones(int number, char *s) {
    sprintf(s, "%s", ones[number]);
}

void write_teens(int number, char *s) {
    sprintf(s, "%s", teens[number - 10]);
}

void write_tens(int number, char *s) {
    if (number % 10 == 0) {
        sprintf(s, "%s", tens[number / 10]);
    } else {
        sprintf(s, "%sog%s", ones[number % 10], tens[number / 10]);
    }
}

void write_hundreds(int number, char *s) {
    int hundreds = number / 100;
    int remainder = number % 100;
    char buffer[256] = "";

    if (hundreds > 0) {
        strcat(buffer, (hundreds == 1) ? "et" : ones[hundreds]);
        strcat(buffer, "hundrede");
    }

    if (remainder > 0) {
        strcat(buffer, " og ");
        if (remainder < 10) {
            strcat(buffer, ones[remainder]);
        } else if (remainder < 20) {
            strcat(buffer, teens[remainder - 10]);
        } else {
            char tens_str[50];
            write_tens(remainder, tens_str);
            strcat(buffer, tens_str);
        }
    }

    strcpy(s, buffer);
}

void write_thousands(int number, char *s) {
    int thousands = number / 1000;
    int remainder = number % 1000;
    char buffer[256] = "";

    if (thousands > 0) {
        if(thousands < 10) {
            (thousands == 1) ? strcat(buffer, "et") : strcat(buffer, ones[thousands]);
            strcat(buffer, " tusind ");        
        }
        else if (thousands < 100) {
            char thousands_str[256];
            write_tens(thousands, thousands_str);
            strcat(buffer, thousands_str);
            strcat(buffer, " tusind ");
        }
        else if (thousands < 1000) {
            char thousands_str[256];
            write_hundreds(thousands, thousands_str);
            strcat(buffer, thousands_str);
            strcat(buffer, " tusind ");
        }
    }

    if (remainder > 0) {
        char hundreds_str[256];
        write_hundreds(remainder, hundreds_str);
        strcat(buffer, hundreds_str);
    }

    strcpy(s, buffer);
}

void write_millions(int number, char *s) {
    int millions = number / 1000000;
    int remainder = number % 1000000;
    char buffer[256] = "";

    if (millions > 0) {
        if (millions < 10) {
            strcat(buffer, ones[millions]);
            (millions == 1) ? strcat(buffer, " million ") : strcat(buffer, " millioner ");
        }
        else if (millions < 100) {
            char millions_str[256];
            write_tens(millions, millions_str);
            strcat(buffer, millions_str);
            strcat(buffer, " millioner ");
        }
        else if (millions < 1000) {
            char millions_str[256];
            write_hundreds(millions, millions_str);
            strcat(buffer, millions_str);
            strcat(buffer, " millioner ");
        }
    }

    if (remainder > 0) {
        char thousands_str[256];
        write_thousands(remainder, thousands_str);
        strcat(buffer, thousands_str);
    }

    strcpy(s, buffer);
}

void write_billions(int number, char *s) {
    int billions = number / 1000000000;
    int remainder = number % 1000000000;
    char buffer[256] = "";

    if (billions > 0) {
        if (billions < 10) {
            strcat(buffer, ones[billions]);
            (billions == 1) ? strcat(buffer, " milliard ") : strcat(buffer, " milliarder ");
        }
        else if (billions < 100) {
            char billions_str[256];
            write_tens(billions, billions_str);
            strcat(buffer, billions_str);
            strcat(buffer, " milliarder ");
        }
        else if (billions < 1000) {
            char billions_str[256];
            write_hundreds(billions, billions_str);
            strcat(buffer, billions_str);
            strcat(buffer, " milliarder ");
        }
    }

    if (remainder > 0) {
        char millions_str[256];
        write_millions(remainder, millions_str);
        strcat(buffer, millions_str);
    }

    strcpy(s, buffer);
}