#include"stdio.h"
#include "stdlib.h"

void tolower_function(char *given_text){
    int i = 0;
    for(i=0;i<strlen(given_text);i++){
        if(given_text[i]<=90 && given_text[i]>= 64){
            given_text[i] += 32;
        }
    }
}
void cryption_function(char *given_text, char *key_word){
    for(int i =0;i< strlen(given_text)-1;i++){
        if(given_text[i] != ' '){
            given_text[i] = given_text[i] + key_word[i%strlen(key_word)] -96;
            if(given_text[i]> 122){
                given_text[i] = given_text[i]%122 + 96;
            }
        }
    }
}
void decryption_function(char *given_text, char *key_word){
    for(int i = 0; i< strlen(given_text)-1; i++){
        if(given_text[i] != ' '){
            given_text[i] = given_text[i] - (key_word[i%strlen(key_word)] -96);
            if(given_text[i] < 97){
                given_text[i] = given_text[i] + 26;
            }
        }
    }
}
int main(){
    int operation=0;
    printf("enter a text: \n");
    char text[50];
    fgets(text,50,stdin);
    printf("enter a key word: \n");
    char key[10];
    scanf("%s",key);
    printf("which operation do you want to use? 1 for cryption 2 for decryption\n");
    scanf("%d",&operation);
    if(operation == 1){
        cryption_function(text,key);
        printf("crypted\n");
        puts(text);
    }
    if(operation == 2){
        decryption_function(text,key);
        printf("decrypted\n");
        puts(text);
    }
    return 0;
}
