#include "login.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

std::string username()
{
  int attempts = 4;
  std::string input;
  std::cout << "Enter username: " << std::endl;
  std::cin >> input;
  std::string filePath = "database/userpass/" + input + ".txt";
  while (attempts != 0)
  {
    if (!std::filesystem::exists(filePath))
    {

      std::cout << "wrong username"
                << "\n";
      std::cout << attempts << " "
                << "attempts remain" << '\n';
      std::cout << "Enter username: " << std::endl;
      std::cin >> input;
      std::string filePath = "database/userpass/" + input + ".txt";
      attempts--;
      if (std::filesystem::exists(filePath))
      {
        return filePath;
      }
    }
    else
    {
      break;
    }
    if (attempts == 0)
    {
      std::cout << "Locked out" << '\n';
      exit(0);
    }
  }
  return filePath;
}

std::string login()
{
  std::string filePath = username();
  std::ifstream file(filePath);
  std::string username;
  std::vector<std::string> user;
  while (std::getline(file, username))
  {
    user.push_back(username);
  };
  file.close();

  user.erase(user.begin());
  std::vector<std::string> password;
  std::string input;
  std::cout << "Enter password: " << '\n';
  std::cin >> input;
  password.push_back(input);
  int attempts = 4;
  while (attempts != 0)
  {
    if (user != password)
    {
      std::cout << "wrong password" << '\n';
      std::vector<std::string> password;
      std::string input;
      std::cout << attempts << " "
                << "attempts remain" << '\n';

      std::cout << "Enter password: " << '\n';
      std::cin >> input;
      password.push_back(input);
      attempts--;
      if (user == password)
      {
        return input;
      }
    }
    else
    {
      return input;
    }
    if (attempts == 0)
    {
      std::cout << "Locked out" << '\n';
      exit(0);
    }
  }
  return "none";
}
