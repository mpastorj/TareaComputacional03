#include <iostream>
#include <libpq-fe.h>

using namespace std;

PGconn *cnn = NULL;
PGresult *result = NULL;

char servidor[]="sebastian.cl";//Nombre del servidor
char puerto[]="5432";//Numero del puerto
char bd[]="iswdb";//Nombre de la base de datos
char user[]="isw";//Nombre de usuario
char password[]="isw";//autentificación

class Conexion{

 int i;

 public:

 void conectar();
 void consulta(const char *consulta);    
    

};



void Conexion::conectar(){

cnn = PQsetdbLogin(servidor,puerto,NULL,NULL,bd,user,password); 

if (PQstatus(cnn) != CONNECTION_BAD) {
        cout << "Estamos conectados a PostgreSQL!" << endl;
        }
else {
        cout << "Error de conexion" << endl;
    }

}


void Conexion::consulta(const char *consulta){

result = PQexec(cnn, consulta);

if (result != NULL) {
            int tuplas = PQntuples(result);
            int campos = PQnfields(result);
            cout << "No. Filas:" << tuplas << endl;
            cout << "No. Columnas:" << campos << endl;

            cout << "Los nombres de las columnas son:" << endl;

            for (i=0; i<campos; i++) {
                cout << PQfname(result,i) << " | ";
            }

            cout << endl << "Contenido de la tabla" << endl;

            for (i=0; i<tuplas; i++) {
                for (int j=0; j<campos; j++) {
                    cout << PQgetvalue(result,i,j) << " | ";
                }
                cout << endl;
            }
        }



}
