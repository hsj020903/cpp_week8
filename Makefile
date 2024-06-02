CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

# Include directories


# Object files
OBJECTS_FIRST = first.o echo_service.o echo_service_installer.o host.o link_installer.o manual_router.o message_service_installer.o message_service.o link.o node.o router.o service_installer.o service.o
OBJECTS_SECOND = second.o echo_service.o echo_service_installer.o host.o link_installer.o manual_router.o message_service_installer.o message_service.o link.o node.o router.o service_installer.o service.o

all: first second

first.o: scenarios/first.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp

second.o: scenarios/second.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

echo_service.o: echo_service.cpp
	$(CC) $(CFLAGS) -c echo_service.cpp

echo_service_installer.o: echo_service_installer.cpp
	$(CC) $(CFLAGS)  -c echo_service_installer.cpp

host.o: host.cpp
	$(CC) $(CFLAGS) -c host.cpp -o host.o

link_installer.o: link_installer.cpp
	$(CC) $(CFLAGS) -c link_installer.cpp

link.o: link.cpp
	$(CC) $(CFLAGS) -c link.cpp

manual_router.o: manual_router.cpp
	$(CC) $(CFLAGS) -c manual_router.cpp

message_service_installer.o: message_service_installer.cpp
	$(CC) $(CFLAGS) -c message_service_installer.cpp

message_service.o: message_service.cpp
	$(CC) $(CFLAGS) -c message_service.cpp

node.o: node.cpp
	$(CC) $(CFLAGS) -c node.cpp

router.o: router.cpp
	$(CC) $(CFLAGS) -c router.cpp

service_installer.o: service_installer.cpp
	$(CC) $(CFLAGS) -c service_installer.cpp

service.o: service.cpp
	$(CC) $(CFLAGS) -c service.cpp

first: $(OBJECTS_FIRST)
	$(CC) $(CFLAGS) -o first $(OBJECTS_FIRST)

second: $(OBJECTS_SECOND)
	$(CC) $(CFLAGS) -o second $(OBJECTS_SECOND)


clean:
	rm -f *.o first second