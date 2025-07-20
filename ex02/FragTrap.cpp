/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:35:08 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:42:02 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

// Constructors and Destructors
FragTrap::FragTrap() : ClapTrap() {
  _name = "Anonymous";
  _hitpoints = 100;
  _attackdamage = 30;
  _energypoints = 100;
  colorprint("Default constructor of Fragtrap " + _name + " called\n", GREEN);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  _hitpoints = 100;
  _attackdamage = 30;
  _energypoints = 100;
  colorprint("Parametrised constructor of Fragtrap " + _name + " called\n",
             GREEN);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  colorprint("Copy constructor of Fragtrap " + _name + " called\n", GREEN);
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  colorprint("Copy assignment operator of Fragtrap " + _name + " called\n",
             GREEN);
  if (this != &copy)
    ClapTrap::operator=(copy);
  return (*this);
}

FragTrap::~FragTrap() {
  colorprint("Destructor of Fragtrap " + _name + " called\n", GREEN);
}

// Member functions
void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << _name << " requests a High-Five!\n";
}
