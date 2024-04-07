#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#define max 30
// CPU Scheduling Function Declarations
void fcfs();
void priority();
void roundRobin();
void sjf();
// Disk Scheduling Function Declarations
void fcfsDisk();
void sstfDisk();
void scanDisk();
// Memory Management Function Declarations
void bestFit();
void worstFit();
void firstFit();
int main() {
    int mainChoice, diskChoice, cpuChoice;
    int choice;
    int n, initial;
    int RQ[100], d[20];
    system("color 1E");
      //bankers start from here:---
      printf("\n Before proceeding towards the Scheduling algorithms , First check for DeadLock state (if any).........");
      int process, resource, i, j, instance, k=0, count=0, temp=0;
  printf("\n Enter No. of Process : ");
  scanf("%d", &process);
  printf(" Enter No. of Resources : ");
  scanf("%d",&resource);
  int available[resource], max2[process][resource], allocated[process][resource], need[process][resource], completed[process];
  for(i=0; i<process; i++)
    completed[i] = 0;
  printf("\n Enter No. of AVAILABLE Instances for each resource\n\n");
  for(i=0; i<resource;i++)
  {
    printf(" Resources[%d] : ", i);
    scanf("%d", &instance);
    available[i] = instance;
  }
  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter MAXIMUM instance for a Process & its corresponding resource :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
        printf(" Resource[%d] : ", j);
        scanf("%d", &instance);
        max2[i][j] = instance;
    }
  }
  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter instance ALLOCATED for a Process & its corresponding resource :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
      printf(" Resource[%d] : ", i);
      scanf("%d", &instance);
      allocated[i][j] = instance;
      need[i][j] = max2[i][j] - allocated[i][j];
    }
  }
  printf("\n------------------------------------------------------------------------------\n");
  printf("\nSafe Sequence is : ");
  while(count != process)
  {count = temp;
    for(i=0; i<process; i++)
    {
      for(j=0; j<resource; j++)
      {
        if(need[i][j] <= available[j])
        {
          k++;
        }
      }
      if(k == resource && completed[i] == 0 )
      {printf(" > P[%d] ", i);
        completed[i] = 1;
        for(j=0; j<resource; j++)
        {available[j] = available[j] + allocated[i][j];
        }count++;
      }k=0;
    }
if(count == temp)
    {break;
    }
  }
  for(i=0; i<process; i++)
  {
    if(completed[i] != 1)
    {
      printf("\n\n P[%d] not able to allocate", i);
    }
  }
  printf("\n");
  printf("------------------------------------------------------------------------------------------------------\n0");
  printf("\n Now as you know the DeadLock Status of your request, here is the process scheduling part:--\n\n");
  //bankers finish here:----------
    do {
        printf("\n=============== Main Menu ===============\n");
        printf("0. Disk Scheduling\n");
        printf("1. CPU Scheduling\n");
        printf("2. Memory Management\n");
        printf("3. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice) {
        case 0:
            // Disk Scheduling
            printf("\n=============== Disk Scheduling Algorithms Menu ===============\n");
            printf("1. FCFS (First Come First Serve)\n");
            printf("2. SSTF (Shortest Seek Time First)\n");
            printf("3. SCAN\n");
            printf("4. Exit\n");
            printf("==============================================================\n");
            printf("Enter your choice: ");
            scanf("%d", &diskChoice);
            switch (diskChoice) {
            case 1:
                printf("Enter the number of Requests: ");
                scanf("%d", &n);

                printf("Enter the Requests sequence:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &RQ[i]);

                printf("Enter initial head position: ");
                scanf("%d", &initial);

                fcfsDisk(RQ, n, initial);
                break;
            case 2:
                printf("Enter the number of Requests: ");
                scanf("%d", &n);
                printf("Enter the Requests sequence:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &RQ[i]);
                printf("Enter initial head position: ");
                scanf("%d", &initial);
                sstfDisk(RQ, n, initial);
                break;
            case 3:
                printf("Enter the number of location: ");
                int num_locations;
                scanf("%d", &num_locations);
                printf("Enter position of head: ");
                int disk_position;
                scanf("%d", &disk_position);
                printf("Enter elements of disk queue:\n");
                for (int i = 0; i < num_locations; i++)
                    scanf("%d", &d[i]);
                scanDisk(d, num_locations, disk_position);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
            }
            break;
        case 1:
            // CPU Scheduling
            printf("\n=============== CPU Scheduling Algorithms Menu ===============\n");
            printf("1. First Come First Serve (FCFS) \n");
            printf("2. Priority Scheduling\n");
            printf("3. Round Robin Scheduling\n");
            printf("4. Shortest Job First (SJF)\n");
            printf("5. Exit\n");
            printf("==============================================================\n");
            printf("Enter your choice: ");
            scanf("%d", &cpuChoice);
            switch (cpuChoice) {
            case 1:
                fcfs();
                break;
            case 2:
                priority();
                break;
            case 3:
                roundRobin();
                break;
            case 4:
                sjf();
                break;
            case 5:
                printf("Exiting CPU scheduling.\n");
                break;
            default:
                printf("Invalid choice for CPU scheduling. Please enter a valid option.\n");
            }
            break;
        case 2:
            // Memory Management
            printf("\n=============== Memory Management Algorithms Menu ===============\n");
            printf("1. Best Fit\n");
            printf("2. Worst Fit\n");
            printf("3. First Fit\n");
            printf("4. Back to Main Menu\n");
            printf("==================================================================\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                bestFit();// Best Fit
                break;
            case 2:
                worstFit();// Worst Fit
                break;

            case 3:
                firstFit(); // First Fit
                break;
            case 4:
                printf("Returning to the Main Menu.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
            }
            break;
        case 3:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (mainChoice != 3);
    return 0;
}
void fcfsDisk(int RQ[], int n, int initial) {
    int TotalHeadMoment = 0;
    for (int i = 0; i < n; i++) {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
    }printf("Total head movement for FCFS is %d\n", TotalHeadMoment);
}
void sstfDisk(int RQ[], int n, int initial) {
    int TotalHeadMoment = 0;
    int count = 0;
    while (count != n) {
        int min = 1000, d, index;
        for (int i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (d < min) {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        RQ[index] = 1000;
        count++;
    }
    printf("Total head movement for SSTF is %d\n", TotalHeadMoment);
}
void scanDisk(int d[], int n, int disk) {
    int i, j, sum = 0;
    int temp, max1;
    int dloc;
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max1 = d[n];
    for (i = 0; i < n; i++) {
        if (disk == d[i]) {
            dloc = i;
            break;
        }
    }
    printf("SCAN movement order:\n");
    for (i = dloc; i >= 0; i--) {
        printf("%d -->", d[i]);
    }
    printf("0 -->");
    for (i = dloc + 1; i < n; i++) {
        printf("%d-->", d[i]);
    }
    sum = disk + max1;
    printf("\nTotal movement of cylinders for SCAN is %d\n", sum);
}
void fcfs() {
    int i,j, n,bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the B.T.s:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Process\t BurstTime\t WaitingTime\t TurnAroundTime\n");
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("AVG WT: %f\n", awt);
    printf("AVG TAT: %f\n", atat);
}
void priority() {
    // Priority scheduling implementation goes here
    int i,j,n,t,bt[max],pr[max],tat[max],wt[max],pos;
    float awt=0, atat=0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the B.T.s:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the Priority:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &pr[i]);
    }
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
            {
                pos=j;
            }
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
    }
    wt[0]=0;
    printf("Process\t Bt\t priority\t WT\t TAT\n");
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t %d\t \t%d\t %d\n", i+1,bt[i],pr[i],wt[i],tat[i]);
    }
    awt=awt/n;
    printf("The AVG WT: %f\n", awt);
    atat=atat/n;
    printf("The AVG ATAT: %f", atat);
}
void roundRobin() {
    // Round Robin implementation goes here
    // Arrival time is ZERO for all
    int i,count=0,n,tq,bt[max],bt_rem[max],wt[max],temp,sq=0,tat[max];
    float awt=0,atat=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the Burst time of processes: ");
    for(i=0;i<n;i++)
    {
    scanf("%d", &bt[i]);
    bt_rem[i]=bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp=tq;
            if(bt_rem[i]==0)
            {
                count++;
                continue;
            }
            if(bt_rem[i]>tq)
            {
                bt_rem[i]=bt_rem[i]-tq;
            }
            else
                if(bt_rem[i]>=0)
                {
                    temp=bt_rem[i];
                    bt_rem[i]=0;
                }
                sq=sq+temp;
                tat[i]=sq;
        }
        if(n==count)
            break;
    }
   printf("PID\t BT\t TAT\t WT\n");
   for(int i=0;i<n;i++)
   {
       wt[i]=tat[i]-bt[i];
       awt=awt+wt[i];
       atat=atat+tat[i];
       printf("%d\t %d\t %d\t %d\n", i+1,bt[i],tat[i],wt[i]);
   }
   awt=awt/n;
   printf("AVG WT: %f", awt);
   atat=atat/n;
   printf("AVG TAT: %f", atat);
}
//arrival time of all the jobs to be 0
void sjf() {
    int i,j,t,n,p[max],bt[max],wt[max],tat[max];
    float atat=0,awt=0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the Process Number: ");
    for (int i =0;i<n;i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the Burst time: ");
    for (int i =0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    //bubble sort for bt and p
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    printf("PID\t BT\t WT\t TAT\n");
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        atat=atat+tat[i];
        awt=awt+wt[i];
        printf("%d\t %d\t %d\t %d\n", p[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("avg wt: %f\n", awt);
    printf("avg tat: %f\n", atat);
}
void bestFit() {
int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
static int barray[20],parray[20];
printf("\n\t\t\tMemory Management Scheme - Best Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of processes:");
scanf("%d",&np);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
    {
printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
printf("\nEnter the size of the processes :-\n");
for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
for(i=1;i<=np;i++)
{
for(j=1;j<=nb;j++)
{
if(barray[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(lowest>temp)
{
parray[i]=j;
lowest=temp;}}}
fragment[i]=lowest;
barray[parray[i]]=1;
lowest=10000;}
printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
for(i=1;i<=np && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);
}
void worstFit() {
int n,n1,i;
printf("enter the number of processes:");
scanf("%d",&n);
int process[n];
printf("\n enter the size of processes:\n");
for(i=0;i<n;i++)
{
scanf("%d",&process[i]);
}
printf("enter the no of memoryblocks:");
scanf("%d",&n1);
int blocks[n1];
printf("\n enter the size of blocks:\n");
int total=0;
for(i=0;i<n1;i++)
{
scanf("%d",&blocks[i]);
total=total+blocks[i];
}
int process1[n1];
int job[n1];
int frag[n1];
int check[n1];
for(i=0;i<n1;i++)
{
check[i]=0;
}
int j,used=0;
i=0;
while(i<n)
{
int max4=-1,j1=-1,k=-1,max5;
for(j=0;j<n1;j++)
{
max5=blocks[j];
if(max5>=max4&&check[j]==0&&max5>=process[i])
{
max4=max5;
j1=j;
}
else
{
if(check[j]==0)
{
process1[j]=0;
job[j]=0;
frag[j]=blocks[j];}}}
if(k!=j1)
{
process1[j1]=process[i];
job[j1]=i+1;
frag[j1]=blocks[j1]-process[i];
used=used+process[i];
check[j1]=1;
int l;
}
i++;
}
printf("blocksize\tprocess size\tprocessno\tfragmentation\n");
for(i=0;i<n1;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\n",blocks[i],process1[i],job[i],frag[i]);
}
printf("totalmemoryallocation:%d\n",total);
printf("memoryused:%d\n",used);
}
void firstFit() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
printf("Enter no. of blocks: ");
scanf("%d", &bno);
printf("\nEnter size of each block: ");
for(i = 0; i < bno; i++)
scanf("%d", &bsize[i]);
printf("\nEnter no. of processes: ");
scanf("%d", &pno);
printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++)
scanf("%d", &psize[i]);
for(i = 0; i < pno; i++)         //allocation as per first fit
for(j = 0; j < bno; j++)
if(flags[j] == 0 && bsize[j] >= psize[i])
{
allocation[j] = i;
flags[j] = 1;
break;
}//display allocation details
printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
for(i = 0; i < bno; i++)
{
printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
if(flags[i] == 1)
printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
else
printf("Not allocated");}
}
