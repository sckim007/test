all: hello hello-server hello-client unit-test

hello: hello.c
	gcc hello.c -o hello

hello-server: hello_server.c
	gcc hello_server.c -o hello-server

hello-client: hello_client.c
	gcc hello_client.c -o hello-client

unit-test:
	gcc unit_test.c -o unit-test
