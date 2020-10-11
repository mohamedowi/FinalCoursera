#include <stdint.h>
#include "data.h"
#include <stdlib.h>
#include <math.h>

uint8_t* reversestring(uint8_t *ptr,uint8_t length){
uint8_t i=0;
uint8_t j=length-1;
uint8_t temp = 0;
while ( i<j){
    temp = *(ptr+i);
    *(ptr+i) = *(ptr+j);
    *(ptr+j) = temp;
    i++;
    j--;
}
return ptr;
}
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
int32_t truevalue = abs(data);
int counter = 0;
if(base<2 || base>16){
    return 0;
}
if (data == 0 ){
    *(ptr+0) = '0';
    *(ptr+1) = '\0';
return 2;
}

while(truevalue!=0){
int remainder = truevalue % base;
if( remainder>9){
*(ptr+counter) = (remainder-10) + 'a';
}
else{
*(ptr+counter) = remainder + '0';
}
counter++;
truevalue = truevalue/base ;
}
if ( data<0 && base==10){
*(ptr+counter) = '-';
counter++;
}

ptr = reversestring(ptr,counter);
*(ptr+counter) = '\0';
return counter;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
int counter =0;
uint32_t value=0;
uint8_t op = 1;
if(ptr==NULL){
    return 0;
}
if(*(ptr+0)== '-'){
    op = -1;
    counter++;
}
for(;*(ptr+counter)!= '\0';counter++){
value = value*10 + *(ptr+counter) - '0';
}


return op*value;
}

