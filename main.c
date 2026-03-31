#include <stdio.h>
#include "process.h"

int main(){
  
  // start the monitor
  Process* system_monitor = NULL;
  int keep_going = 1;
  
  printf("Booting Cyber-Defense System...\n\n");

  //start the simulation
  system_monitor = insert_process(system_monitor, "System", 104, 150, 0); 
  system_monitor = insert_process(system_monitor, "Browser", 2048, 45, 2); 
  system_monitor = insert_process(system_monitor, "Malware_X", 666, 500, 10);
  system_monitor = insert_process(system_monitor, "Discord", 421, 320, 4);
  system_monitor = insert_process(system_monitor, "Miner_Bot", 542, 940, 9);
  system_monitor = insert_process(system_monitor, "Kernel", 132, 40, 1);
  system_monitor = insert_process(system_monitor, "Spyware", 4643, 150, 7);
  system_monitor = insert_process(system_monitor, "Ransomware", 34, 575, 8);
  
  //impress informations
  system_monitor = list_process(system_monitor);

  //eliminate virus
  system_monitor = quarantine_malware(system_monitor);

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
