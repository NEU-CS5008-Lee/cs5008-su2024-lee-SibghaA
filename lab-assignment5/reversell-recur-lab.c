//Sibgha Ahmad
//ahmad.si@northeastern.edu
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef struct list{
    struct node* head;
}List;

/*-----creating the nodes----------*/
node_t* newNode(int num)
{
  node_t *newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL){
    printf("Memory not allocated\n");
    exit(1);
  }
  newNode->data = num;
  newNode->next=NULL;
  return newNode;
 
}
/*---creating linked list----*/
List* init_LL(){
    List* l = (List*)malloc(sizeof(List));
    if(l == NULL){
      printf("Memory not allocated\n");
      exit(1);
    }
    l->head = NULL;
    return l;
}

/*---Insert the nodes at the begining of the list---*/
void insertFirst(List* l, int data){
    node_t* temp = newNode(data);
    if(l->head == NULL){
      l->head = temp;
      return;
    }
    temp->next = l->head;
    l->head = temp;

}

/*----display the output--------*/
void display(List* l)
{
    node_t *temp;
    temp=l->head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverse(List* l, node_t* ptr)
{
    //insert your code here
    if((l->head == NULL) || (l->head->next == NULL)){
      return;
    }
    node_t* prev = NULL;
    node_t* curr = l->head;
    node_t* suc = NULL;
    while(curr != NULL){
      suc = curr->next;
      curr->next = prev;
      prev = curr;
      curr = suc;
    }
    l->head = prev;
    
    
}

/*----Free the nodes-----*/
void freenode(List* l){
  node_t *temp;
    while(l->head)
    {
        temp=l->head->next;
        free(l->head);
        l->head=temp;
    }  
    
}
/*-----Main program--------------*/
int main()
{
    List *list=init_LL();
    

    insertFirst(list,44);
    insertFirst(list,33);
    insertFirst(list,22);
    insertFirst(list,11);
    display(list);
    reverse(list,list->head);
    display(list);
    
    freenode(list);
    free(list);
    return 0;
}
