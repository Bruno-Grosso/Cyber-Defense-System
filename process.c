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

// 3. Merge_sort to Show the List
Process* selection_sort(Process* head, int criteria){
  if (head == NULL || head->next == NULL) {
    return head;
  }
  
    Process* dummy_node = create_process("DUMMY", 0, 0, 0);
    Process* tail = dummy_node; 
    
  
    while (head != NULL) {
        Process* target = head;        
        Process* target_prev = NULL;
        Process* current = head;
        Process* prev = NULL;

        while (current != NULL) {
            int is_better = 0;
            if (criteria == 0){
              is_better = (current->threat_level > target->threat_level);
            } else if (criteria == 1){
                is_better = (current->pid < target->pid);
            } else if (criteria == 2){
                is_better = (current->ram_mb > target->ram_mb);
            }

            if (is_better) {
                target = current;        
                target_prev = prev;
            }
            prev = current;
            current = current->next;
        }

        if (target == head) {
            head = head->next;
        } else {
            target_prev->next = target->next;
        }

        target->next = NULL;
        tail->next = target;
        tail = target; 
    }

    Process* sorted_list = dummy_node->next;
    free(dummy_node); 
    return sorted_list; 
}

// 4. List processes
Process* list_process(Process*head){
  int criteria = 0;
  
  printf("[OPTION] Choose the option to show the list (0) THREAT, (1) PID, (2) RAM (MB): ");
  scanf("%d", &criteria);

  if(criteria <= 2 && criteria >= 0){
    head = selection_sort(head, criteria);
  }

  Process* current = head;

  printf("\n>>> ACTIVE PROCESS MONITOR <<<\n");
  printf("| NAME\t\t| PID\t| RAM (MB)\t| THREAT |\n");
  printf("----------------------------------\n");

  while(current != NULL){
    printf("| %s \t| %d\t| %d\t\t| %d\t | \n", current->name, current->pid, current->ram_mb, current->threat_level);
    current = current->next;
  }
  
  printf("----------------------------------\n\n");

  return head;

}

// 5. Eliminate the Worst Vírus
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

// 6. Clean the System
void free_system(Process*head){
  Process*current = head;

  while(current != NULL){
    head = head->next;
    free(current);
    current = head;
  }
  printf("[INFO] Defense system shutdown and memory cleared.\n");
}

