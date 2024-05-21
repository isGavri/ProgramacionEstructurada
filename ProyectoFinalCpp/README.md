# Documentacion 

**Descipcion del programa**: Una institución educativa universitaria de prestigio desea tener un programa donde tenga el registro de sus estudiantes, datos de contacto de sus familiares y el registro de calificaciones de cinco materias.
## Requerimientos 
**Nota**: si ingresas un caracter no numerico cuando se te pide una entrada de datos numerica resultará en un fallo en el programa. Por bobo y no usar las cosas como se deben :)
- ### Consulta de datos
	- Individual
	- Grupal
	- Materia
	- General
- ### Registros
	- Persistentes
	- Creacion
	- Modificacion
	- Baja
- ### Estudiante
	- Nombre 
	- Edad
	- Grupo
	- Datos de familia
		- Nombre de familiar
		- Relacion del familiar
		- Numero de contacto familiar
	- Calificaciones
		- Materia
		- Calificacion
	-  Promedio
	- Rendimiento
## Manual de uso
Al ejecutar el programa serás recibido con el siguiente menu:
```
*** *** *** SIIAU *** *** ***
Inicio del registro de alumnos
¿Que operacion deseas realizar?
(M) Modificar base de datos de alumnos
(L) Listar en base de datos
(E) Eliminar la base de datos
(S) Salir
Opcion: 
```
Este espera por input que determinara la continuación del programa, las posibilidades son las siguentes:
- [Menu de modificacion de registros](#Modificacion-de-registros)
- [Menu de listado de registros](#Listado-de-registros) 
- [Confirmacion de borrado de la  base de datos](#Eliminar-todos-los-registros)
- [Salir](#Salir)
### Modificacion de registros
Al seleccionar esta opcion te encuentras con el siguente menu:
```
¿Que operacion deseas realizar?
(C) Dar de alta un nuevo alumno
(M) Modificar registro
(B) Dar de baja a un alumno
```
Espera por le input y te redirigé al siguiente menu,  las opciones son las siguientes:
- [Dar de alta](#Dar-de-alta)
- [Modificar registro](#Modificar-registro)
- [Dar de baja](#Dar-de-baja)
#### Dar de alta
Al seleccionar esta opcion te encontrarás con tres menús que cuentan con varias prompts esperando algun input
##### Datos del estudiante
```
*** Datos del estudiante ***
Ingrese el nombre del estudiante: Eduardo Dominguez Padilla
Ingrese la edad del estudiate: 18
Ingrese el grupo del estudiante: A

```

##### Datos de familiar
```
*** Datos de familiar ***
Ingrese el nombre del familiar: Maria Padilla
Ingrese la relacion del familiar con el estudiante: Mama
Ingrese el numero telefonico del familiar: 3781122233
```
##### Calificaciones
```
*** Ingreso de calificaciones ***
Nombre de la materia: Calculo
Calificacion de la materia: 100
Añadir otra materia (a) Terminar el registro (C): 
```
Podrás añadir cuantas materias desees y terminar el registro cuando quieras.
#### Modificar registro
Al seleccionar esta opcion se listarán todos los registros en la base de datos y te dará opción a ingresar el ID del registro que deseas modificar o a filtar.
<span style="background-color: #2c333d">Ver seccion de listado para conocer las opciones de [filtrado](#Listado-de-registros)</span>

^0331a8
```
*** --- Datos del estudiante --- ***
- ID del estudiante: 1
- Nombre del estudiante: Pedro Paramo
- Edad del estudiante: 21
- Promedio del estudiante: 98.50
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Guadalupe
- Relacion con el alumno: Mama
- Numero telefonico: 3781432322
*** --- Calificaciones --- ***
Mecanica: 97.00
Calculo: 100.00

*** --- Datos del estudiante --- ***
- ID del estudiante: 2
- Nombre del estudiante: Eduardo Dominguez Padilla
- Edad del estudiante: 18
- Promedio del estudiante: 100.00
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Padilla
- Relacion con el alumno: Mama
- Numero telefonico: 3781122233
*** --- Calificaciones --- ***
Calculo: 100.00

(f) Filtrar	(i) Ingresar el ID

```

Después de ingresar el ID serás presentado con [este menú](#Dar-de-alta)
Si ingresas una opcion invalida te forzará a ingresar el ID.
#### Dar de baja
Al ingresar  esta opción serás presentado con el mismo [menu](#^0331a8) y opciones que en [modificar](#Modificar-registro).
### Listado de registros
Al seleccionar esta opción te encuentras con el siguiente menú:
```
¿Que operacion deseas realizar?
(A) Listar todos los alumnos
(I) Listar por ID
(G) Listar por grupo
(M) Listar por materia
Opcion: 
```
Espera por tu input y muestra los registros o un nuevo menú, las  opciones son:
#### Listado general
Al seleccionar esta opcion simplemente lista todos los registros y espera por un ENTER para continuar. (Si ingresas cualquier caracter el programa se romperá)
Si al ejecutar un listado no muestra ningun resultado significa que no hay registros que cumplan dichos requisitos.
```
*** --- Datos del estudiante --- ***
- ID del estudiante: 1
- Nombre del estudiante: Pedro Paramo
- Edad del estudiante: 21
- Promedio del estudiante: 98.50
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Guadalupe
- Relacion con el alumno: Mama
- Numero telefonico: 3781432322
*** --- Calificaciones --- ***
Mecanica: 97.00
Calculo: 100.00

*** --- Datos del estudiante --- ***
- ID del estudiante: 2
- Nombre del estudiante: Eduardo Dominguez Padilla
- Edad del estudiante: 18
- Promedio del estudiante: 100.00
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Padilla
- Relacion con el alumno: Mama
- Numero telefonico: 3781122233
*** --- Calificaciones --- ***
Calculo: 100.00

Pulsa enter para continuar 
```
#### Listado individual
Al seleccionar esta opcion te pedirá el ID del registro que quieras mostrar y lo imprimirá
```
Ingresa el id del estudiante: 
2
*** --- Datos del estudiante --- ***
- ID del estudiante: 2
- Nombre del estudiante: Eduardo Dominguez Padilla
- Edad del estudiante: 18
- Promedio del estudiante: 100.00
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Padilla
- Relacion con el alumno: Mama
- Numero telefonico: 3781122233
*** --- Calificaciones --- ***
Calculo: 100.00
Pulsa enter para continuar 
```
#### Listado grupal
Al seleccionar esta opción te pedirá el grupo de los registros que queiras mostrar y los imprimirá
```
*** --- Datos del estudiante --- ***
- ID del estudiante: 1
- Nombre del estudiante: Pedro Paramo
- Edad del estudiante: 21
- Promedio del estudiante: 98.50
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Guadalupe
- Relacion con el alumno: Mama
- Numero telefonico: 3781432322
*** --- Calificaciones --- ***
Mecanica: 97.00
Calculo: 100.00
*** --- Datos del estudiante --- ***
- ID del estudiante: 2
- Nombre del estudiante: Eduardo Dominguez Padilla
- Edad del estudiante: 18
- Promedio del estudiante: 100.00
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Padilla
- Relacion con el alumno: Mama
- Numero telefonico: 3781122233
*** --- Calificaciones --- ***
Calculo: 100.00
Pulsa enter para continuar
```
#### Listado por materia
Al seleccionar esta opción te pedirá la materia de los registros que quierás mostar y los imprimirá
```
** --- Datos del estudiante --- ***
- ID del estudiante: 1
- Nombre del estudiante: Pedro Paramo
- Edad del estudiante: 21
- Promedio del estudiante: 98.50
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Guadalupe
- Relacion con el alumno: Mama
- Numero telefonico: 3781432322
*** --- Calificaciones --- ***
Mecanica: 97.00
Calculo: 100.00
*** --- Datos del estudiante --- ***
- ID del estudiante: 2
- Nombre del estudiante: Eduardo Dominguez Padilla
- Edad del estudiante: 18
- Promedio del estudiante: 100.00
- Rendimiento: EXCELENTE
*** --- Datos de la familia --- ***
- Nombre del familiar: Maria Padilla
- Relacion con el alumno: Mama
- Numero telefonico: 3781122233
*** --- Calificaciones --- ***
Calculo: 100.00
```
### Eliminar todos los registros
Al seleccionar esta opcion tendras una promt preguntando si estas seguro de querer realizar esta operacion
```
Estas seguro de querer eliminar la base de datos? (S)si (X)no
```
Cualquier input diferente de 'S'  será tomada como No.
### Salir 
Al  seleccionar esta opción serás despedido con un pequeño mensaje y terminará la ejecución del programa.
```
Nos vemos :)
```
