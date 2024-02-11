// #include <SFML/Network.hpp>
// #include <SFML/System.hpp>
// #include <iostream>
// #include <cstdlib>
// #include <pthread.h>
// using namespace std;

// #define NUM_THREADS 2

// sf::IpAddress ip=sf::IpAddress::getLocalAddress();
// sf::TcpSocket socket;
// char connectiontype,mode;
// char buffer[2000];
// size_t received;
// string text="connected to ";

// struct thread_data {
//    int  thread_id;
//    char *message;
// };
// pthread_t threads[NUM_THREADS];
// struct thread_data td[NUM_THREADS];
// int rc;
// int i;



// void *Send(void *threadarg) {
//    struct thread_data *my_data;
//    my_data = (struct thread_data *) threadarg;
//    getline(cin,text);
//    socket.send(text.c_str(),text.length()+1);
// //    cout << "Thread ID : " << my_data->thread_id ;
// //    cout << " Message : " << my_data->message << endl;

//    pthread_exit(NULL);
// }
// void *Recieve(void *threadarg) {
//    struct thread_data *my_data;
//    my_data = (struct thread_data *) threadarg;
//    socket.receive(buffer,sizeof(buffer),received);
//                 cout<<"received: "<<buffer<<endl;
// //    cout << "Thread ID : " << my_data->thread_id ;
// //    cout << " Message : " << my_data->message << endl;

//    pthread_exit(NULL);
// }
// int main(){

    
    
//     cout<<"s for server, c for client"<<endl;
//     cin>>connectiontype;
//     if(connectiontype=='s'){
//         sf::TcpListener listener;
//         listener.listen(3000);
//         listener.accept(socket);
//         text+="server";
//         mode='s';
//     }
//     else if(connectiontype=='c'){
//         socket.connect(         ip,3000);
//         text+="client";
//         mode='r';
//     }
//     socket.send(text.c_str(),text.length()+1);
//     socket.receive(buffer,sizeof(buffer),received);
//     cout<<buffer<<endl;

//     bool done=false;

//     while(true){
//         cout <<"main() : creating thread, " << i << endl;
//       td[i].thread_id = i;
//       td[i].message = "This is message";
//       rc = pthread_create(&threads[0], NULL, Send, (void *)&td[0]);
//       i = pthread_create(&threads[1], NULL, Recieve, (void *)&td[1]);
//       if (rc || i) {
//          cout << "Error:unable to create thread," << rc << endl;
//          exit(-1);
//       }
//         //pthread_exit(NULL);
//     }
//     return 0;
// }

#include <iostream>
#include <SFML/Network.hpp>

const unsigned short PORT = 5000;
const std::string IPADDRESS("127.0.0.1");//change to suit your needs

std::string msgSend;

sf::TcpSocket socket;
sf::Mutex globalMutex;
bool quit = false;

void DoStuff(void)
{
	static std::string oldMsg;
	while(!quit)
	{
		sf::Packet packetSend;
		globalMutex.lock();
		packetSend << msgSend;
		globalMutex.unlock();
		
		socket.send(packetSend);
		
		std::string msg;
		sf::Packet packetReceive;
		
		socket.receive(packetReceive);		
		if ((packetReceive >> msg) && oldMsg != msg && !msg.empty())
		{
			std::cout << msg << std::endl;
			oldMsg = msg;
		}
	}
}

void Server(void)
{
	sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
}

bool Client(void)
{
	if(socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
	{
		std::cout << "Connected\n";
		return true;
	}
	return false;
}

void GetInput(void)
{
	std::string s;
	std::cout << "\nEnter \"exit\" to quit or message to send: ";
	getline(std::cin,s);
	if(s == "exit")
		quit = true;
	globalMutex.lock();
	msgSend = s;
	globalMutex.unlock();
}


int main(int argc, char* argv[])
{
	sf::Thread* thread = 0;
		
	char who;
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin  >> who;

	if (who == 's')
		Server();
	else
		Client();

	thread = new sf::Thread(&DoStuff);
	thread->launch();
		
	while(!quit)
	{
		GetInput();
	}

	if(thread)
	{
		thread->wait();
		delete thread;
	}
	return 0;
}