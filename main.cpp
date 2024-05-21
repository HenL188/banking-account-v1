#include "login.h"
#include "new_account.h"
#include <iostream>
#include <string>
#include <fstream>
int main()
{
  std::cout << "Are you an existing member?"
            << "\n"
            << "Y/N" << '\n';
  std::string answer;
  std::cin >> answer;
  if (answer == "Y" || answer == "y")
  {
    std::string password = login();
    std::ifstream file("database/accounts/" + password + ".txt");
    std::string account;
    while (std::getline(file, account))
    {
      std::cout << account << "\n";
    }
  }
  if (answer == "N" || answer == "n")
  {
    NewAccount();
  }
}
