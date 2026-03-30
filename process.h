#ifndef PROCESS_H
#define PROCESS_H

// The structure of our Process (Virus or Normal Program)
typedef struct Process {
    int pid;             // Process ID
    int ram_mb;          // Memory consumption in MB
    int threat_level;    // 0 (Safe) to 10 (Critical Malware)
    struct Process* next; 
} Process;

// Engine Signatures
Process* create_process(int pid, int ram_mb, int threat_level);
Process* insert_process(Process* head, int pid, int ram_mb, int threat_level);
void list_process(Process* head);
void free_system(Process* head);
Process* quarantine_malware(Process* head);

#endif


