/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:06:17 by joaoped           #+#    #+#             */
/*   Updated: 2024/01/03 16:06:22 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by joaoped2 on 12/27/23.
//

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* ice;
    AMateria* cure;
    ice = src->createMateria("ice");
    me->equip(ice);
    cure = src->createMateria("cure");
    me->equip(cure);
    ice = src->createMateria("ice");
    bob->equip(ice);
    cure = src->createMateria("cure");
    bob->equip(cure);
    cure = src->createMateria("cure");
    me->equip(cure);
    cure = src->createMateria("cure");
    bob->equip(cure);
    std::cout << std::endl;
    std::cout << "Bob tests" << std::endl;
    bob->use(0, *bob);
    bob->use(1, *bob);
    bob->use(2, *bob);
    bob->use(3, *bob);
    bob->use(4, *bob);
    bob->unequip(1);

    std::cout << std::endl;
    std::cout << "Me tests" << std::endl;
    me->use(0, *me);
    me->use(1, *me);
    me->use(2, *me);
    me->use(3, *me);
    me->use(4, *me);
    me->unequip(0);
    delete bob;
    delete me;
    delete src;
    return 0;

}