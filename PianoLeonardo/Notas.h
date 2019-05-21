//*************************************************
//**  DEFINIR CHAR NOTAS
//*************************************************
const char firstOctave[]  = {'q', 'w', 'e', 'r', 't', 'y', 'u', '2', '3', '5', '6', '7'};
const char secondOctave[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', 's', 'd', 'g', 'h', 'j'};

#define Clean	'k'
#define Exit	(char)177

//*************************************************
//**  DEFINIR ESTRUCTURAS DE NOTAS
//*************************************************
typedef struct {
  String nom;       //nombre
  OneButton btn;    // Boton
  volatile char ch;     // Dato a enviar
} key;

//*************************************************
//**  ARRAY DE NOTAS
//*************************************************

key keys[] = {//nombre,boton,dato
  {"DO", OneButton(4, true),},
  {"RE", OneButton(5, true),},
  {"MI", OneButton(6, true),},
  {"FA", OneButton(7, true),},
  {"SOL", OneButton(8, true),},
  {"LA", OneButton(9, true),},
  {"SI", OneButton(16, true),},
  {"REb", OneButton(14, true),},
  {"MIb", OneButton(15, true),},
  {"SOLb", OneButton(18, true),},
  {"LAb", OneButton(19, true),},
  {"SIb", OneButton(20, true),},
  {"btn", OneButton(21, true),}
};
