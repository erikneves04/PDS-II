#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) 
{
  
    if (!checkPassword(password))
        return;

    if (m_passwords.count(url) != 0)
        return;

    m_passwords[url] = Usuario(login, password);
}

void GooglePassword::remove(const std::string& url) 
{
    if (m_passwords.count(url) == 0)
        return;

    m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) 
{
    if (!checkPassword(new_password))
        return;

    if (m_passwords.count(url) == 0)
        return;

    Usuario* user = &m_passwords[url];

    if (user->getPassword() != old_password)
        return;

    user->setLogin(login);
    user->setPassword(new_password);

}

void GooglePassword::printPasswords() {
  std::cout << m_passwords.size() << std::endl;
  for(auto pair : m_passwords)
  {
    std::string url = pair.first;
    Usuario user = pair.second;

    std::cout << url << ": " << user.getLogin() << " and " << user.getPassword() << std::endl; 
  }

}

bool GooglePassword::checkPassword(const std::string& password) const 
{
    if (password.find("123456") != std::string::npos) 
        return false;
    
    if (password.length() > 50) 
        return false;
    
    if (password.length() < 6) 
        return false;

    if (password.find(' ') != std::string::npos) 
        return false;

    return true;
}