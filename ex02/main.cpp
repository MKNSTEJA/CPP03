/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:08:42 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/01 19:09:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.hpp"

int main() {
  section("Test 1: Instantiation & Cleanup");
  {
    ClapTrap john("John");
  }

  section("Test 2: Copy Constructor & Assignment");
  {
    ClapTrap alpha("Alpha");
    ClapTrap beta(alpha);
    ClapTrap gamma("Gamma");
    gamma = alpha;
  }

  section("Test 3: Attack / Damage / Repair (Normal Flow)");
  {
    ClapTrap attacker("Attacker");
    ClapTrap target("Target");

    attacker.attack("Target");
    target.takeDamage(4);
    target.beRepaired(3);
    target.attack("Attacker");
    attacker.takeDamage(6);
    attacker.beRepaired(5);
  }

  section("Test 4: Repeated Attacks Until Energy Runs Out");
  {
    ClapTrap spam("Spammer");
    for (int i = 0; i < 11; ++i) {
      std::cout << "Attack " << i + 1 << ": ";
      spam.attack("TargetDummy");
    }
  }

  section("Test 5: Repeated Repairs Until Energy Runs Out");
  {
    ClapTrap healer("Healer");
    for (int i = 0; i < 10; ++i) {
      std::cout << "Repair " << i + 1 << ": ";
      healer.beRepaired(1);
    }
    std::cout << "Attempting one extra repair: ";
    healer.beRepaired(1);
  }

  section("Test 6: Actions After Death (0 Hitpoints)");
  {
    ClapTrap ghost("Ghost");
    ghost.takeDamage(10); // Kill it
    ghost.attack("Someone");
    ghost.beRepaired(5);
  }

  section("Test 7: Overkill and Invalid Revival");
  {
    ClapTrap overkill("Overkill");
    overkill.takeDamage(50);  // Kill it hard
    overkill.beRepaired(100); // Should not revive
    overkill.attack("Still Dead");
  }

  section("Test 8: Cycle Damage and Repair (Stress Test)");
  {
    ClapTrap tank("Tank");
    for (int i = 1; i <= 5; ++i) {
      std::cout << "Cycle " << i << ": ";
      tank.takeDamage(2);
      tank.beRepaired(1);
    }
    tank.attack("Enemy");
  }

  colorprint("\n✅ All tests executed. Please review printed logs above to "
             "verify correct behavior.\n",
             BLUE);
  return 0;
}
