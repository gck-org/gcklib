/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <stdio.h>

#include "xmem.h"

#include "net.h"

IPv4 ipv4_from(char *s)
{
	IPv4 ip = { 0 };
	unsigned int b[4];
	if (sscanf(s, "%u.%u.%u.%u", &b[0], &b[1], &b[2], &b[3]) != 4)
		return ip;
	for (int i = 0; i < 4; i++) {
		if (b[i] > 255)
			return ip;
		ip.octets[i] = (uint8_t)b[i];
	}
	return ip;
}

char *ipv4_to(IPv4 ip)
{
	char *buf = xmalloc(16);
	snprintf(buf, 16, "%u.%u.%u.%u", ip.octets[0], ip.octets[1],
		 ip.octets[2], ip.octets[3]);
	return buf;
}

int ping(char *s)
{
}

char *pull(char *s)
{
}
