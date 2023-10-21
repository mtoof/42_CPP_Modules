/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:30:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/21 22:11:46 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	banner()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout<<std::endl;
	std::cout<<"  #     #             # "<< std::endl;
    std::cout<<"  ##   ## #   #      # #   #    # ######  ####   ####  #    # ###### " << std::endl;
    std::cout<<"  # # # #  # #      #   #  #    # #      #      #    # ##  ## #      " << std::endl;
    std::cout<<"  #  #  #   #      #     # #    # #####   ####  #    # # ## # #####  " << std::endl;
    std::cout<<"  #     #   #      ####### # ## # #           # #    # #    # #      " << std::endl;
    std::cout<<"  #     #   #      #     # ##  ## #      #    # #    # #    # #      " << std::endl;
    std::cout<<"  #     #   #      #     # #    # ######  ####   ####  #    # ###### " << std::endl;
    std::cout<<"                                                                     " << std::endl;
    std::cout<<"   ######                              ######                       " << std::endl;
    std::cout<<"   #     # #    #  ####  #    # ###### #     #  ####   ####  #    # " << std::endl;
    std::cout<<"   #     # #    # #    # ##   # #      #     # #    # #    # #   #  " << std::endl;
    std::cout<<"   ######  ###### #    # # #  # #####  ######  #    # #    # ####   " << std::endl;
    std::cout<<"   #       #    # #    # #  # # #      #     # #    # #    # #  #   " << std::endl;
    std::cout<<"   #       #    # #    # #   ## #      #     # #    # #    # #   #  " << std::endl;
    std::cout<<"   #       #    #  ####  #    # ###### ######   ####   ####  #    # " << std::endl;
	std::cout<<"\n"<<std::endl;
    std::cout<<"=================================================================== " << std::endl;
	std::cout<<"\n"<<std::endl;
}

void	user_input(std::string &prompt)
{
	std::getline(std::cin, prompt);
	if (std::cin.eof())
	{
		std::cout<<std::endl;
		exit(0);
	}
}

int main()
{
	banner();
	PhoneBook my_phonebook;
	while (my_phonebook.command());
	return (0);
}