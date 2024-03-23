#include <iostream>
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
int fibonnacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonnacci(n - 1) + fibonnacci(n - 2);
  }
}
void abecedario(char l) {
  if (l <= 'z') {
    abecedario(l + 1);
    std::cout << l << " ";
  }
}
int main() {
  int opt;
  std::cout
      << "Que quieres realizar? 1.Factorial 2.Fibonacci 3.AbecedarioInverso"
      << std::endl;
  std::cin >> opt;
  switch (opt) {
  case 1: {
    int val;
    std::cout << "De que valor quieres calcular el factorial" << std::endl;
    std::cin >> val;
    std::cout << "El factorial de " << val << " es " << factorial(5)
              << std::endl;
    break;
  }
  case 2: {
    int n;
    std::cout << "Ingrese los elementos de la serie fibonacci" << std::endl;
    std::cin >> n;
    std::cout << "La serie de " << n << " elementos es:" << std::endl;
    for (int i = 0; i < n; i++) {
      std::cout << fibonnacci(i) << " ";
    }
    break;
  }
  case 3: {
    abecedario('a');
    break;
  }
  }
}
