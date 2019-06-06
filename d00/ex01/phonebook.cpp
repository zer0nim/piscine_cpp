#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

std::ostream & operator << (std::ostream &out, const Contact &c) {
    out << "first name: " << c.getFirstName() << std::endl;
    out << "last name: " << c.getLastName() << std::endl;
    out << "nickname: " << c.getNickname() << std::endl;
    out << "login: " << c.getLogin() << std::endl;
    out << "postal address: " << c.getPostalAddress() << std::endl;
    out << "email address: " << c.getEmailAddress() << std::endl;
    out << "phone number: " << c.getPhoneNumber() << std::endl;
    out << "birthday date: " << c.getBirthdayDate() << std::endl;
    out << "favorite meal: " << c.getFavoriteMeal() << std::endl;
    out << "underwear color: " << c.getUnderwearColor() << std::endl;
    out << "darkest secret: " << c.getDarkestSecret() << std::endl;
    return (out);
}

std::string formatStr(std::string str) {
    if (str.length() > 10)
    {
        std::string tmp = std::string(str);
        tmp.resize(10);
        tmp.replace(9, 1, ".");
        return (tmp);
    }
    return (str);
}

bool isNumber(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

void    search(Contact contacts[]) {
    if (Contact::getNbInst() > 0) {
        // print basic list of curents contact
        std::cout << std::setw(10) << std::right << "index" << '|' \
                    << std::setw(10) << std::right << "first name" << '|' \
                    << std::setw(10) << std::right << "last name" << '|' \
                    << std::setw(10) << std::right << "nickname" << std::endl;
        for (int i = 0; i < Contact::getNbInst(); i++) {
            std::cout << std::setw(10) << std::right << contacts[i].getId() << '|' \
                << std::setw(10) << std::right << formatStr(contacts[i].getFirstName()) << '|' \
                << std::setw(10) << std::right << formatStr(contacts[i].getLastName()) << '|' \
                << std::setw(10) << std::right << formatStr(contacts[i].getNickname()) << std::endl;
        }

        // ask for index
        std::string indexStr;
        int         index = -1;
        while (index == -1) {
            std::cout << std::endl << "Please type index for more infos: ";
            std::getline(std::cin, indexStr);

            if (!indexStr.empty() && isNumber(indexStr)) {
                try {
                    index = std::stoi(indexStr);
                }
                catch (const std::invalid_argument& ia) {
                    std::cout << "Please type a valid index !" << std::endl;
                }
                catch (const std::out_of_range& oor) {
                    std::cout << "Please type a valid index !" << std::endl;
                }

                if (!(index >= 0 && index < Contact::getNbInst()))
                {
                    std::cout << "Please type a index from 0 to " << Contact::getNbInst() - 1 << std::endl;
                    index = -1;
                }
            }
            else
                std::cout << "Please type a valid index !" << std::endl;
        }
        std::cout << contacts[index];
    } else
        std::cout << "The contact list is empty !" << std::endl;
}

void    addContact(Contact contacts[]) {
    int i = Contact::getNbInst();
    if (i >= 8) {
        std::cout << "Contact limit reached !" << std::endl;
        return;
    }
    contacts[i].initId();
    std::string tmp;
    std::cout << "Let's create a new contact!" << std::endl;
    std::cout << "first name: ";
    std::getline(std::cin, tmp);
    contacts[i].setFirstName(tmp);
    std::cout << "last name: ";
    std::getline(std::cin, tmp);
    contacts[i].setLastName(tmp);
    std::cout << "nickname: ";
    std::getline(std::cin, tmp);
    contacts[i].setNickname(tmp);
    std::cout << "login: ";
    std::getline(std::cin, tmp);
    contacts[i].setLogin(tmp);
    std::cout << "postal address: ";
    std::getline(std::cin, tmp);
    contacts[i].setPostalAddress(tmp);
    std::cout << "email address: ";
    std::getline(std::cin, tmp);
    contacts[i].setEmailAddress(tmp);
    std::cout << "phone number: ";
    std::getline(std::cin, tmp);
    contacts[i].setPhoneNumber(tmp);
    std::cout << "birthday date: ";
    std::getline(std::cin, tmp);
    contacts[i].setBirthdayDate(tmp);
    std::cout << "favorite meal: ";
    std::getline(std::cin, tmp);
    contacts[i].setFavoriteMeal(tmp);
    std::cout << "underwear color: ";
    std::getline(std::cin, tmp);
    contacts[i].setUnderwearColor(tmp);
    std::cout << "darkest secret: ";
    std::getline(std::cin, tmp);
    contacts[i].setDarkestSecret(tmp);
}

int main(void) {
    std::string input;
    Contact contacts[8];


    while (true)
    {
        std::cout << "Wait for command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);

        if (input.compare("ADD") == 0)
        {
            addContact(contacts);
        } else if (input.compare("SEARCH") == 0)
        {
            search(contacts);
        } else if (input.compare("EXIT") == 0)
        {
            return 0;
        } else {
            std::cout << "Command not recognized !" << std::endl \
                << "Use:" << std::endl \
                << "    ADD to create a new contact" << std::endl \
                << "    SEARCH to search in the existing contacts" << std::endl \
                << "    EXIT to quit the program" << std::endl;
        }
        std::cout << std::endl;
    }
}