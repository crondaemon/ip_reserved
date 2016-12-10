/* 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <arpa/inet.h>
#include <stdbool.h>


#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define NETMASK(ip, nm) (((iph) >> (32-nm)) << (32-nm)) 

/*
 * \brief Check if a IP address is reserved
 * \param ip the IP to check in network byte order
 * \return true if the IP is reserved
 */
int is_reserved(uint32_t ip)
{
	uint32_t iph = ntohl(ip);

	if (0x0 == NETMASK(iph, 8))
		return TRUE;

	if (0x0A000000 == NETMASK(iph, 8))
		return TRUE;

	if (0x7F000000 == NETMASK(iph, 8))
		return TRUE;

	if (0xA9FE0000 == NETMASK(iph, 16))
		return TRUE;

	if (0xAC100000 == NETMASK(iph, 12))
		return TRUE;

	if (0xC0000000 == NETMASK(iph, 24))
		return TRUE;

	if (0xC0000200 == NETMASK(iph, 24))
		return TRUE;

	if (0xC0586300 == NETMASK(iph, 24))
		return TRUE;

	if (0xC0A80000 == NETMASK(iph, 16))
		return TRUE;

	if (0xC6120000 == NETMASK(iph, 15))
		return TRUE;

	if (0xC6336400 == NETMASK(iph, 24))
		return TRUE;

	if (0xCB007100 == NETMASK(iph, 24))
		return TRUE;

	if (0xF0000000 == NETMASK(iph, 4))
		return TRUE;

	if (0xFFFFFFFF == iph)
		return TRUE;

	return FALSE;
}
