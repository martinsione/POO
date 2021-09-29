## Programación Orientada a Objetos - Parcial 1 - 28/09/2021 - Tema A

### Ejercicio 1 (30 pts)

1.  Escriba una función que reciba dos punteros indicando el comienzo y el final de un arreglo. La función debe verificar si el arreglo está ordenado de forma creciente. Si lo está, la función debe retornar al arreglo original. Si no lo está, debe retornar un nuevo arreglo que incluya solo la parte ordenada (hasta donde detectó el error) del arreglo original (ej, si ingresa 1,2,3,5,4,6, debe generar un nuevo arreglo con 1,2,3,5).
2.  Escriba un programa cliente que permita al usuario ingresar un arreglo para probar la función, y muestre el resultado: si el arreglo estaba ordenado, mostrar un mensaje alusivo; si no lo estaba el nuevo arreglo.

- Nota: no puede usar std::vector para este ejercicio.

### Ejercicio 2 (35 pts)

1. Defina una clase Carrera que reciba en su constructor el nombre de un evento deportivo y la fecha del mismo. La clase debe tener métodos para consultar estos datos y para gestionar una lista de participantes (nombre de cada uno).
2. Implemente, reutilizando la clase Carrera las clases Formula1 y MotoGP para representar carreras de estas dos categorías. Estas clases deben tener un método CalcularPuntos que reciba el nombre de un participante, la posición en la que finalizó la carrera, y un booleano para indicar si fue el autor de la vuelta más rápida. El método debe validar si el nombre es correcto (está entre los inscriptos) y si lo es retornar la cantidad de puntos que obtuvo (si no es correcto, debe retornar -1).
   - En la Fórmula 1, los 10 primeros reciben 25, 18, 15, 12, 10, 8, 6, 4, 2 y 1 puntos respectivamente. Pero además, si uno de los 10 primeros logra la vuelta rápida, suma un punto adicional.
   - En Moto GP, los 15 primeros suman puntos según la siguiente escala: 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 (aquí no hay bonificación alguna para quien logre la vuelta rápida).
3. Escriba una función “testCalcularPuntos" para probar el método CalcularPuntos. La función debe poder recibir cualquier tipo de Carrera, y un vector con los nombres de los pilotos en el orden en que arribaron a meta. Debe mostrar el puntaje resultante de cada uno (o un mensaje alusivo si un nombre no es correcto).

### Ejercicio 3 (35 pts)

En el diseño orientado a objetos para un caso, se ha decidido plantear las siguientes dos clases:

**Clase Alumno.**

- Atributos:
  - nombre.
  - dni.
  - nota1, nota2, nota3.
  - promedio.
  - condición (‘P’,’R’o ‘L’).
- Métodos:
  - Constructor.
  - CalcularCondicion (calcula promedio y condición y devuelve esos 2 atributos).
  - VerDatosAlumno(un solo método para devolver nombre, dni).

**Clase Materia.**

- Atributos:
  - nombreMateria.
  - nombreProfesor.
  - Grupo de alumnos que la cursan (son 80, cada alumno tiene nombre, dni, nota1, nota2, nota 3, promedio, condición).
- Métodos:
  - Constructor.
  - buscar condición y promedio de un alumno (un solo método; parámetro: dni).
  - Cantidades (un solo método que calcule y devuelva cantidad de promocionados, cantidad libres, cantidad regulares ).

Considerando que las condiciones posibles en la materia son: Promocionado si promedio>=60, Libre si promedio<40, Regular en otro caso.

1. Establezca una relación de clases entre Alumno y Materia. Codifique las 2 clases con la sintaxis de C++.
2. Escriba un programa C++ cliente de dichas clases que lea los datos necesarios para inicializar una instancia de Materia e informe las condiciones de los alumnos.
3. Además, el programa debe ingresar un dni y mostrar los datos del alumno, su promedio y condición en la materia.


<!--  -->
