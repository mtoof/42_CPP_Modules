/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:30:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/30 12:27:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	exit_banner()
{
	std::cout << "\033[2J\033[1;1H"<<std::flush;
	std::cout<<"  .oooooo.                              .o8   .o8                         "<< std::endl;
	std::cout<<" d8P'  `Y8b                             888   888                             "<< std::endl;
	std::cout<<"888            .ooooo.   .ooooo.   .oooo888   888oooo.  oooo    ooo  .ooooo.  "<< std::endl;
	std::cout<<"888           d88' `88b d88' `88b d88' `888   d88' `88b  `88.  .8'  d88' `88b "<< std::endl;
	std::cout<<"888     ooooo 888   888 888   888 888   888   888   888   `88..8'   888ooo888 "<< std::endl;
	std::cout<<"`88.    .88'  888   888 888   888 888   888   888   888    `888'    888    .o "<< std::endl;
	std::cout<<" `Y8bood8P'   `Y8bod8P' `Y8bod8P' `Y8bod88P   `Y8bod8P'     .8'     `Y8bod8P' "<< std::endl;
	std::cout<<"                                                        .o..P'                "<< std::endl;
	std::cout<<"                                                        `Y8P'                 "<< std::endl;
	std::cout<<"                                                                              "<< std::endl;
}
static void	start_banner()
{
	std::cout << "\033[2J\033[1;1H"<<std::flush;
	std::cout<<"  #     #             # "<< std::endl;
    std::cout<<"  ##   ## #   #      # #   #    # ######  ####   ####  #    # ###### " << std::endl;
    std::cout<<"  # # # #  # #      #   #  #    # #      #      #    # ##  ## #      " << std::endl;
    std::cout<<"  #  #  #   #      #     # #    # #####   ####  #    # # ## # #####  " << std::endl;
    std::cout<<"  #     #   #      ####### # ## # #           # #    # #    # #      " << std::endl;
    std::cout<<"  #     #   #      #     # ##  ## #      #    # #    # #    # #      " << std::endl;
    std::cout<<"  #     #   #      #     # #    # ######  ####   ####  #    # ###### " << std::endl;
    std::cout<<"                                                                     " << std::endl;
    std::cout<<"   ######                              ######                       " << std::endl;
    std::cout<<"   #     # #       ####  #    # ###### #     #  ####   ####  #    # " << std::endl;
    std::cout<<"   #     # #      #    # ##   # #      #     # #    # #    # #   #  " << std::endl;
    std::cout<<"   ######  ###### #    # # #  # #####  ######  #    # #    # ####   " << std::endl;
    std::cout<<"   #       #    # #    # #  # # #      #     # #    # #    # #  #   " << std::endl;
    std::cout<<"   #       #    # #    # #   ## #      #     # #    # #    # #   #  " << std::endl;
    std::cout<<"   #       #    #  ####  #    # ###### ######   ####   ####  #    # " << std::endl;
	std::cout<<"\n"<<std::endl;
    std::cout<<"======================================================================" << std::endl;
	std::cout<<"\n"<<std::endl;
	std::cout<<"               Use ADD, SEARCH or EXIT command\n"<<std::endl;
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
	start_banner();
	PhoneBook my_phonebook;
	while (my_phonebook.command());
	exit_banner();
	return (0);
}