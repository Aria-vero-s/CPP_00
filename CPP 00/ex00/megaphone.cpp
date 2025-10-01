#include <iostream>

int main(int argc, char **argv) {
  int i;
  int j;
  char c;

  i = 1;
  j = 0;
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
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
      std::cout << c;
      j++;
    }
    std::cout << " ";
    i++;
  }
  std::cout << std::endl;
  return (0);
}
