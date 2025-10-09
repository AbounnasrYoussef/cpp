/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:51:06 by yabounna          #+#    #+#             */
/*   Updated: 2025/10/09 10:48:57 by yabounna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>


void to_upper(int  ac,char **av)
{
    int i = 0;
    int j = 0;
    
    for (i = 1; i < ac; i++)
    {
        for (j = 0 ; av[i][j]  ; j++ )
        {
            std::cout <<  (char)std::toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
}


int main(int ac, char **av) {

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        to_upper(ac, av);
    }

    return 0;
}