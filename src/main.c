#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"

int main(){
  
  // start the monitor
  Process* system_monitor = NULL;
  int mode = 0;
  srand(time(NULL));
  int keep_going = 1;

  printf("=== CYBER-DEFENSE SYSTEM CONFIG ===\n");
  printf("(1) Default Mode (Pre-set list)\n");
  printf("(2) User Mode (Manual input)\n");
  printf("(3) Random Mode (Stress test)\n");
  printf("[OPTION] Select initialization mode: "); //chosse the process list
  scanf("%d", &mode);
  
 
  switch (mode){
    case 1:
      //start the simulation
      system_monitor = insert_process(system_monitor, "System", 104, 150, 0); 
      system_monitor = insert_process(system_monitor, "Browser", 2048, 45, 2); 
      system_monitor = insert_process(system_monitor, "Malware_X", 666, 500, 10);
      system_monitor = insert_process(system_monitor, "Discord", 421, 320, 4);
      system_monitor = insert_process(system_monitor, "Miner_Bot", 542, 940, 9);
      system_monitor = insert_process(system_monitor, "Kernel", 132, 40, 1);
      system_monitor = insert_process(system_monitor, "Spyware", 4643, 150, 7);
      system_monitor = insert_process(system_monitor, "Ransomware", 34, 575, 8);
      break;

    case 2:
      //start the simulation
      int n = 0;

      printf("[OPTION] How many process to add: ");
      scanf("%d", &n);
      
      for(int i= 0; i < n; i++){
        char name[30];
        int p, r, t; //p = PID, r = RAM (MB), t = THREAT
        
        printf("\n--- Process #%d ---\n", i+1);
        printf("Name: "); scanf("%s", name);
        printf("PID: "); scanf("%d", &p);
        printf("RAM (MB): "); scanf("%d", &r);
        printf("Threat (0-10): "); scanf("%d", &t);
        system_monitor = insert_process(system_monitor, name, p, r, t);
      }
      break;

    case 3:
      //start the simulation
      int count;
      printf("Enter number of random processes: ");
      scanf("%d", &count);

      for(int i = 0; i < count; i++) {
        char r_name[30];
        sprintf(r_name, "Task_%d", i);
        int r_pid = rand() % 9000 + 100;
        int r_ram = rand() % 4000 + 10;
        int r_threat = rand() % 11;
        system_monitor = insert_process(system_monitor, r_name, r_pid, r_ram, r_threat);
      }
      break;
  }

  printf("Booting Cyber-Defense System...\n\n");
  
  //impress informations
  system_monitor = list_process(system_monitor);

  //eliminate virus
  system_monitor = quarantine_malware(system_monitor);
  
  //impress informations
  system_monitor = list_process(system_monitor);

  //verify possible virus
  system_monitor = security_triage(system_monitor);

  while(keep_going == 1){
    //impress information again
    system_monitor = list_process(system_monitor);

    printf("[OPTION] You want continue this program? (0) = no, (1) yes ");
    scanf("%d", &keep_going);
  }

  //clean process
  free_system(system_monitor);

  return 0;
}
