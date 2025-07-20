/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:26:32 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/01 19:09:37 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

void colorprint(std::string str, const std::string color) {
  std::cout << colortxt(str, color);
}

std::string colortxt(std::string str, const std::string color) {
  return (color + str + RESET);
}

// Section marker
void section(const std::string &title) {
  std::cout << std::endl;
  colorprint("==================== ", ORANGE);
  colorprint(title, ITALIC);
  colorprint(" ====================\n", ORANGE);
}
