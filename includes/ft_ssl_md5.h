#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <stdint.h>

# include "ft_ssl.h"
# include "ft_ssl_md5_errors.h"

# define CHUNK_SIZE 64 // 64 bytes = 512 bits

typedef struct s_md5_context {
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
} t_md5_context;

unsigned char *md5_pad(const unsigned char *msg, size_t len_bytes, size_t *padded_len_bytes);

#endif
