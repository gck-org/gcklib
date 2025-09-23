/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef NET_H
#define NET_H

#include <stdint.h>

typedef union {
	uint32_t addr;
	uint8_t octets[4];
} IPv4;

IPv4 ipv4_from(char *s);
char *ipv4_to(IPv4 ip);

int ping(char *s);
char *pull(char *s);

#endif
