#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Pour ssize_t ou si vous voulez utiliser des fonctions de bas niveau

/**
 * Imprime un tableau d'octets (unsigned char) sous forme hexadécimale.
 * @param data Le tableau d'octets à imprimer.
 * @param len La longueur du tableau en octets.
 * @param bytes_per_line Nombre d'octets à imprimer par ligne (pour la mise en forme).
 */
void print_hex_dump(const unsigned char *data, size_t len, int bytes_per_line) {
	if (data == NULL || len == 0) return;

	for (size_t i = 0; i < len; i++) {
		// %02x: Imprime le nombre en hexadécimal (x), en utilisant au moins 2 caractères (2)
		// et en ajoutant un zéro (0) si nécessaire (par exemple, 0F au lieu de F).
		// (unsigned int) est un transtypage (cast) de sécurité car %x attend généralement un int.
		printf("%02x", (unsigned int)data[i]);

		// Ajoute un espace pour séparer les octets
		printf(" ");

		// Ajoute un saut de ligne pour la mise en forme
		if ((i + 1) % bytes_per_line == 0) {
			printf("\n");
		}
	}
	// Assurez-vous qu'il y a un saut de ligne final si la boucle n'en a pas mis un.
	if (len % bytes_per_line != 0) {
		printf("\n");
	}
}
