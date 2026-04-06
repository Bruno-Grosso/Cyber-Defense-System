# 🛡️ Cyber-Defense System (Phase 1)

A low-level process monitoring engine developed in **C**. This project simulates a digital biosecurity environment, utilizing **Dynamic Linked Lists** to manage system entities in real-time, with a rigorous focus on memory management and algorithmic efficiency.

## 🚀 Key Features
* **Dynamic Management**: Real-time allocation and deallocation of processes in the Heap.
* **Multi-Criteria Sorting**: Custom implementation of **Selection Sort** to organize processes by **Threat Level**, **PID**, or **RAM Usage**.
* **Quarantine Engine**: A recursive system for the automatic elimination of critical threats (Threat Level >= 8).
* **Security Triage**: An interactive interface for manual analysis and purging of suspicious processes (Threat Level 5-7).
* **Stress Simulation**: Automated random process generator for load and performance testing.

## 🛠️ Tech Stack & Tools
* **Language**: C (C99 Standard)
* **Environment**: WSL2 (Ubuntu 24.04 Noble)
* **Editor**: Neovim (LazyVim setup)
* **Memory Analysis**: **Valgrind (Memcheck)** — *Zero Leaks Guaranteed*.

## 📂 Project Structure
The project follows a modular organization to ensure scalability:

```text
.
├── bin/          # Compiled executables
├── include/      # Header files (.h)
├── src/          # Source code implementation (.c)
└── Makefile      # Automation for compilation and testing
```

## 📊 Quality Assurance (Memory Audit)
The system has been subjected to rigorous memory leak testing.

```text

Bash
# Valgrind Verdict:
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## 🎓 Academic Context
This project was developed during my 3rd semester of Computer Engineering at IPRJ/UERJ (Polytechnic Institute of the State University of Rio de Janeiro). It serves as a practical application of Dynamic Data Structures and Manual Memory Allocation.

## 💻 How to Run
Clone the repository.

In the terminal, run make to compile the source.

Execute ./bin/defense_system to launch the monitor.

## Developed with 💻 by Bruno Grosso
