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
char toUpper(char c){
    if(c>='a' && c<='z')
        return c - ('a' - 'A');
    return c;
}
void wordStreak(char *str,int start,int end,int *w){
    int streak = 1,maxStreak = 1,streakStart = start;
    char before = '\0';
    for(int i = start + 1;i<=end;i++){
        before = str[i-1];
        if(before == '\0'){
            before = str[i];
            continue;
        }
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
            if(toUpper(str[i]) > toUpper(before)){
                streak++;
            }
            else{
                if(streak > maxStreak){
                maxStreak = streak;
                streakStart = i - streak;
                }
                streak = 1;
            }


        }
    }
    if(streak >  maxStreak){
                    maxStreak = streak;
                    streakStart = end - streak + 1;
                }

    for(int i = streakStart;i < streakStart + maxStreak; i++){
        str[(*w)++] = str[i];
    }
    str[(*w)++] = ' ';
}
int main()
{

    char *str = stringEntry();
    int i = 0,wordStart = 0,wordEnd = 0,w;
    int *w = 0;
    while(str[i]){
        if(str[i] == ' ' || str[i] == '\0'){
            wordEnd = i-1;
            wordStreak(str,wordStart,wordEnd,w);
            wordStart = i+1;
        }
        i++;
    }
    wordEnd = i - 1;
    wordStreak(str,wordStart,wordEnd,w);
    printf("%s",str);
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
