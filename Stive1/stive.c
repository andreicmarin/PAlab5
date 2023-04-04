#include "stive.h"

Data topVal(Node *top) ////Funcția topVal returnează valoarea stocată în vârful stivei.
//Dacă stiva este goală, se returnează CHAR_MIN
{
    if (isEmpty(top)) return CHAR_MIN;
    return top->val;
}

void push(Node**top, Data v) //Funcția push adaugă o valoare la începutul stivei. 
//Se alocă memorie pentru un nou nod al stivei, se setează valoarea acestuia la v,
//se setează legătura dintre noul nod și nodul precedent (vârful stivei) și se actualizează vârful stivei.
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;
}

Data pop(Node**top) //Funcția pop elimină valoarea din vârful stivei și o returnează. 
//Se verifică dacă stiva este goală și, dacă este cazul, se returnează CHAR_MIN. Altfel, 
//se alocă memorie pentru un nod temporar care să reprezinte vârful stivei, se salvează valoarea acestuia într-o variabilă auxiliară, 
//se actualizează vârful stivei și se eliberează memoria ocupată de nodul temporar.
{
    if (isEmpty(*top)) return CHAR_MIN;
    Node *temp=(*top);
    Data aux=temp->val;
    *top=(*top)->next;
    free(temp);
    return aux;
}

bool isEmpty(Node *top) //Funcția isEmpty verifică dacă stiva este goală, adică dacă vârful stivei este NULL
{
    return top==NULL;
}

void deleteStack(Node**top) //Funcția deleteStack elimină toate elementele din stivă și eliberează memoria ocupată de acestea. 
//Se parcurge stiva și se elimină elementele unul câte unul
{
    Node  *temp;
    while (!isEmpty(*top))
    {
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}

void writeStack(Node **top) //Funcția writeStack afișează valorile stocate în stivă, în ordinea inversă față de ordinea în care au fost adăugate. 
//Se aloca memorie pentru un buffer, se parcurge stiva și se adaugă valoarea fiecărui element la sfârșitul buffer-ului
{
    Data * buf = malloc(1*sizeof(Data));
    int i = 0;
    while(isEmpty(*top)== false)
    {
        buf[i] = pop(top);
        i++;
        buf = realloc(buf,(i+1)*sizeof(buf));
    }
    buf[i] = '\0';
    Data * buff = malloc(strlen(buf)*sizeof(Data));
    for(int j = 0; j<=strlen(buf)-1; j++)
        buff[strlen(buf)-1-j] = buf[j];
    buff[strlen(buf)] = '\0';
    free(buf);
    printf("%s",buff);
    free(buff);
} //Se eliberează memoria ocupată de elementele stivei și se afișează buffer-ul în ordine inversă, pentru a afișa valorile stocate în ordinea corectă

void fillStack(Node **top, Data * buf) //Funcția fillStack adaugă valorile dintr-un buffer în stivă. 
//Se parcurge buffer-ul și se adaugă fiecare valoare în stivă folosind funcția push
{
    for(int i=0; i<=strlen(buf)-1; i++)
        push(top,buf[i]);
}
