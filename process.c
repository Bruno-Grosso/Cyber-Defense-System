#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"

// 1. Allocate memory for a new process in the Heap
Process* create_process(char name[30], int pid, int ram_mb, int threat_level){
  Process* new_node = (Process*)malloc(sizeof(Process));
    
  if(new_node == NULL){
    printf("[ERROR] Critical memory allocation failure. \n");
    return NULL;
  }
  
  strncpy(new_node->name, name, sizeof(new_node->name) - 1);

  new_node->name[sizeof(new_node->name) - 1] = '\0';
  new_node->pid = pid;
  new_node->ram_mb = ram_mb;
  new_node->threat_level = threat_level;
  new_node->next = NULL;

  return new_node;
}

// 2. Insert at the linked list
Process* insert_process(Process* head, char name[30], int pid, int ram_mb, int threat_level){
  Process* new_node = create_process(name, pid, ram_mb, threat_level);

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
  printf("| NAME\t\t| PID\t| RAM (MB)\t| THREAT |\n");
  printf("----------------------------------\n");

  while(current != NULL){
    printf("| %s \t\t| %d\t| %d\t\t| %d\t | \n", current->name, current->pid, current->ram_mb, current->threat_level);
    current = current->next;
  }
  
  printf("----------------------------------\n\n");
}

// 4. Eliminate the Worst Vírus
Process* quarantine_malware(Process*head){
  Process* current = head;
  Process* target = head;
  Process* prev = NULL;
  Process* target_prev = NULL;
  int suspect_process = 0;
  
  while(current != NULL){

    if(current->threat_level >= 8){
      suspect_process++;
      if(current->threat_level > target->threat_level){
        target = current;
        target_prev = prev;
      } 
    }
    prev = current;
    current = current->next;

  }
  
  if(suspect_process > 0){

    printf("[DEFENSE] The Virus with name %s and with %d of PID and with %d of threat_level was Eliminated \n",target->name, target->pid, target->threat_level);

    if(target == head){
      head = head->next;
      free(target);
    } else{
      target_prev->next = target->next;
      free(target);
    }
    suspect_process--;
    
    if(suspect_process > 0){
      head = quarantine_malware(head);
    }

  }

  return head;
    
}

// 5. Clean the System
void free_system(Process*head){
  Process*current = head;

  while(current != NULL){
    head = head->next;
    free(current);
    current = head;
  }
  printf("[INFO] Defense system shutdown and memory cleared.\n");
}

