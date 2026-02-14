#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char* stringEntry(){
    int size=0,capacity = 10;
    char *str = malloc(capacity);
    if(!str) return NULL;

    int c;

    while((c = getchar()) != '\n' && c!=EOF){
        str[size++] = c;

        if(size >= capacity){
            capacity*=2;
            str = realloc(str,capacity);
            if(!str) return NULL;
        }


    }

    str[size] = '\0';
    return str;
}
char* stringShift();


char toUpper(char c){
    if(c>='a' && c<='z')
        return c - ('a' - 'A');
    return c;
}
int main()
{

    char *str = stringEntry();
    char before = '\0';
    int i = 0,write=0,wordStart = 0,wordEnd = 0,streak=1,maxstreak=1,streakStart=0;
    while(str[i]){
        if(before == '\0' || before == ' '){

        }
    }
    free(str);
    return 0;
}
/*Napisati program koji uˇcitava string koji sadrˇzi reˇci sastavljene od velikih i malih slova, razdvojene
jednim ili viˇse razmaka (mogu postojati vode ́ci i zaostali razmaci). Program treba da modifikuje string tako ˇsto:
• U svakoj reˇci pronalazi najduˇzu sekvencu uzastopnih karaktera koji se nalaze u strogo rastu ́cem alfabetskom
redosledu (svaki slede ́ci karakter mora biti strogo ve ́ci od prethodnog, velika slova se tretiraju isto kao mala).
• Sve ostale karaktere te reˇci briˇse, ostavljaju ́ci samo tu najduˇzu sekvencu.
• Ako ima viˇse sekvenci iste maksimalne duˇzine, zadrˇzava prvu.
• Reˇci kod kojih nema takve sekvence duˇzine bar 2 se u celosti briˇsu iz stringa.
• Na kraju, izmedu reˇci ostaje taˇcno jedan razmak i nema vode ́cih/zaostalih razmaka.
Napomena: Nije dozvoljeno koriˇs ́cenje pomo ́cnih stringova/nizova.
Primer:
Ulaz: HeLLo WoRLd TeST AbC zzAbC
Izlaz: eL oR eST AbC AbC*/
