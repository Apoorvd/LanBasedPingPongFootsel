#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;
int main(){
    sf::IpAddress ip=sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectiontype,mode;
    char buffer[2000];
    size_t received;
    cout<<"Connection to server"<<endl;
    string text="connected to client";
    sf::TcpListener listener;
    listener.listen(3000);
    listener.accept(socket);
    socket.send(text.c_str(),text.length()+1);
    socket.receive(buffer,sizeof(buffer),received);
    cout<<buffer<<endl;
    bool done=false;
  struct termios old_tio, new_tio;
    unsigned char c;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    do {
         
         c=getchar();
         socket.send(c,2);
         cout << c;
         socket.receive(buffer,sizeof(buffer),received);
            if(received>0){
                cout<<"received: "<<buffer<<endl;
    } while(!done);  

        }
