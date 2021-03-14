#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define LIMIT 100
char buffer[LIMIT];
char t;

int main(){
  int i;
  char *previous = "";
  char *ptr = "";
  while (1){
    char * inputStr = (char *)malloc(LIMIT);
    for(i = 0; (t = getchar()) != 0x0a && i<LIMIT-1; i++){
      *(inputStr+i) = t;
    }
    *(inputStr+99) = '\0';
    printf("Previous: %s\n", previous);
    printf("Last: %s\n", ptr);
    previous = ptr;
    ptr = inputStr;
    printf("Current %s\n", inputStr);
    printf("-----------------------\n");
  }
}

int space_char(char c){
  if (c == " ")
    return 1;
  else
    return 0;
}

int non_space_char(char c){
  if (c != " ")
    return 1;
  else
    return 0;
}

char *word_start(char *str){
  if(count_words(str) > 0){
    char *temp_str = str;
    while(temp_str){
      if(non_space_char(temp_str[0]))
	return temp_str;
      else
	temp_str++;
    }
  }
  return "0";
}

char *word_end(char *str){
  if(count_words(str) > 0){
    while(non_space_char(str)){
      str++;
    }
    return str;
  }
  return "0";
}

int count_words(char *str){
  char *temp_str = str;
  int num = 0;
  int i = 0;
  while(temp_str[i]){
    if(non_space_char(temp_str[i])){
      num++;
      i++;
      while(non_space_char(temp_str[i])){
	i++;
      }
    }
    else
      i++;
  }
  return num;
}

char *copy_str(char *inStr, short len){
  char *new_str = (char*)malloc(len+1);
  int i = 0;
  while(inStr[i]){
    new_str[i] = inStr[i];
    i++;
  }
  new_str[i+1] = '\0';
}

char **tokenize(char *str){
  int i = 0;
  int len = count_words(str);
  char **tokens = (char**) malloc((len+1) * sizeof(char*));
  while(i<len){
    str = word_start(str);
    char *tokenized = copy_str(str, count_words(str));
    str = word_end(str);
    tokens[i] = tokenized;
    i++;
  }
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    printf("[%d] = %s\n", i, tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
