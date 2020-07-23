#include<stdio.h>
#include<string.h>

int myStrStr(char haystack[], char needle[], char buffer[]){


	for(int i=0;i<strlen(haystack);i++){

		if(haystack[i]==needle[0]){
			int q=i,j=0;
			for(int p=0;p<strlen(needle);p++){
				if(haystack[q]==needle[j]){
					buffer[j]=haystack[q];
					q++;j++;
				}
			}
			if(j==strlen(needle)){
				buffer[j]='\0';
			//strcpy(buffer,needle);
				return 1;
			}
		}
	}
	return 0;

}

unsigned int countOnes(int num){

int count=0;

if(num<0){
	count=sizeof(int)*8;
}
while(num >0){

num=num & (num-1);
count++;
}


return count;

	

}


void binaryArray(int n, int array[], int size){
 for (int i = 0; i < size; i++) {
 array[size-i-1] = (n >> i) & 1;
 }
};

void binaryPrinter(int array[], int size){
  for (int i = 0; i < size; i++) {
   printf("%d",array[i]);
  }
};