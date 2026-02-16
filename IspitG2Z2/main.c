#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char* stringEntry(){
    int size = 0, capacity = 10;
    char *str = malloc(capacity);
    if(!str) return NULL;
    int c;
    while((c = getchar()) != '\n' && c != EOF){
        str[size++] = c;
        if(size>=capacity - 1){
            capacity*=2;
            char *temp = realloc(str,capacity);
            if(!temp){
                free(str);
                return NULL;
            }
            str = temp;
        }
    }
    str[size] = '\0';
    return str;
}
char toUpper(char c){
    if(c>='a' && c<='z')
        return c - 32;
    return c;
}
int Hex(char c){
    if(toUpper(c)>='A' && toUpper(c)<='F'){
        return toUpper(c) - 55;
    }else if(c>='0' && c<='9'){
        return c - '0';
    }
    return 17;
}
void write(char *str,int *w,int streakStart,int streak){
    int  i = 0;
    while(i < streak ){
        str[*w] = str[streakStart+i];
        (*w)++;
        i++;
    }
    str[(*w)++] = ' ';
}
void iterate(char *str,int start,int end,int *w){
    int wordStart=0,wordEnd=0,i = start+1,before = str[start],streak = 1,maxStreak = 0,streakStart = 0;
    while(i != end){
        if((Hex(before) > Hex(str[i])) && Hex(before) != 17 && Hex(str[i])!= 17){
            streak++;
        }else{
            if(streak > maxStreak){
                maxStreak = streak;
                streakStart = i - streak;
            }
            streak = 1;
        }
        before = str[i];
        i++;
    }
    if(streak > maxStreak){
                maxStreak = streak;
                streakStart = i - streak;
    }
    if(maxStreak >= 2){
        write(str,w,streakStart,maxStreak);
    }
}
int main(){
    char *str = stringEntry();
    //char *str = "a3bc9 fedcba hello 9C4x xyz\0";
    int i=0, wordStart = 0, wordEnd = 0,write = 0;
    int *w = &write;
    while(str[i]){
        if(str[i] == ' '){
            wordEnd = i;
            iterate(str,wordStart,wordEnd,w);
            wordStart = i+1;
        }
        i++;
    }
    wordEnd = i-1;
    iterate(str,wordStart,wordEnd,w);

    char *temp = realloc(str,(*w));
    if(!temp){
        free(str);
        return 1;
    }
    temp[*w] = '\0';
    str = temp;
    printf("%s",str);
    free(str);
    return 0;
}
/*Napisati program koji uˇcitava string koji sadrˇzi reˇci sastavljene od velikih slova, malih slova i cifara,
razdvojene jednim ili viˇse razmaka (mogu postojati vode ́ci i zaostali razmaci). Program treba da modifikuje string
tako ˇsto:
• U svakoj reˇci pronalazi najduˇzu sekvencu uzastopnih heksadecimalnih cifara (0-9, a-f, A-F) koje se nalaze u
strogo opadaju ́cem redosledu (svaka slede ́ca cifra mora biti strogo manja od prethodne, velika slova se tretiraju
isto kao mala).
• Sve ostale karaktere te reˇci briˇse, ostavljaju ́ci samo tu najduˇzu sekvencu.
• Ako ima viˇse sekvenci iste maksimalne duˇzine, zadrˇzava prvu.
• Reˇci kod kojih nema takve sekvence duˇzine bar 2 se u celosti briˇsu iz stringa.
• Na kraju, izmedu reˇci ostaje taˇcno jedan razmak i nema vode ́cih/zaostalih razmaka.
Napomena: Nije dozvoljeno koriˇs ́cenje pomo ́cnih stringova/nizova.
Primer:
Ulaz: a3bc9 fedcba hello 9C4x xyz
Izlaz: a3 fedcba c4*/
