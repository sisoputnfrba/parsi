# ParSI [![Build Status](https://travis-ci.org/sisoputnfrba/parsi.svg?branch=master)](https://travis-ci.org/sisoputnfrba/parsi)
## تجزیه کننده

Biblioteca para Parser lineas de archivos ESI 

### Ejemplo
Dentro de la carpeta de [ejemplo](https://github.com/sisoputnfrba/parsi/tree/master/ejemplo), hay un [código](https://github.com/sisoputnfrba/parsi/blob/master/ejemplo/main.c) que lee linea por linea un archivo, y lo interpreta con `ParSI`.

### Instalacion
Desde la consola clonar el repo, luego meterse dentro de la carpeta parsi y ahi ejecutar el comando sudo make install. 

### Uso
El usarlo es muy simple. Solo hace falta linkearlo tu ejecutable con `ParSI` y las `commons` _(`-lcommons -lparsi`)_, y el úso es darle de a una linea a la función [`parse`](https://github.com/sisoputnfrba/parsi/blob/master/src/parsi/parser.h#L54).
Recordar liberar la memoria corriendo la función auxiliar de `destruir_operacion`.
