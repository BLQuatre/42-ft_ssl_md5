#include "ft_ssl.h"
#include "ft_ssl_md5.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		ft_write(STDOUT_FILENO, "usage: ");
		ft_write(STDOUT_FILENO, basename(argv[0]));
		ft_write(STDOUT_FILENO, " command [flags] [file/string]\n");
		return EXIT_SUCCESS;
	}

	if (ft_strncmp(argv[1], "md5", 4) && ft_strncmp(argv[1], "sha256", 7)) {
		ft_write(STDOUT_FILENO, basename(argv[0]));
		ft_write(STDOUT_FILENO, ": Error: '");
		ft_write(STDOUT_FILENO, argv[1]);
		ft_write(STDOUT_FILENO, "' is an invalid command.\n\nCommands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s\n");
		return EXIT_FAILURE;
	}

	size_t padded_len_bytes;
	const char *original_msg = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."; // Message de test
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
	print_hex_dump(padded_msg, padded_len_bytes, 16);

	if (padded_len_bytes % CHUNK_SIZE != 0) {
		free(padded_msg);
		ft_write(STDERR_FILENO, ERR_SPLIT_CHUNKS);
		return EXIT_FAILURE;
	}

	printf("Chunks:\n");
	size_t chunks_amount = padded_len_bytes / CHUNK_SIZE;

	unsigned char chunk[CHUNK_SIZE];
	for (size_t i = 0; i < chunks_amount; i++) {
		for (size_t j = 0; j < CHUNK_SIZE; j++) {
			chunk[j] = (padded_msg + (i * CHUNK_SIZE))[j];
		}

		printf("chunk %zu: ", i);
		print_hex_dump(chunk, CHUNK_SIZE, CHUNK_SIZE);
	}

	free(padded_msg);

	return EXIT_SUCCESS;
}
