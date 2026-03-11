#include "ft_ssl_md5.h"

void md5_init(t_md5_context *ctx) {
	ctx->A = 0x67452301;
	ctx->B = 0xefcdab89;
	ctx->C = 0x98badcfe;
	ctx->D = 0x10325476;
}

void md5_compute(const unsigned char *msg, size_t len_bytes, unsigned char result[16]) {
	t_md5_context ctx;
	size_t padded_len_bytes;

	md5_init(&ctx);

	unsigned char *padded_msg = md5_pad(msg, len_bytes, &padded_len_bytes);
	if (!padded_msg) {
		return;
	}

	size_t chunks_amount = padded_len_bytes / CHUNK_SIZE;
	for (size_t i = 0; i < chunks_amount; i++) {
		md5_transform(&ctx, padded_msg + (i * CHUNK_SIZE));
	}

	md5_finalize(&ctx, result);

	free(padded_msg);
}

void md5_print(const char *input, const unsigned char digest[16]) {
	printf("MD5(\"%s\") = ", input);
	for (int i = 0; i < 16; i++) {
		printf("%02x", digest[i]);
	}
	printf("\n");
}
