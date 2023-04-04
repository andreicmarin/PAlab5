#include "stive.h"

int main()
{
    Node * top = NULL;

    if(isEmpty(top) == true) printf("Stiva goala\n");
    else printf("Stiva nu e goala.\n");

    push(&top,'p');
    push(&top,'e');
    push(&top,'p');
    push(&top,'s');
    push(&top,'i');

    if(isEmpty(top) == true) printf("Stiva goala.\n");
    else printf("Stiva nu e goala.\n");

    writeStack(&top); //Se afișează conținutul stivei prin apelul funcției "writeStack", 
    //care va afișa elementele în ordinea în care au fost adăugate
    printf("\n");

    if(isEmpty(top) == true) printf("Stiva goala.\n");
    else printf("Stiva nu e goala.\n");

    push(&top,'a');
    //Se adaugă două elemente noi în stivă prin apelul funcției
    push(&top,'a');

    if(isEmpty(top) == true) printf("Stiva goala.\n");
    else printf("Stiva nu e goala.\n");

    deleteStack(&top); //Se șterge conținutul stivei

    if(isEmpty(top) == true) printf("Stiva goala.\n");
    else printf("Stiva nu e goala.\n");

    Data * buf = malloc(30*sizeof(Data)); //Se alocă memorie pentru un buffer de dimensiune 30, 
    //care va fi folosit pentru a citi date de la tastatură prin apelul funcției "fgets"

    fgets(buf,30,stdin);
    buf = realloc(buf,strlen(buf)+1);
    fillStack(&top,buf); //Se adaugă elementele citite în stivă prin apelul funcției "fillStack"
    writeStack(&top); //se afișează conținutul stivei prin apelul funcției "writeStack"

    return 0;
}
