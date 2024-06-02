CC = g++ -std=c++11 -g
exe_file = prog

$(exe_file): main.o auth_service.o bot_service.o contact.o acc_info.o
	$(CC) main.o auth_service.o bot_service.o contact.o acc_info.o -o $(exe_file)

main.o: main.cpp 
	$(CC) -c main.cpp

auth_service.o: auth_service.cpp auth_service.h
	$(CC) -c auth_service.cpp

bot_service.o: bot_service.cpp bot_service.h
	$(CC) -c bot_service.cpp

contact.o: contact.cpp contact.h
	$(CC) -c contact.cpp

acc_info.o: acc_info.cpp acc_info.h
	$(CC) -c acc_info.cpp

clean:
	rm -f *.out *.o $(exe_file)