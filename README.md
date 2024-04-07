#Multi-Objective Resource Scheduler
This project encompasses essential resource management functionalities tailored for operating systems, addressing critical components such as CPU scheduling, disk management, memory allocation, and deadlock prevention.

#CPU Scheduling Algorithms
FCFS (First Come First Serve): Implements a basic scheduling approach in the fcfs() function, executing tasks in the order of arrival. Helps understand scheduling complexities.

Priority Scheduling: Assigns priority levels to processes in the priority() function, balancing priority with fairness to ensure critical tasks are prioritized.

Round Robin Scheduling: Ensures fairness by executing processes in a time-sliced manner in the roundRobin() function, preventing potential starvation.

Shortest Job First (SJF): Prioritizes processes based on the shortest burst time in the sjf() function, minimizing waiting time and enhancing throughput.

#Disk Scheduling Techniques
FCFS (First Come First Serve): Executes disk requests sequentially in the fcfsDisk() function, ensuring simplicity but potentially leading to high seek times.

SSTF (Shortest Seek Time First): Prioritizes disk requests with the shortest seek time in the sstfDisk() function, minimizing head movements for optimized disk access.

SCAN (Elevator): Manages disk arm movement unidirectionally in the scanDisk() function, reversing upon reaching the end to enhance fairness in servicing disk requests.

#Memory Management Strategies 
Best Fit: Allocates the smallest available partition that fits the process in the bestFit() function, reducing fragmentation and optimizing memory usage.

Worst Fit: Allocates the largest available partition in the worstFit() function, efficiently utilizing memory but potentially leading to fragmentation.

First Fit: Allocates the first available partition that satisfies the process size in the firstFit() function, offering a simple and quick allocation method.

#Deadlock Prevention
The project incorporates the Banker's Algorithm for deadlock detection and resolution. This algorithm, integrated into the main function, checks for potential deadlock states from the initial stages of resource allocation, ensuring system stability and efficiency by preemptively managing resource allocation.

This comprehensive resource scheduler aims to optimize system performance, enhance resource utilization, and maintain system stability in dynamic computing environments.
