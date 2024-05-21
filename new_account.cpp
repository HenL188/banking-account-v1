#include "new_account.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

typedef struct account
{
  int id; // account number
  double balence;
  std::string username;
  std::string password;

} account;

std::string NewUsername()
{
  account a;
  printf("Username max of 20 characters\n");
  printf("Create Username:\n");
  std::string input;
  std::cin >> input;
  int size = input.length();
  while (size > 20)
  {
    if (size > 20)
    {
      printf("Username is greater then 20 characters\n");
      printf("Try once more \n");
      std::cin >> input;
      size = input.length();
    }
  }
  a.username = input;
  return a.username;
}

std::string NewPassword()
{
  account a;
  printf("Password min of 8 characters and max of 20\n");
  printf("Create Password:\n");
  std::string input;
  std::cin >> input;
  int size = input.length();
  while (size < 8 || size > 20)
  {
    if (size <= 8)
    {
      printf("Password is not 8 characters or greater\n");
      printf("Try once more\n");
      std::cin >> input;
      size = input.length();
    }
    if (size > 20)
    {
      printf("Password is greater then 20 characters\n");
      printf("Try once more \n");
      std::cin >> input;
      size = input.length();
    }
  }
  a.password = input;
  return a.password;
}

int NewID()
{
  account a;
  srand(time(0));

  int rnd = rand();
  a.id = rnd;
  return a.id;
}

void NewAccount()
{
  account a;
  a.username = NewUsername();
  a.password = NewPassword();
  a.id = NewID();
  a.balence = 0.00;
  std::string path = "database/userpass/" + a.username + ".txt";
  std::ofstream file(path);
  file << a.username << "\n"
       << a.password;
  file.close();
  std::string path2 = "database/accounts/" + a.password + ".txt";
  std::ofstream file2(path2);
  file2 << a.id << "\n"
        << a.balence << "\n";
  file2.close();
}
