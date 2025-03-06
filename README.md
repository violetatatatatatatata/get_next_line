#  Get Next Line

##   ¿Qué es esto?

Este proyecto consiste en implementar la función `get_next_line`, que permite leer un archivo o entrada estándar línea a línea. Es un ejercicio clásico en C que ayuda a mejorar la gestión de memoria dinámica y el uso de variables estáticas.

##   ¿Cómo funciona?

Cada vez que llamas a `get_next_line(fd)`, la función lee del file descriptor (`fd`) y te devuelve una línea completa, incluyendo el salto de línea (`\n`). Internamente, mantiene una caché de datos leídos para optimizar el rendimiento y evitar lecturas innecesarias.

- Si hay más contenido por leer, puedes seguir llamándola hasta obtener `NULL`, lo que indica el final del archivo o un error.
- La implementación usa `read()`, `malloc()`, y `free()`, gestionando la memoria correctamente para evitar leaks.

##   Archivos

- **`get_next_line.c`** → Implementación principal de la función.
- **`get_next_line_utils.c`** → Funciones auxiliares para manipular cadenas.
- **`get_next_line.h`** → Cabecera con definiciones y prototipos.

##   Cómo compilar

El proyecto se compila con un `Makefile`. Para compilarlo:

```sh
make
```

Para limpiar archivos objeto y binarios generados:

```sh
make clean
make fclean
```

Para recompilar desde cero:

```sh
make re
```

##  Nota
- El tamaño del buffer (`BUFFER_SIZE`) puede ajustarse al compilar.
