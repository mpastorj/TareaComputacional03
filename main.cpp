#include <iostream>
#include <libpq-fe.h>
#include "Conexion.cpp"


int main()
{

Conexion cn ;

cn.conectar();

cn.consulta("SELECT * FROM asignaturas_cursadas");

select c.docente_id, avg (a.nota), stdev(a.nota)
from asignaturas_cursadas a, cursos c
where c.curso_id = a.curso_id
group by c.docente_id;

select c.curso_id, c.anio, c.semestre, c.seccion, a.ac_id
from asignaturas_cursadas a, cursos c
where c.curso_id = a.curso_id
order by c.anio asc, c.semestre desc;



}
