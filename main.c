#include <stdio.h>
#include "process.h"

int main(){
  
  // start the monitor
  Process* system_monitor = NULL;
  
  printf("Booting Cyber-Defense System...\n\n");

  //start the simulation
  system_monitor = insert_process(system_monitor, 104, 150, 0); //secure process
  system_monitor = insert_process(system_monitor, 2048, 45, 2); //web browser
  system_monitor = insert_process(system_monitor, 666, 500, 10); //critical malware
  system_monitor = insert_process(system_monitor, 421, 320, 4);
  system_monitor = insert_process(system_monitor, 542, 940, 9);
  system_monitor = insert_process(system_monitor, 132, 40, 1);
  system_monitor = insert_process(system_monitor, 4643, 150, 7);
  system_monitor = insert_process(system_monitor, 34, 575, 8);
  
  //impress informations
  list_process(system_monitor);

  //eliminate virus
  system_monitor = quarantine_malware(system_monitor);

  //impress information again 
  list_process(system_monitor);

  //clean process
  free_system(system_monitor);

  return 0;
}
