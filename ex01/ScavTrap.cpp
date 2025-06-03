/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:14:56 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:17:07 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "utils.hpp"

// Constructors and Destructors
ScavTrap::ScavTrap() : ClapTrap() {
  _name = "Anonymous";
  _hitpoints = 100;
  _attackdamage = 20;
  _energypoints = 50;
  colorprint("Default constructor of Scavtrap " + _name + " called\n", GREEN);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitpoints = 100;
  _attackdamage = 20;
  _energypoints = 50;
  colorprint("Parametrised constructor of Scavtrap " + _name + " called\n",
             GREEN);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  colorprint("Copy constructor of Scavtrap " + _name + " called\n", GREEN);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
  colorprint("Copy assignment operator of Scavtrap " + _name + " called\n",
             GREEN);
  if (this != &copy)
    ClapTrap::operator=(copy);
  return (*this);
}

ScavTrap::~ScavTrap() {
  colorprint("Destructor of Scavtrap " + _name + " called\n", GREEN);
}

// Member functions
void ScavTrap::attack(const std::string &target) {
  if (_energypoints > 0 && _hitpoints > 0) {
    --_energypoints;
    std::cout << "Scavtrap " + _name + " attacks " + target + ", causing"
              << _attackdamage << "points of damage!\n";
  } else if (_hitpoints == 0) {
    colorprint("ScavTrap " + _name + " lacks hitpoints to attack\n", ORANGE);
  } else if (_energypoints == 0) {
    colorprint("ScavTrap " + _name + "lacks energypoints to attack\n", ORANGE);
  }
}

void ScavTrap::guardGate() {
  colorprint("ScavTrap " + _name + " is now in Gate keeper mode\n", YELLOW);
}
