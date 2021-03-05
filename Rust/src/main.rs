
///Instituto Tecnológico de Costa Rica
///Escuela de Computación
///Análisis de Algortimos
///Profesor: Rodrigo Núñez Núñez
///Estudiantes: 
///Luis Carlos Araya Mata Carné: 2020205005
/// Junior Lopez Aguirre Carné: 2015097593
///Grupo: 1
///I Semestre
///2021
///Martes 9 de marzo de 2021
///9/03/2021


fn main() {
    println!("Sort numbers ascending");
    let mut numbers = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]; // Cambiar el arreglo al tamaño que es !!!!!!!
    println!("Before: {:?}", numbers);
    bubble_sort(&mut numbers);
    println!("After:  {:?}\n", numbers);
}

pub fn bubble_sort<T: Ord>(arr: &mut [T]) {
    for i in 0..arr.len() {
        for j in 0..arr.len() - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}