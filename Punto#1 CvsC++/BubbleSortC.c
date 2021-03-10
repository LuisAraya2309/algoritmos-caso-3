/*
Instituto Tecnológico de Costa Rica
Escuela de Computación
Análisis de Algortimos
Profesor: Rodrigo Núñez Núñez
Estudiantes:
Luis Carlos Araya Mata Carne: 2020205005
Junior Lopez Aguirre Carne:   2015097593
Grupo: 1
I Semestre
2021
Martes 9 de marzo de 2021
9/03/2021
*/
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#define SIZE          8192  /* buffer size for reading /proc/<pid>/status */

 
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
 
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
     
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
 

void FillArray(int arr[]){
    srand(time(NULL));
    for(int indice= 0; indice<100000; indice++){
        arr[indice]=rand()%(3000001-0);
    }
}

//Function to calculate memory usage
int mem_total ()
{
  char a[SIZE], *p, *q;
  int data, stack;
  int n, v, fd;
  pid_t pid= getpid();

  p = a;
  sprintf (p, "/proc/%d/status", pid);
  fd = open (p, O_RDONLY);
  if (fd < 0)
    return -1;
  do
    n = read (fd, p, SIZE);
  while ((n < 0) && (errno == EINTR));
  if (n < 0)
    return -2;
  do
    v = close (fd);
  while ((v < 0) && (errno == EINTR));
  if (v < 0)
    return -3;
  data = stack = 0;
  q = strstr (p, "VmData:");
  if (q != NULL)
    {
      sscanf (q, "%*s %d", &data);
      q = strstr (q, "VmStk:");
      if (q != NULL)
    sscanf (q, "%*s %d\n", &stack);
    }
  return (data + stack);
}  
 
// Driver code  
int main()  
{  
    clock_t c1 = clock();
    int arr[100000];
    FillArray(arr);   
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);    
    int memoryUsed = mem_total ();
    printf("C\n");
    printf("Compiler Used: gcc 9.3.0\n");
    printf("Bubble sort completed\n");
    printf("Memory used: %d kb \n",memoryUsed);
    printf("Execution time: %ld milliseconds\n",(clock()-c1)*1000/CLOCKS_PER_SEC);
    return 0;  
}















  
