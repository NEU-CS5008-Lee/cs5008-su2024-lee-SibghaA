//Sibgha Ahmad
//ahmad.si@northeastern.edu
#include<stdio.h>
int main()
{
    int a,b, choice;
    float answer;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values\n");
    scanf("%d %d", &a, &b);
    
    // Add your code here using switch
    switch(choice) {
    	case 1:
		answer = a + b;
		printf("Sum: %.2f\n", answer);
		break;
	case 2:
		answer = a - b;
		printf("Difference: %.2f\n", answer);
		break;
	case 3:
		answer = a * b;
		printf("Product: %.2f\n", answer);
		break;
	case 4:
		if (b == 0){
		printf("Error: divide by zero\n");
		break;
		}
		answer = (float) a / b;
		printf("Quotient: %.2f\n", answer);
		answer = a % b;
		printf("Remainder: %.2f\n", (float)answer);
		break;
	default:
		printf("Invalid option\n");
		break;
    }
           
    return 0;
}

