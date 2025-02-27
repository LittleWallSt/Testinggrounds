#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>

struct Persona {
	char sexo;
	int edad;
};

void ejercicio1() {
	int n;
	std::cout << "LEER NUMERO \n";
	std::cin >> n;

	//Si el numero es par simplemente hacemos un descenso hasta 0 escribiendo en la consola
	if (n % 2 == 0) {
		for (int i = n; i >= 0; i -= 2)
			std::cout << i << " ";
	}
	//Lo mismo si es impar solo que hasta 1
	else
		for (int i = n; i >= 1; i -= 2)
			std::cout << i << " ";
}

void ejercicio2()
{
	std::vector<Persona> personas(50);

	int mayor = 0, menor = 0, hMayor = 0, mMenor = 0, nM = 0;

	std::cout << "LEER PERSONAS: \n";

	for (int i = 0; i < 50; i++) {
		do {
			std::cout << "Ingresa sexo (M/F) de persona " << (i + 1) << ": ";
			std::cin >> personas[i].sexo;
			personas[i].sexo = std::toupper(personas[i].sexo);

		} while (personas[i].sexo != 'M' && personas[i].sexo != 'F');

		do {
			std::cout << "Ingresa edad para persona " << (i + 1) << ": ";
			std::cin >> personas[i].edad;
		} while (personas[i].edad < 0 || personas[i].edad > 130);

		if (personas[i].edad >= 18) {
			mayor++;
			if (personas[i].sexo == 'M')
				hMayor++;
		}
		else {
			menor++;
			if (personas[i].sexo == 'F')
				mMenor++;
		}

		if (personas[i].sexo == 'F') {
			nM++;
		}
	}

	float porcentajeMayores = (mayor / 50.0) * 100;
	float porcentajeMujeres = (nM / 50.0) * 100;

	// Mostrar resultados
	std::cout << "\n--- RESULTADOS --- \n";
	std::cout << "a. Cantidad de personas mayores de edad: " << mayor << "\n";
	std::cout << "b. Cantidad de personas menores de edad: " << menor << "\n";
	std::cout << "c. Cantidad de personas masculinas mayores de edad: " << hMayor << "\n";
	std::cout << "d. Cantidad de personas femeninas menores de edad: " << mMenor << "\n";
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "e. Porcentaje de personas mayores de edad: " << porcentajeMayores << "%\n";
	std::cout << "f. Porcentaje de mujeres respecto al total: " << porcentajeMujeres << "%\n";
}

void ejercicio3()
{
	int hTrabajadas;
	double tarifa;

	// Leer datos de entrada
	std::cout << "LEER HORASTRABAJADAS: \n";
	std::cin >> hTrabajadas;

	std::cout << "LEER TARIFA: \n";
	std::cin >> tarifa;

	double sueldo;

	// Calcular el sueldo
	if (hTrabajadas <= 40) {
		// Si las horas trabajadas son 40 o menos, no hay horas extras
		sueldo = hTrabajadas * tarifa;
	}
	else {
		// Si las horas trabajadas son más de 40, se calculan las horas extras
		int horasExtras = hTrabajadas - 40;
		double tarifaExtra = tarifa * 1.5;
		sueldo = (40 * tarifa) + (horasExtras * tarifaExtra);
	}

	// Mostrar el sueldo calculado con 2 decimales
	std::cout << std::fixed << std::setprecision(2);  // Para mostrar dos decimales
	std::cout << "El sueldo recibido por el trabajador es: $" << sueldo << "\n";
}

int main()
{

	ejercicio1();
	ejercicio2();
	ejercicio3();
}


