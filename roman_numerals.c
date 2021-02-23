// Roman Numerals
// Ask user for a number
// Convert number to roman numerals

#include <stdio.h>

typedef struct {
   char *sym;
   int val;
} numeral;

int maxNumeral(numeral *nu, int num);
void decimalToRoman(numeral *nu, int num);

int main() {
   int number;
   numeral letter[15] = {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
                      {"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000},{"MMMM",4000}};
    
   printf("Enter a decimal number: ");
   scanf("%d", &number);
    
   if (number >0 && number <= 5000) { //checks input number within range
      printf("The Roman equivalent of %d is ", number);
      decimalToRoman(letter, number);
   }
   else {
      printf("Invalid Input");
   }
      printf("\n");

    return 0;
}

void decimalToRoman(numeral *nu, int num){
   int max;
   if (num != 0) {
      max = maxNumeral(nu, num);
      printf("%s", nu[max].sym);
      num -= nu[max].val; //decrease number
      decimalToRoman(nu, num); //recursively print numerals
   }
}

int maxNumeral(numeral *nu, int num){
   int i, index = 0;
   for (i = 0; i < 15; i++) { //15 numerals in array
      if (nu[i].val <= num)
         index = i;
   }
   //gretest value numeral index, not greater than number
   return index;
}