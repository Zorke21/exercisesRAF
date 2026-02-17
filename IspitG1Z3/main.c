#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Element {
    char symbol[5];
    int atomNum;
    struct Element *next;
} Element;
Element* createElement(char* symbol,int atomNum){
    Element* newElement = malloc(sizeof(Element));
    strcpy(newElement->symbol,symbol);
    newElement->atomNum = atomNum;
    newElement->next = NULL;
    return newElement;
}
Element* insertElement(Element* head,Element* newElement){
    if(!head){
        return newElement;
    }

    if(head->atomNum > newElement->atomNum){
        newElement->next = head;
        return newElement;
    }

    Element* temp = head;
    while(temp->next && temp->next->atomNum < newElement->atomNum){
        temp = temp->next;
    }

    newElement->next = temp->next;
    temp->next = newElement;

    return head;
}
Element* loadFile(){
    Element* head = NULL;
    FILE* fp = fopen("elementi.txt","r");

    if(!fp){
        printf("Error when opening the file");
        return 0;
    }

    char line[255],symbol[5];
    char* token;
    int atomNum;

    while(fgets(line,sizeof(line),fp)){
        token = strtok(line,",");
        strcpy(symbol,token);
        token = strtok(NULL,",");
        atomNum = atoi(token);
        head = insertElement(head,createElement(symbol,atomNum));
    }
    fclose(fp);
    return head;
}
void printList(Element *list){
    if(list == NULL){
        printf("The list is empty");
        return;
    }
    //if(mode){
        printList(list->next);
        printf("%s - %d \n",list->symbol,list->atomNum);
    /*}else{
        Element *temp;
        temp = list;
        while(temp){
            printf("%s - %d \n",temp->symbol,temp->atomNum);
            temp = temp->next;
        }
    }*/
}

int elementCountBetween(Element *list, int fromNum, int toNum){
    int count = 0;

    while(list){
        if(list->atomNum >= fromNum && list->atomNum <= toNum){
            count++;
        }
        list = list->next;
    }

    return count;
}

void deleteLesser(Element **list, int atomNum){
    if(!(*list)){
        printf("The list is empty");
        return;
    }
    while((*list) && (*list)->atomNum < atomNum){
        Element* forDel = *list;
        *list = (*list)->next;
        free(forDel);
        forDel = NULL;
    }
    Element *temp = *list;
    while(temp && temp->next){
        if(temp->next->atomNum < atomNum){
            Element* forDel = temp->next;
            temp->next = temp->next->next;
            free(forDel);
            forDel = NULL;
        }else{
            temp = temp->next;
        }
    }
}

void deleteList(Element **list){
    if(!(*list)){
        printf("The list is empty");
        return;
    }
    while((*list)){
        Element* forDel = *list;
        *list = (*list)->next;
        free(forDel);
        forDel = NULL;
    }
}

int main(){
    int fromNum,toNum, deletionNum;
    Element *head = NULL;
    head = loadFile();
    printf("\n");
    printList(head);
    printf("Enter the atomic number range: ");
    scanf("%d %d", &fromNum,&toNum);
    printf("Count of atomic numbers in the range of %d-%d: %d \n", fromNum,toNum,elementCountBetween(head,fromNum,toNum));
    printf("Num for lesser deletion\n");
    scanf("%d",&deletionNum);
    deleteLesser(&head,deletionNum);
    printList(head);
    deleteList(&head);
    printList(head);
    return 0;
}
/*Deklarisana je struktura Element na slede ́ci naˇcin:
typedef struct Element {
char simbol[5];
int atomskiBroj;
struct Element *sledeci;
} Element;
U tekstualnoj datoteci “elementi.txt“ nalazi se lista hemijskih elemenata i njihovih atomskih brojeva. Svaki red
datoteke sadrˇzi simbol elementa i atomski broj razdvojene zarezom.
U fajlu zadatka (koji se kompajlira ali ne radi niˇsta) je dat ˇsablon za funkcije koje treba implementirati (ne
menjati im potpis!) i glavni program koji ne treba menjati. Implementirati slede ́ce funkcije (dozvoljeno je dodavati
i pomo ́cne funkcije):
a) (10p) Element* ucitajFajl() - Uˇcitava datoteku u jednostruko povezanu listu i vra ́ca pokazivaˇc na poˇcetak

liste. Sve elemente iz datoteke prilikom uˇcitavanja sortirati rastu ́ce po atomskom broju (elementi sa manjim atom-
skim brojem na poˇcetku liste). Elemente sa istim atomskim brojem sortirati alfabetski rastu ́ce po simbolu. Voditi

raˇcuna o praznom redu na kraju datoteke. Ako je lista prazna, njen poˇcetak je NULL.
b) (2p) void ispisiListu(Element *lista) - Ispisuje sve elemente iz liste sortirano po atomskom broju
opadaju ́ce (tj. od kraja ka poˇcetku). Ispis na ekranu moˇze biti u formatu kao iz datoteke. Ispis od poˇcetka do kraja
umesto od kraja do poˇcetka vredi 50% poena.
c) (5p) int brojElemenata(Element *lista, int odBroja, int doBroja) - Vra ́ca broj elemenata u listi
ˇciji se atomski broj nalazi izmedu zadatih brojeva (ukljuˇcuju ́ci i graniˇcne vrednosti).
d) (6p) void izbaciLake(Element **lista, int atomskiBroj) - Izbacuje iz liste sve elemente ˇciji je atomski
broj strogo manji od zadatog atomskog broja. Voditi raˇcuna da su elementi pravilno obrisani (da je oslobodena
memorija). Ako je obrisana cela lista, posle ove funkcije trebalo bi da postane NULL.

e) (2p) void brisanje(Element **lista) - Briˇse sve elemente liste (oslobada svu zauzetu memoriju), posta-
vlja poˇcetak liste na NULL.

Primer ispisa za tre ́ci zadatak:
Poˇcetak ispisa:
H, 1
He, 2
Li, 3
Be, 4
B, 5
C, 6
N, 7
O, 8
...
U, 92
Kraj prvog ispisa:
U, 92
Pb, 82
Au, 79
Ag, 47

2

Zn, 30
Cu, 29
Fe, 26
Ca, 20
...
He, 2
H, 1
Broj elemenata sa atomskim brojem izmedju 5 i 10: 6
Broj elemenata sa atomskim brojem izmedju 1 i 20: 20
Posle izbacivanja elemenata sa atomskim brojem manjim od 20:
Ca, 20
Fe, 26
Cu, 29
Zn, 30
Ag, 47
Au, 79
Pb, 82
U, 92
Posle brisanja:
(nil)*/
