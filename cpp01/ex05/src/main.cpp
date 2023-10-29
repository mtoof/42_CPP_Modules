/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:31:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/29 13:07:21 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl_test;

	harl_test.complain("DEBUG");
	harl_test.complain("INFO");
	harl_test.complain("WARNING");
	harl_test.complain("ERROR");
	harl_test.complain("NOTHING");
	return (0);
}