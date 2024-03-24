#include "operadoresSobrecargados.hpp"

/*****************************************************************************
 * LECTURA
 ******************************************************************************/
//506117   EDGAR_MUNOZ_VERGEL_Urologia   337.03

bool operator>>(ifstream &archMedico, struct StMedico &medico) {
    medico = StMedico();
    char nombreEspecialidad[60];
    archMedico >> medico.codigo;
    if (archMedico.eof()) return false;
    archMedico >> nombreEspecialidad >> medico.tarifaPoxConsulta;
    int i = 0;
    while ((nombreEspecialidad[i] >= 'A' and nombreEspecialidad[i] <= 'Z') or (nombreEspecialidad[i] == '_'))i++;
    strncpy(medico.nombre, nombreEspecialidad, i - 2);
    medico.nombre[strlen(medico.nombre) + 1] = '\0';
    strncpy(medico.especialidad, nombreEspecialidad + i - 1, strlen(nombreEspecialidad) - i + 1);
    medico.especialidad[strlen(medico.especialidad) + 1] = '\0';
    return true;
}

// 43704548   Vizcardo/Maribel   960851431

bool operator>>(ifstream &archPaciente, struct StPaciente &paciente) {
    paciente = StPaciente();
    archPaciente >> paciente.dni;
    if (archPaciente.eof()) return false;
    archPaciente >> paciente.nombre >> paciente.telefono;
    paciente.numeroDeCitas = 0;
    paciente.totalGastado = 0.0;
    for (int i = 0; i < 20; i++) {
        paciente.citas[i] = StCita();
    }
    return true;
}

// 43704548   892133   9/09/2022

int operator>>(ifstream &archCita, struct StCita &cita) {
    cita = StCita();
    int dniPaciente, dia, mes, anho;
    char c;
    archCita >> dniPaciente;
    if (archCita.eof()) {
        cita = StCita();
        return -1;
    }
    archCita >> cita.codigoDelMedico >> dia >> c >> mes >> c>> anho;
    cita.fecha = anho * 10000 + mes * 100 + dia;
    cita.tarifaPorConsulta = 0.0;
    memset(cita.especialidad, 0, sizeof (cita.especialidad));
    return dniPaciente;
}

/*****************************************************************************
 * BUSQUEDA
 ******************************************************************************/

bool operator<=(struct StCita &cita, struct StMedico *arregloMedico) {
    for (int i = 0; arregloMedico[i].codigo != 0; i++) {
        if (cita.codigoDelMedico == arregloMedico[i].codigo) {
            strcpy(cita.especialidad, arregloMedico[i].especialidad);
            cita.tarifaPorConsulta = arregloMedico[i].tarifaPoxConsulta;
            return true;
        }
    }
    return false;
}

/*****************************************************************************
 * AGREGACION
 ******************************************************************************/

void operator+=(struct StPaciente &paciente, const struct StCita cita) {
    int i;
    for (i = 0; paciente.citas[i].codigoDelMedico != 0; i++); // busqueda de la última cita
    //guardamos los valores
    paciente.citas[i].codigoDelMedico = cita.codigoDelMedico;
    strcpy(paciente.citas[i].especialidad, cita.especialidad);
    paciente.citas[i].fecha = cita.fecha;
    paciente.citas[i].tarifaPorConsulta = cita.tarifaPorConsulta;
    paciente.citas[i + 1].codigoDelMedico = 0;
}

/*****************************************************************************
 * GASTOS
 ******************************************************************************/

void operator++(struct StPaciente &paciente) {
    for (int i = 0; paciente.citas[i].codigoDelMedico != 0; i++) {
        paciente.totalGastado += paciente.citas[i].tarifaPorConsulta;
    }
}

/*****************************************************************************
 * IMPRESION
 ******************************************************************************/

void operator<<(ofstream &output, const struct StPaciente paciente) {
    output << left << setprecision(2) << fixed; // configuracion base de la salida
    output << setw(30) << "  DNI" << setw(30) << "NOMBRE" << "TELEFONO\n";
    output << setw(25) << paciente.dni << setw(35) << paciente.nombre << paciente.telefono << endl;
    output << "RELACION DE CITAS\n";
    output << setw(5) << "No." << setw(15) << "FECHA" << setw(20) << "CODIGO DEL MEDICO"
            << setw(20) << "ESPECIALIDAD" << "TARIFA\n";
    int fecha[3];
    for (int i = 0; paciente.citas[i].codigoDelMedico != 0; i++) {
        output << (i + 1) << ')';
        obtenerFecha(fecha, paciente.citas[i].fecha);
        output << setfill('0') << right;
        output << setfill('0') << right << setw(2) << fecha[0]<< '/'
                << setfill('0') << right <<  setw(2) << fecha[1] << '/'
                << setfill(' ') << left << setw(17) << fecha[2];
        output << left << setprecision(2) << fixed; // configuracion base de la salida
        output << setw(15) << paciente.citas[i].codigoDelMedico << setw(20) << paciente.citas[i].especialidad << paciente.citas[i].tarifaPorConsulta << endl;
    }
    output << "MONTO TOTAL GASTADO: " << paciente.totalGastado << endl;
}

void obtenerFecha(int *fecha, int fechaCompuesta) {
    fecha[0] = fechaCompuesta % 100;
    fecha[1] = ((fechaCompuesta / 100) % 100);
    fecha[2] = fechaCompuesta / 10000;
}
