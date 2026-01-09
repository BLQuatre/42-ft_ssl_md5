#include "ft_ssl.h"
#include "ft_ssl_md5.h"

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	// if (argc < 2) {
	// 	write(0, "usage: ft_ssl command [flags] [file/string]\n", 45);
	// 	return 0;
	// }

	size_t padded_len_bytes;
	const char *original_msg = "Coucou les amis, coucou les amis, coucou les amis, coucou"; // Message de test
	size_t original_len = ft_strlen(original_msg);

	unsigned char *padded_msg = md5_pad((const unsigned char*)original_msg, original_len, &padded_len_bytes);
	if (!padded_msg) {
		ft_write(STDERR_FILENO, ERR_PADDING);
		return EXIT_FAILURE;
	}

	printf("Message: %s\n", original_msg);
	printf("Message original: %lu octets, %lu bits\n", original_len, original_len * 8);
	printf("Message rempli: %lu octets, %lu bits\n", padded_len_bytes, padded_len_bytes * 8);
	printf("--- Message Rempli (Hex) ---\n");
	print_hex_dump(padded_msg, padded_len_bytes, CHUNK_SIZE);

	unsigned char **chunks = ft_split_chunks(padded_msg, padded_len_bytes, CHUNK_SIZE);
	if (!chunks) {
		free(padded_msg);
		ft_write(STDERR_FILENO, ERR_SPLIT_CHUNKS);
		return EXIT_FAILURE;
	}

	printf("Chunks:\n");
	int i = 0;

	while (chunks[i]) {
		printf("chunks[%d] = ", i);
		print_hex_dump(chunks[i], CHUNK_SIZE, CHUNK_SIZE);
		i++;
	}

	free(padded_msg);
	free(chunks);

	return EXIT_SUCCESS;
}
