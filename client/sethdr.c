#include "client.h"

unsigned short cksum(unsigned short* addr, int len){
	int sum = 0;
	u_short answer = 0;
	u_short *w = addr;

	int nleft = len;

	while(nleft > 1){
		sum += *w++;
		nleft -= 2;
	}

	if(nleft == 1){
		*(u_char *)(&answer)= *(u_char *)w;
		sum += answer;
	}

	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;

	return answer;
}


void sethdr(struct iphdr *ip, struct tcphdr *tcp){
	srand(getpid());

	memset(ip, 0, sizeof(struct iphdr));
	memset(tcp, 0, sizeof(struct tcphdr));

	tcp->source = htons(9190);
	tcp->dest = htons(9190);
	tcp->seq = htonl(rand()%time(NULL));
	tcp->ack_seq = htonl(rand()%time(NULL));
	tcp->doff = 5;
	tcp->syn = 1;
	tcp->window = htons(512);
	tcp->check = (unsigned short)cksum((unsigned short*)tcp, sizeof(struct tcphdr));;

	ip->version = 4;
	ip->ihl = 5;
	ip->protocol = IPPROTO_TCP;
	ip->tot_len = 40;
	ip->id = htons(getpid());
	ip->ttl = 60;
	ip->check = (unsigned short)cksum((unsigned short*)ip, sizeof(struct iphdr));
	ip->saddr = inet_addr("127.0.0.1");
	ip->daddr = inet_addr("127.0.0.1");
}
