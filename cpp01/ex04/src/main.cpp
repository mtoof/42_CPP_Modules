/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:31:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 14:21:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int	ft_error(int ac , char **av)
{
	if (ac < 4 || ac > 4)
	{
		std::cout << "Error: Invalid Arguments number" << "\n" \
		<< "./Sed_is_for_losers <File_name to be opened>" << \
		" str1 str2" << std::endl;
		return (1);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cout << "Error: Found NULL argument\n \
		Can't accept NULL strings as argument" << std::endl;
		return (1);
	}
	return (0);
}

int	check_read_write_files(std::ifstream &fd_read, std::ofstream &fd_write, char *av)
{
	fd_read.open(av, std::ios::in);
	if (fd_read.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		return (1);
	}
	fd_write.open(std::strcat(av,".replace"), std::ios::app);
	if (fd_write.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		return (1);
	}
	return (0);
}
int	main(int ac, char **av)
{
	std::ifstream	fd_read;
	std::ofstream	fd_write;
	std::string		read_str;
	std::string		read_buf;

	
	if (ft_error(ac, av))
		return (1);
	if (check_read_write_files(fd_read, fd_write, av[1]))
		return (1);
	if (fd_read.is_open())
	{
		while (fd_read)
		{
			std::getline(fd_read, read_buf);
			read_str.append(read_buf);
			read_str.append("\n");
		}
	}
	fd_write << read_str;
	fd_read.close();
	fd_write.close();
	return (0);
}