#if 0
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netatalk/at.h>
#include <linux/atalk.h>
#include "random.h"
#include "net.h"

void atalk_gen_sockaddr(struct sockaddr **addr, socklen_t *addrlen)
{
	struct sockaddr_at *atalk;

	atalk = malloc(sizeof(struct sockaddr_at));
	if (atalk == NULL)
		return;

	atalk->sat_family = PF_APPLETALK;
	atalk->sat_port = rand();
	atalk->sat_addr.s_net = rand();
	atalk->sat_addr.s_node = rand();
	*addr = (struct sockaddr *) atalk;
	*addrlen = sizeof(struct sockaddr_at);
}

void atalk_rand_socket(struct socket_triplet *st)
{
	if (rand_bool()) {
		st->type = SOCK_DGRAM;
	        st->protocol = 0;
	        return;
	}

	st->protocol = rand() % PROTO_MAX;
	st->type = SOCK_RAW;
}

void atalk_setsockopt(struct sockopt *so)
{
	so->level = SOL_ATALK;
}
#endif
