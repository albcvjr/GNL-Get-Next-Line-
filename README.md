*Este proyecto ha sido creado como parte del currículo de 42 por acuevas.*

# Get Next Line

## Descripción

**Get Next Line** es un proyecto del currículo de 42 cuyo objetivo es desarrollar una función capaz de leer y devolver una línea de un archivo o descriptor de archivo en cada llamada.

La función `get_next_line` permite leer el contenido de un archivo progresivamente, sin necesidad de cargarlo por completo en memoria. Para ello, utiliza la función `read` y un tamaño de lectura configurable mediante la macro `BUFFER_SIZE`.

El proyecto permite trabajar conceptos fundamentales de C, como:

- Lectura de archivos mediante descriptores.
- Gestión dinámica de memoria con `malloc` y `free`.
- Uso de variables estáticas.
- Manipulación y concatenación de cadenas.
- Gestión de memoria y prevención de fugas.
- Control de errores y tratamiento del final de archivo (EOF).

### Funcionamiento

La función principal es:

```c
char *get_next_line(int fd);
```

- Recibe un descriptor de archivo (`fd`).
- Lee el contenido utilizando `read`.
- Devuelve una línea por llamada.
- Si encuentra un salto de línea (`\n`), devuelve la línea incluyendo dicho carácter.
- Si llega al final del archivo y quedan caracteres pendientes, devuelve la última línea aunque no termine en `\n`.
- Cuando no quedan más caracteres por leer, devuelve `NULL`.

El tamaño de lectura se puede modificar mediante `BUFFER_SIZE`, permitiendo comprobar el funcionamiento de la función con diferentes tamaños de búfer.

## Instrucciones

### Compilación

El proyecto contiene los siguientes archivos:

- `get_next_line.c`: contiene la función principal y la gestión de la lectura.
- `get_next_line_utils.c`: contiene las funciones auxiliares para manipular cadenas y gestionar el contenido almacenado.
- `get_next_line.h`: contiene las declaraciones necesarias y la configuración de `BUFFER_SIZE`.

Para compilar el proyecto junto con un archivo `main.c`, se puede utilizar:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

El valor de `BUFFER_SIZE` puede modificarse para realizar pruebas con diferentes tamaños de lectura.

### Ejecución

Una vez compilado, se puede ejecutar el programa con:

```bash
./gnl
```

Para probar la lectura de un archivo, se puede utilizar un descriptor obtenido mediante `open`, o bien trabajar con la entrada estándar (`stdin`).

## Recursos

Durante el desarrollo del proyecto se han utilizado los siguientes recursos:

- **Manual de funciones de C:**
  - `man read`
  - `man malloc`
  - `man free`
- **Documentación y material de 42:** subject oficial de Get Next Line.
- **Pruebas y depuración:** compilación con diferentes valores de `BUFFER_SIZE` y comprobación del comportamiento con archivos de distintos tamaños, líneas vacías y archivos sin salto de línea final.
- **Gestión de memoria:** comprobaciones para detectar fugas y errores relacionados con la reserva y liberación de memoria.

### Uso de inteligencia artificial

Se ha utilizado inteligencia artificial como herramienta de apoyo durante el aprendizaje y desarrollo del proyecto, principalmente para:

- Comprender el funcionamiento de `read` y los descriptores de archivo.
- Repasar conceptos de memoria dinámica y variables estáticas.
- Analizar la lógica de lectura y conservación de los caracteres pendientes.
- Plantear casos de prueba.

El desarrollo del proyecto se ha realizado de forma progresiva, trabajando sobre la implementación y comprensión de cada una de sus partes.