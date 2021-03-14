#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List* new_list = (List*)malloc(sizeof(List*)*300);
  return new_list;
}

void add_history(List *list, char *str){
  Item* add_item = (Item*)malloc(sizeof(Item)*300);
  add_item -> str = str;
  if(list->root==NULL){
    add_item->id=1;
    list->root=add_item;
  }
  else{
    Item* history_item = list->root;
    while(history_item->next!=NULL){
      add_item->id=1;
      history_item = history_item -> next;
    }
  history_item->next=add_item;
  add_item->id++;
  }
}

char *get_history(List *list, int id){
  Item* history_item = list->root;
  while(history_item->next != list->root){
    if(history_item->id==id)
      return history_item->str;
    history_item=history_item->next;
  }
  return history_item->str;
}

void print_history(List* list){
  while(list->root!=NULL){
    printf("History ID:%d, Name:%s\n", list->root->id, list->root->str);
    list->root = list->root->next;
  }
}

void free_history(List* list){
  free(list);
}
