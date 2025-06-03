/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:32:25 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:35:00 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "utils.hpp"

class FragTrap : public ClapTrap {
public:
  // Constructors and Destructors
  FragTrap();                                // Default Constructor
  FragTrap(const std::string &name);         // Parametrised constructor
  FragTrap(const FragTrap &copy);            // Copy constructor
  FragTrap &operator=(const FragTrap &copy); // Copy assignment operator
  ~FragTrap();                               // Destructor

  // Member functions
  void highFivesGuys();
};
