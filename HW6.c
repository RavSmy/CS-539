#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int zipcode;
    char address[100]; 
    char name[100];
    char city[100];
    struct node *next; 
}node;

void add(struct node**);
void sort(struct node**);

void display(struct node *);

int main(void){

    struct node *list = NULL;

    add(&list);
    sort(&list);
    display(list);
}

void sort(struct node **head){
/*
counter = 0; look at two zipcodes. Compare the numbers. If first is bigger tahn second swap function and set swap counter to non-zero. 
Keep sortng through the whole list until sweap counter - 0
*/

struct node *prev, *a, *after, *temp= malloc(sizeof(struct node));;

int swapped = 1;

//** not smaller numbers

while (swapped!=0){
    swapped = 0;
    prev = *head; 
    a = prev->next;
    after = a->next; 

    while(a!=NULL){          
  
        if(prev->zipcode > a->zipcode){
             temp->next = prev->next;
             prev->next = a->next;
             a->next = after->next;
             after->next = temp->next;    
             swapped = 1;                    
        }//if
        
        prev = prev->next;
        a = a->next;
        after = after->next; 

    }//while
    
}//while 



}

void add(struct node **head){
    
    struct node *temp, *rear;
    int i =0, zipcode;
    char address[100], name[100], city[100];
    
    while(scanf("first line: %[^\n]\nsecond line: %[^\n]\nthird line: %[^\n]\nfourth line: %d", name, address, city, &zipcode) != EOF){
      temp = malloc(sizeof(struct node));
      getchar(); 
       
      temp->zipcode = zipcode;        
      strcpy(temp->address, address);
      strcpy(temp->city, city);
      strcpy(temp->name, name);
      temp->next = NULL; 
       
      if(*head == NULL){
        *head = temp;  
      }else{
        rear->next = temp; 
      }

      rear = temp; 
      i++;     

    };   
    
}

void display(struct node *p)
{ 
    
    while (p != NULL)
    {
        printf("%s\t%s\t%s\t%d\n", p->name, p->address, p->city, p->zipcode);
        p = p->next;
    }
    printf("\n");
}
