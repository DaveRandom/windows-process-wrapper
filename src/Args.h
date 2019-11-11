#pragma once

#define SET_IN_ADDR(addr, b1, b2, b3, b4) do {   \
	(addr).addr4.S_un.S_un_b.s_b1 = (UCHAR)(b1); \
	(addr).addr4.S_un.S_un_b.s_b2 = (UCHAR)(b2); \
	(addr).addr4.S_un.S_un_b.s_b3 = (UCHAR)(b3); \
	(addr).addr4.S_un.S_un_b.s_b4 = (UCHAR)(b4); \
} while (0)

#define SET_AF_INET(addr) do {           \
	(addr).length = sizeof(SOCKADDR_IN); \
	(addr).family = AF_INET;             \
} while (0)

#define SET_AF_INET6(addr) do {           \
	(addr).length = sizeof(SOCKADDR_IN6); \
	(addr).family = AF_INET6;             \
} while (0)

typedef struct _server_address {
	int length;
	union {
		struct {
			ADDRESS_FAMILY family;
			USHORT port;
			union {
				IN_ADDR addr4;
				struct {
					ULONG flowinfo;
					IN6_ADDR addr6;
				};
			};
		};
		SOCKADDR_IN sockaddr4;
		SOCKADDR_IN6 sockaddr6;
		SOCKADDR sockaddr;
	};
} server_address_t;

typedef struct _program_arguments {
	server_address_t server_address;
    int token_size;
    LPCWSTR exe_cwd;
} program_arguments_t;

BOOL parse_opts(program_arguments_t* program_arguments, const int argc, LPCWSTR* argv);
