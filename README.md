#  Get Next Line

##   ¿Qué es esto?

Este proyecto consiste en implementar la función `get_next_line`, que permite leer un archivo o entrada estándar línea a línea.

##   ¿Cómo funciona?

`get_next_line(fd)`, la función lee del file descriptor (`fd`) y te devuelve una línea completa, incluyendo el salto de línea (`\n`). Internamente, mantiene una caché de datos leídos para optimizar el rendimiento y evitar lecturas innecesarias.

- Si hay más contenido por leer, puedes seguir llamándola hasta obtener `NULL`, lo que indica el final del archivo o un error.

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

### Tester para Get Next Line con Don Quijote
Este tester evalúa exhaustivamente mi implementación de `get_next_line` utilizando la obra completa de *Don Quijote de la Mancha* como archivo de prueba. Está diseñado para verificar:

- Manejo correcto de archivos muy grandes
- Funcionamiento con diferentes tamaños de buffer
- Gestión adecuada de memoria (sin leaks)
- Comportamiento con líneas de distintas longitudes

## Cómo usar

### Compilación
```sh
make
```

```sh
./tester don_quijote.txt
```

```sh
valgrind --leak-check=full --show-leak-kinds=all ./tester don_quijote.txt
```

##  Nota
- El tamaño del buffer (`BUFFER_SIZE`) puede ajustarse al compilar.
