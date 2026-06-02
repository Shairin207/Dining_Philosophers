# Dining Philosophers Problem

A multi-threaded implementation of the classic **Dining Philosophers Problem** using **POSIX Threads (Pthreads)** and **Semaphores** in C. This project demonstrates synchronization techniques, resource sharing, and deadlock prevention in concurrent systems.

## 📌 Project Overview

The Dining Philosophers Problem is a well-known synchronization problem in operating systems and concurrent programming. It models a group of philosophers sitting around a table who alternate between thinking and eating while competing for limited shared resources (forks).

This project simulates philosopher behavior using multiple threads and semaphores to ensure safe resource allocation, prevent deadlocks, and minimize starvation.

## 🎯 Objectives

* Understand process synchronization and concurrency
* Implement thread communication using POSIX threads
* Manage shared resources with semaphores
* Prevent deadlock and resource starvation
* Analyze thread scheduling and synchronization behavior

## 🧠 Concepts Covered

* Operating Systems
* Concurrent Programming
* Multithreading
* POSIX Threads (Pthreads)
* Semaphores
* Deadlock Prevention
* Resource Allocation
* Critical Sections
* Synchronization Mechanisms

## ⚙️ Features

* Multi-threaded philosopher simulation
* Semaphore-based synchronization
* Deadlock avoidance strategy
* Fair resource allocation for philosophers
* Efficient fork acquisition and release
* Console-based execution and monitoring

## 🛠 Technologies Used

* C Programming Language
* POSIX Threads (Pthreads)
* POSIX Semaphores
* GCC Compiler
* Linux/Unix Environment

## 📂 Project Structure

Dining_Philosophers/

├── dinnig-philosophy.c

├── README.md

## 🚀 How to Run

### Clone the Repository

```bash
git clone https://github.com/Shairin207/Dining_Philosophers.git
cd Dining_Philosophers
```

### Compile the Program

```bash
gcc dinnig-philosophy.c -o dining -lpthread
```

### Run the Program

```bash
./dining
```

## 📊 Project Analysis

This simulation demonstrates how synchronization techniques can be used to coordinate multiple threads competing for shared resources.

The implementation focuses on:

* Preventing deadlocks caused by circular waiting
* Avoiding resource starvation
* Ensuring fair access to shared resources
* Improving understanding of concurrent system behavior

## 🎓 Learning Outcomes

* Practical experience with multithreading
* Understanding semaphore-based synchronization
* Implementing deadlock prevention techniques
* Managing shared resources in concurrent systems
* Applying operating system concepts to real-world problems

## 👩‍💻 Author

**Shairin Akter Hashi**
Department of Computer Science & Engineering
East West University

## 📚 Course Information

**Course:** Operating Systems
**Department:** Computer Science & Engineering

## 📄 License

This project is available for educational and learning purposes.
