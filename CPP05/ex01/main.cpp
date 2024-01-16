//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat	one;
    Bureaucrat	two("Segundo", 1);
    Bureaucrat	three("Terceiro", 75);
    Form		carta("Conducao", 1, 100);
    Form		carta2("tratado", 20, 100);
    Form		carta3("tratado2", 80, 100);

    std::cout << one << std::endl;
    std::cout << two << std::endl;
    std::cout << three << std::endl;
    std::cout << carta << std::endl;
    carta.beSigned(two);
    std::cout << carta << std::endl;
    two.signForm(carta);
    std::cout << carta2 << std::endl;
    two.signForm(carta2);
    std::cout << carta2 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    try{
        three.signForm(carta2);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    try{
        one.signForm(carta);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    std::cout << carta3 << std::endl;
    try{
        three.signForm(carta3);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    std::cout << carta3 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    try{
        Bureaucrat	four("Quarto", 0);
        try{
            four.signForm(carta2);
        } catch (std::exception &t) {
            std::cout << t.what() << std::endl;
        }
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    try{
        Bureaucrat	four("Quarto", 155);
        try{
            four.signForm(carta2);
        } catch (std::exception &t) {
            std::cout << t.what() << std::endl;
        }
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    return (0);
}

