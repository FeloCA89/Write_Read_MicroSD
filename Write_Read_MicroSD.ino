#include <SPI.h>       // Libreria para la comunicacion SPI
#include <SD.h>        // Libreria para la tarjeta SD, Revisar que la SD este en modo "FAT" o "FAT32"

#define SSpin 10       // Definiendo la constante para el pin 10 

File archivo;          // Declarando el objeto archivo de tipo file

void setup (){
 Serial.begin(9600);                           // Inicializacion del monitor serial
 Serial.println("Inicializando tarjeta ...");  // Imprimir el texto en el monitor serial
 if (!SD.begin(SSpin)){                        // Funcion NOT para la inicializando la tarjeta SD
   Serial.println("Fallo la inicializacion");  // Imprimir el mensaje de fallo si la inicializacion de la SD no es posible
   return;                                     // Detener el codigo en caso de no poder inicializar la SD
 }  

 Serial.println("Inicializacion correcta");      // Imprimir el texto en el monitor serial
 archivo = SD.open("prueba.txt", FILE_WRITE);    // Abrir el archivo "prueba.txt" en caso de no existir lo crea (archivo tomara un valor booleano)

 if(archivo){                                                                      // Si el archivo se pudo crear entra al condicional
   archivo.println("Se escribio correctamente dentro del archivo ¡¡¡felicidades!!!"); // Imprimir dentro del archivo
   Serial.println("Escribiendo dentro del archivo prueba.txt ...");                // Imprime en el monitor serial como control del proceso
   archivo.close();                                                                // Cierra el archivo 
   Serial.println("Escritura correcta");                                           // Imprime en el monitor serial como control del proceso
 } 
 
 else {
   Serial.println("Error en la apertura de prueba.txt");                           // En caso de no poder crear el archivo en la SD notifica en el monitor serial 
 }

 archivo = SD.open("prueba.txt");                      // Solamente abrir el archivo "prueba.txt" (archivotomara un valor booleano) 
 if (archivo){                                         // Si el archivo se pudo abrir entra al condicional
   Serial.println("contenido de prueba.txt :");        // Imprime el texto en el monitor serial
   while(archivo.available()){                         // La funcion archivo.available() retorna true mientras exixta contenido en el archivo
     Serial.write(archivo.read());                     // Escribe en el monitor serial cada caracter leido hasta el final
   }
   archivo.close();                                    // Alterminar de leer el archivo cierra el el mismo
 }
 else {
   Serial.println("Error en la apertura de prueba.txt"); // En caso de no poder abrir el archivo lo notifica en el monitor serial
 }
}

void loop(){
 // No es necesario ya que solo queremos que se ejecute una sola vez  
}
