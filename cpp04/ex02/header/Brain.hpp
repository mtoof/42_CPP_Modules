/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:25:26 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 17:02:42 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string.h>
#include <iostream>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);
	~Brain();

	void	setAnIdea(unsigned int index, std::string idea);
	std::string	getAnIdea(unsigned int index) const;
	void	getAllIdeas(void) const;
};


#endif