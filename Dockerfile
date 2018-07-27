FROM alpine:latest
RUN apk add --update gcc libc-dev
ADD hello_server.c /hello_server.c
RUN gcc -static -o /hello-server hello_server.c

FROM scratch
COPY --from=0 /hello-server /hello-server
CMD ["/hello-server"]
