#ifndef PROCESS_H
#define PROCESS_H

// The structure of our Process (Virus or Normal Program)
typedef struct Process {
    char name[30];       // Process name
    int pid;             // Process ID
    int ram_mb;          // Memory consumption in MB
    int threat_level;    // 0 (Safe) to 10 (Critical Malware)
    struct Process* next; 
} Process;

// Engine Signatures
Process* create_process(char name[30], int pid, int ram_mb, int threat_level);
Process* insert_process(Process* head, char name[30], int pid, int ram_mb, int threat_level);
Process* quarantine_malware(Process* head); // first elimination, threat_level dependent
Process* selection_sort(Process* head, int criteria); //0 = threat_level, 1 = pid, 2 = ram_mb
Process* list_process(Process* head);
Process* security_triage(Process* head); //seconde elimination, ram_mb dependent
void free_system(Process* head);


#endif


