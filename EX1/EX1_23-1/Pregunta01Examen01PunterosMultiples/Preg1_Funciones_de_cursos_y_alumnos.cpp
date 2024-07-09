#include "Preg1_Funciones_de_cursos_y_alumnos.hpp"

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *curso_name,const char *escala_name){
    ifstream file_curso;
    AperturaDeUnArchivoDeTextosParaLeer(file_curso,curso_name);
    
    int size = 0, capacity = 0;
    while (true) {
        
        if(size == capacity) incrementarMemoriaCurso(cursos, cursos_cred,size, capacity);
        
    }

    
}

void incrementarMemoriaCurso(char ***&cursos,double *&cursos_cred,
        int &size,int &capacity){
    
}
