#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <iostream>
int main(int argc, char const *argv[]) {
  if (Keyboard::isKeyPressed(Keyboard::Up))
  {
      std::cout << "up is pressed" << '\n';
  }
  return 0;
}
