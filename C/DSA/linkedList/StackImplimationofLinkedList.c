#include <stdio.h>
#include <stdlib.h>

struct node{                        // struct of Node 
    int info;
    struct node * link;
};
struct node *Head,*p,*start,*temp;
 
void insertionAtTheBeginning(int n){                  // Insertion 
    int i;
    start =NULL;
    for(i=0;i<n;i++){                       
        p = (struct node*) malloc(sizeof(struct node));        // Address of the first node
        printf("Enter in The Info Part (%d node):- ",i+1);     // Adding info to that node
        scanf("%d",&p->info);                                  
        if(start==NULL){                                       // If The node is first
            start = p;                                           // Start = p
            Head  = p;                                          // Head = p 
            Head->link =NULL;
        }
        else{
            p->link = Head;
            Head =p;
        }
    }
    start = Head;
    
}
void DeletionAtTheBeginning(){
    temp = Head;
    Head = Head->link;
    start = Head;
    printf("Deleted Node = [%d | %p]\n",temp->info,temp->link);
    free(temp);
}
void Display(){
    printf("List after insertion is : \n");
    printf("[Start | %p] ----> ",start);
    while(Head!=NULL)
    {
        printf("[%d | %p] ----> ",Head->info,Head->link);
        Head=Head->link;
    }
    printf("[End]");
    
    
}

int main(){
    int n;
    printf("Enter the Number of Nodes :- ");
    scanf("%d",&n);
    insertionAtTheBeginning(n);
    Display();
    Head = start;
    printf("\n");
    DeletionAtTheBeginning();
    Display();
}
