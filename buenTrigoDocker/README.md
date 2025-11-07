# Contexto del proyecto:

La panadería El Buen Trigo produce diferentes tipos de panes: pan blanco, pan
integral, pan de centeno, pan dulce, entre otros. Actualmente, la gestión de la producción y
el control de inventarios se realizan de forma manual, lo que genera errores en el cálculo de
insumos, pérdidas por falta de control y demoras en la planificación de la producción.
Se requiere desarrollar un programa basado en el paradigma orientado a objetos que
permita automatizar las siguientes tareas:

1. Gestionar el inventario de materias primas tales como: harina, levadura, azúcar,
mantequilla, sal, entre otros.

2. Definir y registrar recetas para cada tipo de pan, indicando las cantidades de cada
ingrediente.

3. Controlar el proceso de producción, reduciendo automáticamente del inventario los
insumos utilizados según las recetas.

4. Llevar un registro del stock de productos terminados, es decir cantidad de panes
listos para la venta.

5. Consultar las cantidades actuales del inventario y del stock.

# Objetivos del sistema:

El sistema propuesto busca optimizar la gestión del inventario y de las recetas, permitiendo
un control preciso sobre los insumos utilizados en la producción. De esta forma, se evitan
desperdicios al registrar y supervisar el consumo real de materias primas, garantizando un
uso eficiente de los recursos. Además, el sistema monitorea la disponibilidad de productos
terminados listos para la venta, facilitando la planificación de nuevas producciones.
Finalmente, la automatización de los cálculos de consumo y reposición contribuye a mantener niveles óptimos de inventario, reduciendo errores manuales y mejorando la eficiencia operativa de la panadería.

# Funcionamiento del proyecto:

El programa esta tiene un patron de diseño Modelo , vista , controlador, es decir que las responsabildiades estan distribuidas entre clases del modelo , de la vista y el puente entre estas , que es el controlador.

Antes de explicar el funcionamiento de las clases me dispondre a explicar como se relaciona todo el proyecto, es decir nuestro archivo main:

# Archivo Main:

El archivo main contine una funcion que crea los usuarios correspondientes con sus respectivas propiedades, Estos usuarios se crean en la memoria dinamica del programa y se realcionan entre si por el inventario, clase central del programal.

despues va la funcion principal
ahi se crea una instancia del objeto vistaLogin, este se encarga de pedir el usuario .

Despues se crea el usuario con la funcion crear usuario y los datos que pasa el usuario, em realidad cualquier contraseña sirve siempre y cuando se respete el rol, ( dado que no hay base de datos aun ), y como todos comparten el mismo inventario no importa qeu panadero incia seccion.


Hay funciones de librerias que son dificiles de intepretar, pero explciare a continuacion:

1. make_unique crea una instancia real del objeto y la guarda en memoria dinámica. pero sin los peligros de liberar y todo eso , es como hacer un objeto de puntero y luego se lo pasaras a unique_ptr para crear el puntero inteligente

2. unique_ptr es un puntero inteligente de la libreria std talque permite crear punteros sin peligros de memoria, muy util

Apartir de aqui la vista se distribuye entre la vista del Panadero, la vista del encargado, y la vista del administrador


# MODELO VISTA CONTROLADOR 

Este proyecto tiene el diseño modelo, vista, controlador donde las clases estan distribuidas asi:

Vista:

1. VistaPanadero
2. VistaEncargadoInventario
3. VistaAdministrador
4. VistaLogin

Controlador:

1. ControladorRecetas
2. ControladorProduccion
3. ControladorInventario
4. ControladorReportes

Modelo:

1. Usuario
2. Panadero
3. EncargadoInventario
4. Administrador
5. IngredReceta
6. Receta
7. Pan
8. Inventario

Todo esto con el fin de tenre un proyecto bien modulado y facil de depurar. A continuacion explicare las clases de cada seccion del diseño

# VISTA

Aqui sere consiso y solo dire los requerimientos que suple cada vista 

VistaPanadero: 

1. muestra el menu de cosas que puede hacer

2. Pide los datos de una receta ( devuelve una tupla de un string que es el nombre de la receta , y un map de los ingredientes y la cantidad )

3. Muestra las recetas, que se le suministran en un vector

4. muestra si la produccion se pudo hacer efectivamente

5. muestra los panes que se le pasaron como un vector de tuplas {nombre , cantidad}

6. solicita los datos de produccion y no devuelve nada , solo modifica directamente la variable

7. muestra las recetas que hay para elegir 

8. verifica si la seleccion es valida

9. muestra que la receta fue satifactoriamente eliminada

10. muestra un mensaje recibido por paramentro

11. muestra que ingredientes faltan

















# 📦 C++ Dev Container con Debug en VS Code

Este proyecto contiene un entorno de desarrollo para **C++** usando **Dev Containers** en VS Code, con soporte para compilación, ejecución y depuración (local y remota con `gdbserver`).  

---

## 🔹 Requisitos previos

1. [Docker](https://docs.docker.com/get-docker/) instalado y corriendo.  
2. [Visual Studio Code](https://code.visualstudio.com/) instalado.  
3. Extensiones recomendadas:  
   - [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)  
   - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)  

---

## 🔹 Apertura del Dev Container

1. Clona este repositorio:  

    ```bash
    git clone https://github.com/usuario/cpp-docker.git
    cd cpp-docker
    ```

2. Abre la carpeta en VS Code:

    ```bash
    code .
    ```

3. VS Code detectará el archivo `.devcontainer/devcontainer.json`.
- Haz clic en **Reopen in Container**. Si no aparece pulsa **Ctrl+Shift+P** y luego buscas la opción **Reopen in Container**.
- Se construirá la imagen y abrirá un entorno con `g++`, `make`, `gdb`, `gdbserver`, `curl` y `nlohmann/json`.


## 🔹 Compilación y ejecución

Dentro del Dev Container:

```bash
make           # Compila con símbolos de depuración
make run       # Ejecuta el binario
make clean     # Limpia binarios
```

El binario generado es `main`.


## 🔹 Debugging en VS Code
El archivo `.vscode/launch.json` ya incluye la configuración de depuración:
- Debug (gdbserver :2345) → Permite depuración remota con `gdbserver`.
1. En una terminal del contenedor, compila y lanza `gdbserver`:
```bash
make gdbserver
```
Esto mostrará algo como:
```bash
Listening on port 2345
Waiting for gdb connection...
```
2. En VS Code pulsa **F5**. Se conectará al puerto *2345* y podrás depurar de forma remota.

## 🔹 Google Testing
Se debe modificar el archivo `tests/test_main.cpp` con los test que requeridos.

Dentro del Dev Container:

```bash
make google-test       # Ejecuta los test con la librería gtest de google
```

El binario generado es `test_runner`.