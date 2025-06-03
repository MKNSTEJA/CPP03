/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:34:03 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:08:12 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
  // Constructors and Destructors
  ScavTrap();                                // Default constructor
  ScavTrap(const std::string &name);         // Parametrised constructor
  ScavTrap(const ScavTrap &copy);            // Copy constructor
  ScavTrap &operator=(const ScavTrap &copy); // Copy assignment operator
  ~ScavTrap();                               // Destructor

  // Member functions
  void attack(const std::string &target);
  void guardGate();
};
