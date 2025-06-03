/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:59 by kmummadi          #+#    #+#             */
/*   Updated: 2025/06/01 19:09:33 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Define colours
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string ORANGE = "\033[38;5;208m"; // Extended ANSI: orange!
const std::string RESET = "\033[0m";
const std::string ITALIC = "\033[3m";

void colorprint(std::string str, const std::string color);
std::string colortxt(std::string str, const std::string color);
void section(const std::string &title);
