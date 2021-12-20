/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:11:11 by user              #+#    #+#             */
/*   Updated: 2021/12/20 17:58:36 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# define E			int
# define DUMP_LIMIT	20

#include <utility>
#include <string>
struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

# include "utils.hpp"
# include <vector>
# include "../vector.hpp"
# include <stack>
# include "../stack.hpp"
# include <map>
# include "../map.hpp"
# include <set>
# include "../set.hpp"


#endif
