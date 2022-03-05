#include "thread_pool.h"
#include <stdio.h>
#include <stdbool.h>
#include "request.h"
#include "io_helper.h"

int main() {
	buffer buffer = {0};
	buffer_init(&buffer, 3);
	buffer_push(&buffer, 1);
	buffer_push(&buffer, 2);
	buffer_push(&buffer, 3);
	printf("%d", buffer_pop(&buffer));
	printf("%d", buffer_pop(&buffer));
	buffer_push(&buffer, 4);
	buffer_push(&buffer, 5);
	printf("%d", buffer_pop(&buffer));
	printf("%d", buffer_pop(&buffer));
	printf("%d", buffer_pop(&buffer));
	buffer_push(&buffer, 6);
	buffer_push(&buffer, 7);
	buffer_push(&buffer, 8);
	printf("%d", buffer_pop(&buffer));
	printf("%d", buffer_pop(&buffer));
	printf("%d", buffer_pop(&buffer));
	buffer_free(&buffer);
}

//// ./wserver [-d basedir] [-p port] [-t threads] [-b buffers] [-s schedalg]
//int main(int argc, char *argv[]) {
//    int c = 0;
//    char *root_dir = ".";
//    long port = 10000;
//	long threads = 1;
//	size_t buffer_size = 1;
//
//    while ((c = getopt(argc, argv, "d:p:")) != -1) {
//		switch (c) {
//		case 'd': {
//			root_dir = optarg;
//			break;
//		}
//		case 'p': {
//			char *end = NULL;
//			port = strtol(optarg, &end, 10);
//			break;
//		}
//		case 't': {
//			char *end = NULL;
//			threads = strtol(optarg, &end, 10);
//			break;
//		}
//		case 'b':{
//			char *end = NULL;
//			buffer_size = (size_t)strtol(optarg, &end, 10);
//			break;
//		}
//		case 's': {
//			if (strcmp(optarg, "FIFO") != 0) {
//				fprintf(stderr, "only FIFO is supported");
//				exit(1);
//			}
//			break;
//		}
//		default: {
//			fprintf(stderr, "usage: wserver [-d basedir] [-p port] [-t threads] [-b buffers] [-s schedalg]\n");
//			exit(1);
//		}
//		}
//	}
//
//    // run out of this directory
//    chdir_or_die(root_dir);
//
//    // now, get to work
//    int listen_fd = open_listen_fd_or_die(port);
//    while (true) {
//		struct sockaddr_in client_addr = {0};
//		int client_len = sizeof(client_addr);
//		int conn_fd = accept_or_die(listen_fd, (sockaddr_t*) &client_addr, (socklen_t*) &client_len);
//		request_handle(conn_fd);
//		close_or_die(conn_fd);
//    }
//}


    


 
