/*
Instituto Tecnológico de Costa Rica
Escuela de Computación
Análisis de Algortimos
Profesor: Rodrigo Núñez Núñez
Estudiantes: 
Luis Carlos Araya Mata Carne: 2020205005
Junior Lopez Aguirre Carne: 
Grupo: 1
I Semestre
2021
Martes 9 de marzo de 2021
9/03/2021
*/
#include <bits/stdc++.h> 
using namespace std; 
  
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
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver code  
int main()  
{  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};   //CAMBIAR EL TAMANNO DEL ARRAY PARA QUE SEA ADECUADO PARA LAS PRUEBAS
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n"<<endl;  
    printArray(arr, n);  
    return 0;  
}  
