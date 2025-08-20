// Copyright 2025 Ariane Saulnier

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:32:12 by asaulnie          #+#    #+#             */
/*   Updated: 2025/08/20 20:19:10 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  int i;
  int j;
  char c;

  i = 1;
  j = 0;
  if (argc == 1) {
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    return (0);
  }
  while (i < argc)
  {
    j = 0;
    while (argv[i][j])
    {
      c = argv[i][j];
      if (c >= 'a' && c <= 'z')
        c = c - 32;
      cout << c;
      j++;
    }
    cout << " ";
    i++;
  }
  cout << endl;
  return (0);
}
