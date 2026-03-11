#include "ft_ssl.h"
#include "ft_ssl_md5.h"
#include "get_next_line.h"

char *read_stdin(void)
{
	char *line;
	char *result;
	char *tmp;

	result = ft_strdup("");
	while ((line = get_next_line(STDIN_FILENO)) != NULL) {
		tmp = ft_strjoin(result, line);
		free(result);
		free(line);
		result = tmp;
	}
	return result;
}

int main(int argc, char **argv)
{
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

	char *input = read_stdin();
	unsigned char result[16];

	md5_compute((const unsigned char*)input, ft_strlen(input), result);
	md5_print(input, result);

	// const char *test1 = "";
	// md5_compute((const unsigned char*)test1, ft_strlen(test1), result);
	// md5_print(test1, result);

	// const char *test2 = "a";
	// md5_compute((const unsigned char*)test2, ft_strlen(test2), result);
	// md5_print(test2, result);

	// const char *test3 = "abc";
	// md5_compute((const unsigned char*)test3, ft_strlen(test3), result);
	// md5_print(test3, result);

	// const char *test4 = "message digest";
	// md5_compute((const unsigned char*)test4, ft_strlen(test4), result);
	// md5_print(test4, result);

	return EXIT_SUCCESS;
}
