/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:22:45 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:37:33 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
protected:
  std::string _name;
  unsigned int _hitpoints;
  unsigned int _energypoints;
  unsigned int _attackdamage;

public:
  // Constructors and Destructor
  ClapTrap();                                // Default constructor
  ClapTrap(const std::string &name);         // Parametrized constructor
  ClapTrap(const ClapTrap &copy);            // Copy constructor
  ClapTrap &operator=(const ClapTrap &copy); // Assignment Operator overload
  ~ClapTrap();                               // Destructor

  // Subject fucntions
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  // Getter functions
  std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

  // Setter functions
  void setName(std::string name);
  void setHitPoints(unsigned int hitpoints);
  void setEnergyPoints(unsigned int energypoints);
  void setAttackDamage(unsigned int attackdamage);
};
