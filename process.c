#include <stdio.h>
#include <stdlib.h>
#include "process.h"

// 1. Allocate memory for a new process in the Heap
Process* create_process(int pid, int ram_mb, int threat_level){
  Process* new_node = (Process*)malloc(sizeof(Process));
    
  if(new_node == NULL){
    printf("[ERROR] Critical memory allocation failure. \n");
    return NULL;
  }
    
  new_node->pid = pid;
  new_node->ram_mb = ram_mb;
  new_node->threat_level = threat_level;
  new_node->next = NULL;

  return new_node;
}

// 2. Insert at the linked list
Process* insert_process(Process* head, int pid, int ram_mb, int threat_level){
  Process* new_node = create_process(pid, ram_mb, threat_level);

  if(new_node == NULL){
    return head;
  }

  if(head == NULL){
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }

  printf("[INFO] Process PID %d (Threat: %d) loaded into monitor.\n", pid, threat_level);
  return head;
}

// 3. List processes
void list_process(Process*head){
  Process*current = head;

  printf("\n>>> ACTIVE PROCESS MONITOR <<<\n");
  printf("| PID\t| RAM (MB)\t| THREAT |\n");
  printf("----------------------------------\n");

  while(current != NULL){
    printf("| %d\t| %d\t\t| %d\t | \n", current->pid, current->ram_mb, current->threat_level);
    current = current->next;
  }
  
  printf("----------------------------------\n\n");
}

// 4. Clean the System
void free_system(Process*head){
  Process*current = head;

  while(current != NULL){
    head = head->next;
    free(current);
    current = head;
  }
  printf("[INFO] Defense system shutdown and memory cleared.\n");
}

