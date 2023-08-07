Next I present my own study guide for make the project, is in spanish because was just for me, but now I think is knowledge that deserves to be shared.

# Get next line - 42
A continuación, quisiera compartir un poco de la información que estudié y leí que me ayudó a crear un get next line relativamente decente.  Aquí no comparto información de como está hecho pero si algunos hints de lo que usé para resolver este problema.

## Ficheros
Cuando un proceso necesita acceder a un recurso, debe realizar las siguientes operaciones:

1. **Abrir el fichero correspondiente a dicho recurso:** el proceso indica al sistema la ruta del fichero, especificando su intención de abrirlo para lectura (obtener información del recurso), escritura (enviar información al recurso) o lectura/escritura; el sistema concederá el tipo de acceso solicitado según las características del recurso (teclado, pantalla, …) y los permisos que el usuario efectivo del proceso posea sobre el fichero. Como respuesta, el sistema devolverá al proceso el **descriptor** (o descriptor de fichero) con el que el proceso podrá acceder al fichero.
2. **Acceder al fichero/recurso usando el descriptor suministrado por el sistema:** el proceso indicará el descriptor al kernel, éste localiza el fichero y accede al recurso asociado.

Cada **proceso** tiene su propia tabla de **descriptores** para acceder a los **recursos/ficheros**; el fichero que un proceso tenga asociado al descriptor «n» es independiente del que puedan tener asociado para ese mismo descriptor los demás procesos del sistema. El conjunto de descriptores que tiene asociados un determinado proceso puede obtenerse con `ls /proc/PID/fd/`, cambiando `PID` por el identificador de dicho proceso
## **Función Open()**

Esta función puede aceptar diferentes parámetros, entre ellos las "flags", que  basicamente son indicadores que controlan la forma en la que se va a abrir el archivo. Estas flags se especifican como argumentos adicionales en la función **`open()`** se usan para especificar como se accederá al archivo y qué operaciones serán permitidas al abrirlo.

Existen dos tipos principales de flags utilizadas con la función **`open()`**: las flags de estatus (status flags) y las flags de creación (creation flags).

