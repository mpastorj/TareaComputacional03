#include <iostream>
#include <libpq-fe.h>
#include "Conexion.cpp"


int main()
{

Conexion cn ;

cn.conectar();

cn.consulta("SELECT * FROM asignaturas_cursadas");


}
