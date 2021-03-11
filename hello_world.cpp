#include <iostream>
#include <string>

int
main(int argc, char** argv)
{
  std::string str;
  std::cout << "Your name:";
  getline(cin, str);
  std::cout << "Hello world " << str
            << endl; // program will say "hello,world,(your name)"

  return 1;
}

