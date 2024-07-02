// name: Sibgha Ahmad
// email: ahmad.si@northeastern.edu


// please start with a copy of your hw7.c, rename it to hw.8
// and then complete the assignment
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTRING 200
#define TABLE_SIZE 100

typedef struct Node {
  char city[MAXSTRING];
  int population;
  struct Node* next;
} Node;

typedef struct HashTable {
  Node* table[TABLE_SIZE];
} HashTable;

#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

bool isDigit(char c){
  return '0' <= c && c <= '9';
}

void appendChar(char* s, char c){
  char charToStr[2];
  charToStr[0] = c;
  charToStr[1] = '\0';
  strcat(s, charToStr);
}

void initTable(HashTable* ht){
  for(int i = 0; i < TABLE_SIZE; i++){
    ht->table[i] = NULL;
  }
}

Node* createNode(const char* city, int population){
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->city, city);
  newNode->population = population;
  newNode->next = NULL;
  return newNode;
}

int hashFunction1(const char* city){
  int len = strlen(city);
  return len % TABLE_SIZE;
}

int hashFunction2(const char* city){
  int sum = 0;
  for(int i = 0; city[i] != '\0'; i++){
    sum += city[i];
  }
  return sum % TABLE_SIZE;
}

int hashFunction3(const char* city){
  int product = city[0] * city[1];
  return product % TABLE_SIZE;
}

void insert(HashTable* ht, const char* city, int population, int (*hashFunc)(const char*)){
  int index = hashFunc(city);
  Node* newNode = createNode(city, population);

  if(ht->table[index] == NULL){
    ht->table[index] = newNode;
  } else {
      Node* temp = ht->table[index];
      while(temp != NULL){
        if(strcmp(temp->city, city) == 0){
	  temp->population = population;
	  free(newNode);
	  return;
	}
	if(temp->next == NULL){
	  break;
	}
	temp = temp->next;
      }
      temp->next = newNode;
  }
}

void printTable(HashTable* ht, int tableNumber){
  
  printf("==============================\n\n");
  printf("***** HASH TABLE %d *****\n\n", tableNumber);
  printf("==============================\n\n");

  for(int i = 0; i < TABLE_SIZE; i++){
    printf("TABLE[%d]:\n", i);
    if(ht->table[i] != NULL) {
      Node* temp = ht->table[i];
      while(temp != NULL){
        printf("key/value: [%s] / [%d]\n", temp->city, temp->population);
	temp = temp->next;
      }
    }
  }
}

int main(){
  char inputLine[MAXSTRING];
  char cityStr[MAXSTRING];
  int lineNum;
  int popInt;
  int state;
  int nextChar;
  char temp[MAXSTRING];

  HashTable ht1,ht2,ht3;
  initTable(&ht1);
  initTable(&ht2);
  initTable(&ht3);

  FILE* fp;
  fp = fopen("pop.csv", "r");

  if(fp != NULL){
    fgets(inputLine, MAXSTRING, fp);

    while (feof(fp) == 0){
      nextChar = 0;
      state = STARTSTATE;
      strcpy(temp,"");

      if(nextChar >= strlen(inputLine)){
        state = ERRORSTATE;
      }

      while((state != ERRORSTATE) && (state != ACCEPTSTATE)){
        switch (state){
	  case STARTSTATE:
            if(isDigit(inputLine[nextChar])){
	      state = S1;
	      appendChar(temp, inputLine[nextChar]);
	    } else {
	        state = ERRORSTATE;
	    }
	    break;
	  case S1:
	    if(isDigit(inputLine[nextChar])){
	      appendChar(temp, inputLine[nextChar]);
	    } else if (inputLine[nextChar] == ','){
	        state = S2;
		lineNum = atoi(temp);
		strcpy(temp, "");
	    } else {
	        state = ERRORSTATE;
	    }
	    break;

	  case S2:
	    if(inputLine[nextChar] == '"'){
	      state = S3;
	    } else {
	        state = ERRORSTATE;
	    }
	    break;

	  case S3:
	    if (inputLine[nextChar] != '"'){
	      appendChar(temp, inputLine[nextChar]);
	    } else {
	        state = S4;
		strcpy(cityStr, temp);
		strcpy(temp, "");
	    }
	    break;

	  case S4:
	    if(inputLine[nextChar] == ','){
	      state = S5;
	    } else {
	        state = ERRORSTATE;
	    }
	    break;

	  case S5:
	    if(inputLine[nextChar] == '"'){
	      state = S6;
	    } else if(inputLine[nextChar] == '('){
	        state = ACCEPTSTATE;
		popInt = 0;
	    } else {
	        state = ERRORSTATE;
	    }
	    break;

	  case S6:
	    if(isDigit(inputLine[nextChar])){
	      appendChar(temp, inputLine[nextChar]);
	    } else if(inputLine[nextChar] == ','){
	    } else if(inputLine[nextChar] == '"'){
	        state = ACCEPTSTATE;
		popInt = atoi(temp);
	    } else {
	        state = ERRORSTATE;
	    }
	    break;

	  case ACCEPTSTATE:
	    break;

	  default:
	    state = ERRORSTATE;
	    break;
	}
	nextChar++;
      }

      insert(&ht1, cityStr, popInt, hashFunction1);
      insert(&ht2, cityStr, popInt, hashFunction2);
      insert(&ht3, cityStr, popInt, hashFunction3);

      fgets(inputLine, MAXSTRING, fp);
    }

    fclose(fp);
    
   
   
    printTable(&ht1, 1);
    printTable(&ht2, 2);
    printTable(&ht3, 3);
  }

  return 0;
}



