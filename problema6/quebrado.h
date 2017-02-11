#ifndef _quebrado_h
#define _quebrado_h

struct quebrado{
	int numerador;
	int denominador;
};

// Recibe como argumento dos quebrados, realiza la suma de los mismos y devuelve el resultado.
struct quebrado suma (struct quebrado q, struct quebrado p);

//Recibe como argumento dos quebrados, realiza la resta de los mismos y devuelve el resultado.
struct quebrado resta (struct quebrado q, struct quebrado p);

// Recibe como argumento dos quebrados, realiza la multiplicación de los mismos y devuelve el resultado.
struct quebrado multiplicacion (struct quebrado q, struct quebrado p);

// Recibe como argumento dos quebrados, realiza la división de los mismos y devuelve el resultado.
struct quebrado division (struct quebrado q, struct quebrado p);

//Recibe como argumento un quebrado y lo reduce a su fracción canónica (ejem 15/6   pasaría a 5/2.)
void reducir (struct quebrado * q);

// imprime por pantalla un quebrado
void imprimir (struct quebrado q);

// calcula el máximo común divisor
int mcd ( int a, int b );


#endif