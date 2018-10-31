#include "stdio.h"
#include "stdlib.h"


void cryption_function(char *given_text, int key){
    puts(given_text);
    int temp=0;
    for(int i = 0;i < strlen(given_text); i++){
        if((given_text[i] >= 65 && given_text[i] <= 90) || (given_text[i]>= 97 && given_text[i <= 122])){
            given_text[i] = given_text[i] + key;
            if(given_text[i]>122){
                temp = given_text[i]%122;
                given_text[i] = 96 + temp;
                temp = 0;
            }
            if(given_text[i]> 90 && given_text[i]< 97){
                temp = given_text[i]%90;
                given_text[i] = 64 + temp;
                temp = 0;
            }
        }
    }
    puts(given_text);
}
void decryption_function(char *given_text, int key){
    puts(given_text);
    int temp=0;
    for(int i = 0;i < strlen(given_text); i++){
        if((given_text[i] >= 65 && given_text[i] <= 90) ){ // || (given_text[i]>= 97 && given_text[i <= 122])
            given_text[i] = given_text[i] - key;
            if(given_text[i]<65  ){
                given_text[i] = given_text[i] + 26;
            }
        }
        if((given_text[i]>= 97 && given_text[i <= 122])){
            given_text[i] = given_text[i] - key;
            if(given_text[i]<97  ){
                given_text[i] = given_text[i] + 26;
            }
        }
    }
    puts(given_text);
}
int main(){
    int operation;
    int key=0;char text[50];
    printf("enter a text\n");
        fgets(text,50,stdin);

    printf("which operation do you prefer? \(1 for crypting 2 for decrypting 3 for exit\)\n");
    scanf("%d",&operation);
  //  printf("which operation do you prefer? \(1 for crypting 2 for decrypting 3 for exit\)\n");
    while(operation!= 3){
        if(operation == 1 ){
            printf("enter a key\n");
            scanf("%d",&key);
            cryption_function(text,key);
        }
        if( operation == 2){
            printf("enter a key\n");
            scanf("%d",&key);
            decryption_function(text,key);
        }
        printf("which operation do you prefer? \(1 for crypting 2 for decrypting 3 for exit\)\n");
        scanf("%d",&operation);
    }
    return 0;
}
