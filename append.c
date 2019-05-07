#include <stdio.h>

#include "directory.h"
#include "disk.h"
#include "append.h"

void append(listPtr head, listPtr newNode) {
  listPtr last, newHead;
  last = head;
  newHead = head;

  if (head->next == NULL) {
    head = newNode;
    return;
  }
  while (last->next != NULL){
    last = last->next;
  }
  last->next = newNode;
  return;
}
