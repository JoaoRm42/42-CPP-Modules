//
// Created by Juanito on 16/01/2024.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), _target("Default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this == &obj)
        return (*this);
    this->_target = obj._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::string ShrubberyCreationForm::getTarget() const {
    return (this->_target);
}

void ShrubberyCreationForm::typeExecute() const {
    std::ofstream file;
    std::string name = this->_target + "_shrubbery";

    file.open(name.c_str());
    if (!file.is_open()) {
        std::cout << "Something went wrong with the creation of the file" << std::endl;
        return ;
    }
    file << "discord-bot/" << std::endl;
    file << "|─ .github/" << std::endl;
    file << "|─ src/" << std::endl;
    file << "│  ├─ assets/utils/" << std::endl;
    file << "│  ├─ commands/" << std::endl;
    file << "│  ├─ config/" << std::endl;
    file << "│  ├─ database/" << std::endl;
    file << "│  ├─ events/" << std::endl;
    file << "│  ├─ handlers/" << std::endl;
    file << "│  ├─ interactions/" << std::endl;
    file << "│  ├─ bot.js" << std::endl;
    file << "│  ├─ dev.js" << std::endl;
    file << "│  ├─ index.js" << std::endl;
    file << "├─ .env.example" << std::endl;
    file << "├─ .gitignore" << std::endl;
    file << "├─ .replit" << std::endl;
    file << "├─ Dockerfile" << std::endl;
    file << "├─ LICENSE" << std::endl;
    file << "├─ README.md" << std::endl;
    file << "├─ package.json" << std::endl;
    file << "├─ replit.nix" << std::endl;
    file << "cute-animal-pics/" << std::endl;
    file << "games/" << std::endl;
    file.close();
}
