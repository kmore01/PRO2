#include "Estudiant.hh"

// No confundir double con int

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0; // se podria poner tis->dni, pero no hace falta pq no se puede confundir
  nota = -1;
  // amb_nota = false;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4); // Comprobar las precondiciones
  this->dni = dni; // this->dni es el atributo qe tiene el estudiante, se pone para no confndirlo con el parametro de la funcion
  nota = -1;
  // amb_nota = false;
}

void Estudiant::afegir_nota(double nota)
{
  if (this->nota != -1) 
    throw PRO2Excepcio(ER3); // Se acaba la ejecucion sacando el error ER3
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
  // amb_nota = true;
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (this->nota == -1) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  bool ambnota = true;
  if (nota == -1) ambnota = false;
  return ambnota;
}

double Estudiant::consultar_nota() const
{
  if (nota == -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
    // amb_nota = true;
  }
  else nota = -1;
}

void Estudiant::escriure() const
{
  if (nota != -1)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}

bool Estudiant::operator==(const Estudiant& est) const {
  return dni == est.dni; 
}

bool Estudiant::operator!=(const Estudiant& est) const {
  if (dni != est.dni) return true;
  else return false;
}

bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2) {
  if (e1.consultar_DNI() < e2.consultar_DNI()) return true;
  else return false;
}
