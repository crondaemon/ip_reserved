
#include <ip_reserved.h>

#include <assert.h>
#include <stdio.h>
#include <arpa/inet.h>

#define TEST_YES(ip) { assert(is_reserved(inet_addr((ip)))); printf("."); fflush(stdout); }
#define TEST_NO(ip) { assert(!is_reserved(inet_addr((ip)))); printf("."); fflush(stdout); }

int main()
{
	printf("Running tests");
	TEST_YES("0.1.2.3");
	TEST_NO("1.2.3.4");
	TEST_YES("10.1.2.3");
	TEST_YES("127.1.2.3");
	TEST_YES("169.254.1.2");
	TEST_YES("172.16.1.2");
	TEST_YES("172.31.1.2");
	TEST_YES("192.0.0.1");
	TEST_YES("192.0.2.4");
	TEST_YES("192.88.99.6");
	TEST_YES("192.168.100.200");
	TEST_YES("198.18.1.2");
	TEST_YES("198.19.255.255");
	TEST_YES("198.51.100.100");
	TEST_YES("203.0.113.100");
	TEST_YES("240.0.0.0");
	TEST_YES("255.255.255.254");
	TEST_YES("255.255.255.255");
	printf("\nTests complete\n");
	return 0;
}
