//enter your email here: ahmad.si@northeastern.edu
//enter your name here: Sibgha Ahmad

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    //insert your code here
    //edge case if n < 2
   if(n < 2){
     if(n == 1) {
       res[0] = arr[0];
       return 1;
     }
     return 0;
   
   }
   int i = 1;
   int count = 1;
   int index = 1;
   char curr = arr[0];
   char r[10];
   while(i <= n){
  
   //check if current character is equal to the next character, if not, then store the current character in res array and store count in res array
   //put the character  in res array
   //put the count in the res array if the count is greate than 1
     if(arr[i] == curr){
       count++;
     } else {
         res[index++] = curr;
	 if(count > 1){
	   sprintf(r, "&d", count);
	   for(int j = 0; r[j] != '\0'; j++){
	     res[index++] = r[j];
	   }
	 }
	 curr = arr[i];
	 count = 1;
     }
     i++;
   }

   res[index++] = curr;
   if(count > 1){
     sprintf(r, "%d", count);
     for(int j = 0; r[j] != '\0'; j++){
       res[index++] = r[j];
     }
   }
   //display the compressed string
   // for(int i = 0; i < index; i++){
   //  printf("%c", res[i]);
   //}
   // return the length of compressed string
   //printf("\n");
   return index;
   
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
