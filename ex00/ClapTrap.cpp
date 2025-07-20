/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:32:40 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:26:37 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"
#include <iostream>

// Constructors and Destructors
ClapTrap::ClapTrap()
    : _name("Anonymous"), _hitpoints(10), _energypoints(10), _attackdamage(0) {
  std::string msg;
  msg = "Default constructor of ClapTrap \"" + _name + "\" called.\n";
  colorprint(msg, GREEN);
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0) {
  std::string msg;

  msg = "Parametrised constructor of ClapTrap \"" + _name + "\" called.\n";
  colorprint(msg, GREEN);
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy.getName()), _hitpoints(copy.getHitPoints()),
      _energypoints(copy.getEnergyPoints()),
      _attackdamage(copy.getAttackDamage()) {
  std::string msg;

  msg = "Copy constructor of ClapTrap \"" + _name + "\" called.\n";
  colorprint(msg, GREEN);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  std::string msg;

  msg = "Copy assignment overload of Claptrap called\n";
  colorprint(msg, GREEN);
  if (this != &copy) {
    _name = copy.getName();
    _attackdamage = copy.getAttackDamage();
    _energypoints = copy.getEnergyPoints();
    _hitpoints = copy.getAttackDamage();
  }
  return (*this);
}

ClapTrap::~ClapTrap() {
  std::string msg;

  msg = "Destructor of ClapTrap \"" + _name + "\" called.\n";
  colorprint(msg, GREEN);
}

// Getter functions
std::string ClapTrap::getName() const { return (_name); }

unsigned int ClapTrap::getAttackDamage() const { return (_attackdamage); }

unsigned int ClapTrap::getEnergyPoints() const { return (_energypoints); }

unsigned int ClapTrap::getHitPoints() const { return (_hitpoints); }

// Setter functions
void ClapTrap::setName(std::string name) { _name = name; }

void ClapTrap::setHitPoints(unsigned int hitpoints) { _hitpoints = hitpoints; }

void ClapTrap::setEnergyPoints(unsigned int energypoints) {
  _energypoints = energypoints;
}

void ClapTrap::setAttackDamage(unsigned int attackdamage) {
  _attackdamage = attackdamage;
}

// Subject functions
void ClapTrap::attack(const std::string &target) {
  if (_energypoints > 0 && _hitpoints > 0) {
    --_energypoints;
    std::cout << "Claptrap " + _name + " attacks " + target + ", causing "
              << _attackdamage << " points of damage!\n";
  } else if (_hitpoints == 0) {
    colorprint("ClapTrap " + _name + " has died and cannot attack\n", ORANGE);
  } else if (_energypoints == 0) {
    colorprint("ClapTrap " + _name + " lacks energypoints to attack\n", ORANGE);
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "Claptrap " << _name << " has taken -" << amount
            << "HP damage\n";
  if (_hitpoints > amount) {
    _hitpoints -= amount;
    std::cout << "HP left: " << _hitpoints << "\n";
  } else {
    _hitpoints = 0;
    colorprint(_name + " died!\n", ORANGE);
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energypoints > 0 && _hitpoints > 0) {
    _energypoints--;
    _hitpoints += amount;
    std::cout << "Claptrap " << _name << " has gained " << amount << "HP\n";
  } else if (_energypoints == 0) {
    colorprint("Claptrap " + _name + " lacks energypoints to repair itself\n",
               ORANGE);
  } else if (_hitpoints == 0)
    colorprint("Claptrap " + _name + " has died and cannot repair itself\n",
               ORANGE);
}
