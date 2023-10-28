/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:31:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/28 20:42:44 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

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
	std::string des_file_name;
	fd_read.open(av, std::ios::in);
	if (fd_read.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		return (1);
	}
	des_file_name.append(av);
	des_file_name.append(".replace");
	fd_write.open(des_file_name, std::ios::out);
	if (fd_write.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		return (1);
	}
	return (0);
}
int	main(int ac, char **av)
{
	std::stringstream	buffer_file;
	std::ifstream		fd_read;
	std::ofstream		fd_write;
	std::string			read_str;
	std::string			read_buf;
	size_t				last_found = 0;
	size_t				prev_found = 0;
	int					str1_len = 0;

	
	if (ft_error(ac, av))
		return (1);
	if (check_read_write_files(fd_read, fd_write, av[1]))
		return (1);
	str1_len = std::strlen(av[2]);
	if (fd_read.is_open())
	{
		buffer_file << fd_read.rdbuf();
		read_buf = buffer_file.str();
		last_found = read_buf.find(av[2]);
		while (last_found != std::string::npos)
		{
			read_str += read_buf.substr(prev_found, last_found - prev_found) + av[3];
			prev_found = last_found + str1_len;
			last_found = read_buf.find(av[2], prev_found);
		}
		read_str += read_buf.substr(prev_found);
	}
	fd_write << read_str;
	fd_read.close();
	fd_write.close();
	return (0);
}