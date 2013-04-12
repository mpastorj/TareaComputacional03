#include <iostream>
#include <libpq-fe.h>
#include "Conexion.cpp"

/*

Librería utilizada para compilar : http://www.postgresql.org/docs/8.2/interactive/libpq.html

Compilado con g++ en Ubuntu 10.04 :

g++ main.cpp -o "nombre del ejecutable" -Wall -I/usr/include/postgresql -L/usr/include/postgresql -lpq

Instalación de la libreria:

sudo apt-get install libpq-dev

*/

using namespace std;

int main()
{

cout << "INTEGRANTES: " << endl;
cout <<"- Marilyn Pastor Jaque"<< endl; 
cout <<"- Monica Riquelme" << endl;
cout <<"- Pedro Cuevas Meza" << endl;
Conexion cn ;

cn.conectar();

cn.consulta("SELECT c.docente_id AS DOCENTE, ROUND(AVG(a.nota),6) AS PROMEDIO, ROUND(STDDEV(a.nota),6) AS DESVIACION FROM asignaturas_cursadas a, cursos c WHERE c.curso_id = a.curso_id GROUP BY c.docente_id");

cn.desconectar();

}
