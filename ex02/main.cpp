/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:08:42 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/04 00:44:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
  section("Test 1: Instantiation & Cleanup");
  {
    FragTrap ft("Fraggy");
  }

  section("Test 2: Copy Constructor & Assignment");
  {
    FragTrap a("Alpha");
    FragTrap b(a);
    FragTrap c("Gamma");
    c = a;
  }

  section("Test 3: Attack / Damage / Repair (Normal Flow)");
  {
    FragTrap attacker("Attacker");
    FragTrap target("Target");

    attacker.attack("Target");
    target.takeDamage(30);
    target.beRepaired(25);
    target.attack("Attacker");
    attacker.takeDamage(40);
    attacker.beRepaired(10);
  }

  section("Test 4: Repeated Attacks Until Energy Runs Out");
  {
    FragTrap spammer("Spammer");
    for (int i = 0; i < 102; ++i) {
      std::cout << "Attack " << i + 1 << ": ";
      spammer.attack("Dummy");
    }
  }

  section("Test 5: Repeated Repairs Until Energy Runs Out");
  {
    FragTrap healer("Healer");
    for (int i = 0; i < 101; ++i) {
      std::cout << "Repair " << i + 1 << ": ";
      healer.beRepaired(1);
    }
    std::cout << "Attempting one extra repair: ";
    healer.beRepaired(1);
  }

  section("Test 6: Actions After Death");
  {
    FragTrap ghost("Ghost");
    ghost.takeDamage(100);
    ghost.attack("Someone");
    ghost.beRepaired(10);
  }

  section("Test 7: Overkill and No Resurrection");
  {
    FragTrap frag("Overfrag");
    frag.takeDamage(150);
    frag.beRepaired(200);
    frag.attack("Still Dead");
  }

  section("Test 8: Damage/Repair Stress Test");
  {
    FragTrap test("Tanky");
    for (int i = 0; i < 5; ++i) {
      std::cout << "Cycle " << i + 1 << ": ";
      test.takeDamage(10);
      test.beRepaired(5);
    }
    test.attack("Target");
  }

  section("Test 9: Special Ability - High Fives");
  {
    FragTrap friendly("Buddy");
    friendly.highFivesGuys();
  }

  colorprint("\nSUCCESS\n", GREEN);
  return 0;
}
