#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
int main(){
    sf::IpAddress ip=sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectiontype,mode;
    char buffer[2000];
    size_t received;
    cout<<"Connection to server"<<endl;
    string text="connected to server";
    socket.connect(ip,3000);
    socket.send(text.c_str(),text.length()+1);
    socket.receive(buffer,sizeof(buffer),received);
    cout<<buffer<<endl;
    bool done=false;

    while(!done){
            getline(cin,text);
            socket.send(text.c_str(),text.length()+1);
            mode='r';
        
        
            socket.receive(buffer,sizeof(buffer),received);
            if(received>0){
                cout<<"received: "<<buffer<<endl;
            }
        }
    }