En el lenguaje de programación C, la función **`[open()`**](https://man7.org/linux/man-pages/man2/open.2.html) se utiliza para abrir o crear un archivo en el sistema operativo. 

```c
fd = Open("ruta de acceso al documento", flags)
```

### Flags de Estatus

- **`O_RDONLY`** (Open Read-Only): Abre el archivo en modo de solo lectura.
- **`O_WRONLY`** (Open Write-Only): Abre el archivo en modo de solo escritura.
- **`O_RDWR`** (Open Read/Write): Abre el archivo en modo de lectura y escritura.
- **`O_APPEND`** (Open Append): Permite agregar contenido al final del archivo en lugar de sobrescribirlo.
- **`O_TRUNC`** (Open Truncate): Trunca (borra) el contenido existente del archivo al abrirlo.
- **`O_CREAT`** (Open Create): Crea el archivo si no existe.
- **`O_EXCL`** (Open Exclusive): Utilizado junto con **`O_CREAT`**, asegura que el archivo no exista previamente.

### Flags de creación:

Las flags de creación se utilizan en conjunto con la flag **`O_CREAT`** y determinan los permisos y atributos del archivo recién creado. Podemos encontrar:

- **`S_IRUSR`** (User Read Permission): Permisos de lectura para el usuario propietario.
- **`S_IWUSR`** (User Write Permission): Permisos de escritura para el usuario propietario.
- **`S_IRGRP`** (Group Read Permission): Permisos de lectura para el grupo.
- **`S_IWGRP`** (Group Write Permission): Permisos de escritura para el grupo.
- **`S_IROTH`** (Others Read Permission): Permisos de lectura para otros usuarios.
- **`S_IWOTH`** (Others Write Permission): Permisos de escritura para otros usuarios.

Estas flags de creación se especifican como argumentos adicionales después de la flag **`O_CREAT`**.

### File descriptors -fd —>Retorno

El file descriptor es un numero que usualmente no muy alto, que representa algo a lo que se puede mandar bytes, o desde donde se puede leerlos. En UNIX

La función **`open()`** **devuelve un descriptor de archivo válido** si la operación de apertura es exitosa. Si ocurre un error, devuelve -1, indicando que la apertura del archivo ha fallado. 

Los descriptores de archivos o [identificadores de archivos](https://www.baeldung.com/linux/stale-file-handles#file-handle) son identificadores enteros que especifican estructuras de datos. El kernel de Linux se refiere a estas estructuras como [estructuras de archivos](https://elixir.bootlin.com/linux/v5.15/source/include/linux/fs.h#L965), ya que describen archivos abiertos.
## Ulimit y limites

Para el desarrollo de una función es posible revisar previamente los limites que tenemos disponibles usando la función ulimit

Vemos *ilimitado*  en la salida cuando ejecutamos *ulimit* sin ningún argumento. Esto significa que podemos acceder a cualquier recurso en el sistema como el usuario actual.

Además, podemos usar la opción *-a* para ver nuestros límites para cada recurso.

**Un límite blando nos restringe, pero podemos aumentarlo aún más** usando el comando *ulimit* .

**El limite blando** para el total de descriptores abiertos es 1024.

Un limite blando es diferente a un **limite estricto**, puesto que el estricto no podemos aumentarlo **como un usuario sin privilegio**

Podemos ver el ***límite estricto*** en la cantidad de descriptores de archivos abiertos agregando la opción *-H* a nuestro último comando:

```c
$ ulimit -n -H
4096
```

Una vez que conocemos los valores anteriores, podemos usar el comando *ulimit* nuevamente para aumentar nuestros límites suaves, siempre que estén por debajo de los límites estrictos.

En la práctica, podemos insertar el nuevo valor límite suave después del recurso que queremos cambiar. Dado que conocemos el límite estricto ( *4096* ) para los descriptores de archivos abiertos ( *-n* ), intentaremos aumentar el límite suave hasta eso:

```c
$ ulimit -n 4096
```

**Es importante destacar que intentar aumentar el límite suave a un valor más alto que el límite duro simplemente generará un error.**

```c
$ ulimit -n 5000
**sh: error setting limit: Operation not permitted**
```

## Función Read()

Esta función se usa para leer datos desde un archivo abierto o un descriptor de archivo. 

```c
ssize_t read(int fd, void *buffer, size_t count);
```

Parámetros:

- **`fd`**: **El descriptor de archivo del archivo** desde el cual se leerán los datos. Puede ser obtenido al abrir el archivo con la función **`open()`** o también puedes utilizar **`0`** (valor especial) para leer desde la entrada estándar (stdin).
- **`buffer`**: Un puntero a un área de memoria donde se almacenarán los datos leídos.
- **`count`**: El número máximo de bytes a leer.

### Retorno

La función **`read()`** devuelve el número de bytes leídos exitosamente, o bien, devuelve **`-1`** si ocurre un error durante la lectura. 

**En caso de que se alcance el final del archivo, la función retornará `0`**.

Es importante tener en cuenta que la función **`read()`** es una llamada de sistema y la lectura puede ser bloqueante, lo que significa que si no hay suficientes datos disponibles para leer en ese momento, el programa se quedará esperando hasta que se disponga de los datos necesarios o se alcance el final del archivo.

Tomemos como ejemplo:

```c
ssize_t bytesLeidos = read(fd, buffer, sizeof(buffer));
```

## El buffer

Se refiere a la región de memoria utilizada para almacenar temporalmente los datos que se llen desde un archivo o un descriptor de archivo.

La lectura de datos desde un archivo puede ser un proceso costoso en términos de tiempo de ejecución por lo que el uso del buffer ayuda a minimizar el numero de llamadas al sistema operativo.

La función read puede llenar el buffer con una cantidad especifica de datos a la vez.

> **Los datos en el buffer son volátiles y pueden sobreescribirse por otras operaciones de lectura o escritura**
> 

**“Este buffer se encuentra en el espacio de memoria del programa y se utiliza para almacenar temporalmente los datos leídos de una fuente, como un archivo o una entrada estándar.”** El tamaño del buffer y su ubicación exacta dependen de la implementación del compilador y el sistema operativo en el que se esté ejecutando el programa. Sin embargo, generalmente el buffer se asigna en la pila de ejecución del programa o en el montón (heap) si se ha utilizado la función **`malloc`** para asignar memoria dinámica.

---

# Variables y tipos de variables

Las variables son nombres que les damos a unos espacios de memoria reservados para ser manipulados en nuestro programa. Es posible especificar el tipo y tamaño de estos espacios de memora a través de la elección de su tipo.

### Variables Locales

Este tipo de variables tienen un tiempo de vida relativamente corto. Son declaradas dentro de las funciones y solamente existen en la RAM mientras la función misma exista, cuando la función deje de existir así mismo la variable va a desaparecer.

Este tipo de variables solo funcionan dentro de nuestras funciones, no es posible llamar dichas variables desde otras funciones.

> Si se desea usar el valor de una variable declarada en una función para ser manipulada en otra función es posible hacerlo a través de las direcciones de memoria donde se encuentra alojada la variable, a esto lo conocemos como puntero.
> 

### Variables Globales

Una variable global se declara fuera de cualquier función o bloque de código en un programa; como su nombre lo indica tiene un alcance global, lo que significa que están disponibles y pueden entrar desde cualquier parte del programa o desde otras funciones.

Las variables globales tiene una duración extendida, esto significa que se mantienen durante el tiempo de la ejecucción del programa, su valor persiste a lo largo del tiempo.

Su uso debe ser considerado cuidadosamente puesto que pueden tener implicaciones de diseño y mantenimiento del código que pueden dificultar su uso, entre estos:

- Ocultamiento de información: Dado que cualquier función puede acceder a ellas es posible que en algún momento de la ejecución la variable global sea modificada lo que puede dificultar la realización de seguimiento y comprensión del flujo de datos.
- Conflicto de nombres: En ocasiones puede suceder que los nombres de las variables globales coincidan con los nombres de las variables locales, este conflicto puede producir comportamientos inesperados y errores dificiles de detectar y solucionar.
- Dificultad para entender el código: El uso excesivo de variables globales puede dificultar el razonamiento y entendimiento del programa.

La recomendación general es que solo se empleen variables globales en caso de ser necesario y salvo las dificultades asociadas a la compresión del código estén solucionadas

### Variables estáticas

Las variables pueden ser declaradas como estáticas para aumentar el alcance de la misma, hasta que el mencionado alcance abarque la totalidad del archivo que la contiene.

Se puede acceder a estas variables desde cualquier lugar dentro del archivo que las contiene

Las variables estáticas tienen alance sobre el archivo que las contiene, esto quiere decir que están restringidas a utlilizarse únicamente en un archivo determinado.

Las variables globales pueden ser usadas fuera del archivo que las contiene originalmente

### Constantes

Las constantes son valores que como su nombre lo indica no pueden cambiar durante la ejecución de un programa. Se usan para guardar valores fijos y previamente definidos para ser usados posteriormente en el código.

Su uso considera grandes ventajas:

- Legibilidad y mantenibilidad: Al asignar un nombre significativo a un valor constate, se mejora la legibilidad del código. En lugar de tener valores literales dispersos por el código, las constantes permiten dar un nombre descriptivo al valor, facilitando la comprensión y el mantenimiento del código.
- Evitar errores: al definir un valor constante, se evitan errores inadvertidos al modificar accidentalmente su valor en el programa.
- Reutilización del código: Cuando se definen constantes es posible la reutilización del código, ya que bastará solamente con cambiar el valor de la constante para poder realizar análisis mas completos.
- Optimización de un programa: Al usar constantes es posible que el compilador realice optimizaciones esto hará el código mas eficiente.
- Mejor comprensión del código: generalmente se tomarán como constantes aquellas variables que se repitan múltiples veces en el código y que como se ha aclarado antes,  su valor no varié en el tiempo, será mas fácil hacer seguimiento del desarrollo de un código cuando se tiene una constante para relacionar.

Las constantes pueden ser de cualquier tipo básico: entero, flotante, carácter o cadena, de modo que podrán tratarse como una variable regular con la diferencia de que su valor se mantedrá después de su definición.

```c
#define <indentificador> <valor>
```

> *Sé lo que estás pensando… “Bueno y ¿por qué no simplemente leemos todo el texto y luego hacemos un split para que nuestro carácter de separación sea el “\n”?”, no olvides prestar atención al texto de referencia, se indica que no es posible hacer esa gracia. Nada más imagina tener el quijote de la mancha versión extendida, tendrías que reservar memoria suficiente para almacenar todo el texto y luego recorrerlo cada vez buscando los saltos de línea.  Y quizás cuentes con la mala suerte de que alguna prueba sea cargar el Quijote de la mancha completo y sin saltos de linea.*
> 

---

# Funciones de interés

Algunas funciones que pueden resultar útiles pueden ser:

### Función strchr()

Esta función ubica la primera aparición del caracter c en una cadena de caracteres, en este caso el caracter nulo se considera como parte de la cadena. La función devuelve un puntero al carácter localizado o NULO si el caracter no aparece en la cadena

```c
char *strchr(const char*s, int c);
```

### Función Calloc()

```c
void *calloc(size_t nitems, size_t size)
```

Es importante recordar que tanto Malloc() como Calloc() se usan para asignar memoria dinámica cuando se ejecuta un programa. Cuando se emplea malloc() el bloque de memoria empleado puede contener información “basura”, datos presentes  en esa ubicación antes de asignarla.

La función calloc asigna la memoria reservada y retorna un puntero a esta. 

La diferencia entre malloc y calloc es que malloc no establece la memoria asignada en cero, mientras que calloc si.

Los parámetros de esta función son:

- nitems→ El numero de elementos que serán asignados.
- Size→ El tamaño de los elementos

fd es el file descriptor generado en la función open() a la cual se le pasó por parametro el archivo “ejemplo.txt” y la condición de solo lectura.

El buffer se define del tipo **char buffer[100]**

Quizás la principal desventaja de usar calloc() en vez de malloc() es el hecho de que calloc() incluye un paso extra que implica inicializar el bloque de memoria asignado,  lo que en terminos de ejecución se traduce en tiempo. Dependiendo del programa este tiempo extra podrá ser despreciable.

### Función ft_strlen()

```c
size_t ft_strlen(const char *str)
```

Retorna la longitud de una cadena de caracteres. El conteo lo hace a traves de un ciclo while que busca el terminador nulo de la cadena en cada ciclo mientras va añadiendo valores a un contador.

### Función ft_strdup()

```c
char *ft_strdup(const char *s)
```

Devuelve un puntero a una nueva cadena de caracteres que es un duplicado de la cadena apuntada por s. La cadena duplicada termina en caracter nulo.

### Función ft_bzero()

```c
void bzero(void *s, size_t n);
```

Esta función pone ceros en los primeros n bytes del área que comienza en s.

## Funciones estaticas

Las funciones estaticas tienen un alcance muy limitado, no pueden ser llamadas por otros archivos fuente salvo aquellos donde se encuentran almacenadas.

Por lo tanto solo es visible dentro del archivo fuente en el que se declara, no se puede llamar directamente desde otros archivos.

Se destaca de otras funciones por su persistencia, por lo que mantiene su existencia a lo largo de la ejecución del programa, esta función permanece en memoria durante toda la vida util del programa.

Una función estatica puede acceder directamente a variables estaticas definidas en el mismo archivo fuente.
