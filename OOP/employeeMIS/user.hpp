#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;

class User {
    private:
    string username;
    string password;
  public:
  User(string username,string password):username(username),password(password){}
bool authenticate (string inputUsername,string inputPassword)
{
    return (username==inputUsername && password == inputPassword);
}};

#endif 
