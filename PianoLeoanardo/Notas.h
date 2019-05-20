//*************************************************
//**  DEFINE MUSIC NOTES
//*************************************************
#define DO4 	'q'
#define RE4		'w'
#define MI4		'e'
#define FA4		'r'
#define SOL4	't'
#define LA4		'y'
#define SI4		'u'
#define REb4	'2'
#define MIb4	'3'
#define SOLb4	'5'
#define LAb4	'6'
#define SIb4	'7'

#define DO3		'z'
#define RE3		'x'
#define MI3		'c'
#define FA3		'v'
#define SOL3	'b'
#define LA3		'n'
#define SI3		'm'
#define REb3	's'
#define MIb3	'd'
#define SOLb3	'g'
#define LAb3	'h'
#define SIb3	'j'

#define Clean	'k'
#define Exit	(char)177
//*************************************************
//**  DEFINE STRCUTURE NOTES
//*************************************************
typedef struct {
  String nom;       //nombre
  OneButton btn;    // Boton
  char ch;     // Dato a enviar
} key;

key keys[] = {//nombre,boton,dato
  {"DO4", OneButton(A1, true), DO4},
  {"RE4", OneButton(A2, true), RE4},
  {"Exit", OneButton(A3, true),Exit}
};
