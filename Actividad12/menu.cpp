#include <algorithm>
#include <iostream>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

void initialize_board(int *board, int disc) {
  int *boardPtr;
  for (int i = 0; i < 3; i++) {
    boardPtr = board + i * disc;
    for (int j = 0; j < disc; j++) {
      if (i == 0) {
        boardPtr[j] = j + 1;
      } else {
        boardPtr[j] = 0;
      }
    }
  }
}

void print_board(int *board, int disc) {
  int *boardPtr;
  for (int i = 0; i < disc; i++) {
    for (int j = 0; j < 3; j++) {
      boardPtr = board + j * disc;
      cout << boardPtr[i] << " ";
    }
    cout << "\n";
  }
}

int position_pilar(int *pilarPtr, int n, int s) {
  int position = 0;
  int *ptr = pilarPtr;
  for (int i = s - 1; i >= 0; i--) {
    if (ptr[i] != 0 && ptr[i] > n) {
      position += 1;
    }
  }
  return position;
}

bool validate_move(int *board, int pilar, int pilarTo, int s) {
  bool retrnval = false;
  int *pilarPtr;
  int *pilarPtrTo;
  pilarPtr = board + ((pilar - 1) * s);
  pilarPtrTo = board + ((pilarTo - 1) * s);
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      if (j == 0) {
        if (pilarPtr[i] != 0 && pilarPtrTo[s - 1] == 0) {
          pilarPtrTo[(s - 1) - j] = pilarPtr[i];
          pilarPtr[i] = 0;
          return true;
        }
      }
      if (pilarPtr[i] != 0 && position_pilar(pilarPtrTo, pilarPtr[i], s) != 0) {
        pilarPtrTo[(s - 1) - position_pilar(pilarPtrTo, pilarPtr[i], s)] =
            pilarPtr[i];
        pilarPtr[i] = 0;
        return true;
      }
    }
  }
  return retrnval;
}

bool move(int *board, int pilar, int pilarTo, int s) {
  int rtrnvalue = false;
  if (validate_move(board, pilar, pilarTo, s)) {
    rtrnvalue = true;
    print_board(board, s);
  }
  return rtrnvalue;
}

int min_moves(int base, int times) {
  if (times < 1) {
    return 1;
  } else {
    int val = base;
    return val * min_moves(base, times - 1);
  }
}

bool won(int count, int s) {
  if (count == min_moves(2, s)) {
    cout << "Has ganado! :)" << endl;
  } else {
    cout << "Has perdido! ☹" << endl;
  }
  return false;
}

bool board1(int *brd, int s) {
  int board[3][s];
  int *boardPtr;
  int *brdPtr;
  for (int i = 0; i < 3; i++) {
    boardPtr = (int *)board + i * s;
    for (int j = 0; j < s; j++) {
      if (i == 1) {
        boardPtr[j] = j + 1;
      } else {
        boardPtr[j] = 0;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    boardPtr = (int *)board + i * s;
    brdPtr = brd + i * s;
    for (int j = 0; j < s; j++) {
      if (!(boardPtr[j] == brdPtr[j])) {
        return false;
      }
    }
  }
  return true;
}
bool board2(int *brd, int s) {
  int board[3][s];
  int *boardPtr;
  int *brdPtr;
  for (int i = 0; i < 3; i++) {
    boardPtr = (int *)board + i * s;
    for (int j = 0; j < s; j++) {
      if (i == 2) {
        boardPtr[j] = j + 1;
      } else {
        boardPtr[j] = 0;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    boardPtr = (int *)board + i * s;
    brdPtr = brd + i * s;
    for (int j = 0; j < s; j++) {
      if (!(boardPtr[j] == brdPtr[j])) {
        return false;
      }
    }
  }
  return true;
}

bool isDone(int *board, int disc) {
  if (board1(board, disc)) {
    return true;
  }
  if (board2(board, disc)) {
    return true;
  }
  return false;
}

void move(int *board, int s) {
  int countMove = 0;
  while (!isDone(board, s)) {
    // Torre de la que se movera
    int pilar = 0;
    cout << "De que torre deseas mover un disco?" << endl;
    cin >> pilar;

    // Torre a la que se movera
    int pilarTo = 0;
    cout << "A que torre deseas moverlo?" << endl;
    cin >> pilarTo;

    while ((pilar > 3 || pilar < 1) || (pilarTo > 3 || pilarTo < 1) ||
           (pilar == pilarTo)) {
      cout << "Pilares invalidos, ingresalos otra vez" << endl;
      print_board(board, s);
      cout << "De que torre deseas mover un disco?" << endl;
      cin >> pilar;
      cout << "A que torre deseas moverlo?" << endl;
      cin >> pilarTo;
    }

    bool movement = move(board, pilar, pilarTo, s);
    if (!movement) {
      cout << "Movimiento invalido, intenta otra vez" << endl;
      print_board(board, s);
      movement = move(board, pilar, pilarTo, s);
    }
    countMove++;
  }
  cout << "Haz realizado : " << countMove << " movimientos" << endl;
  won(countMove, s);
}
void board() {
  int disc = 3; // Variable para cantidad de discos

  cout << "Cuantos discos deseas utilizar? 3-8" << endl;
  cin >> disc;

  int board[3][disc]; // Variable para almacenar los datos del tablero
  cout << "Iniciando el juego..." << endl;
  initialize_board((int *)board,
                   disc); // LLama a la funcion de inicializar el tablero
  sleep(1);

  cout << "    Tablero inicial    " << endl;

  print_board((int *)board, disc); // Imprime el estado actual del tablero

  move((int *)board, disc);
}

void print_rules() {

  // Impresion de reglas

  cout << "Que divertido que hayas decidido jugar! Bienvenido a las reglas del "
          "juego!"
       << endl;

  sleep(3);
  cout << "El juego de las torres de Hanoi se trata de llevar todos los discos "
          "de un pilar hacia uno de los pilaes vacantes"
       << endl;

  sleep(3);
  cout << "Esto debe ser realizado sin colocar un disco de mayor valor sobre "
          "uno de menor"
       << endl;

  sleep(3);
  cout << "El valor de cada disco sera representado por un numero, mientras "
          "mayor el numero, mayor el valor"
       << endl;

  sleep(3);
  cout << "Solo es permitido mover el disco de arriba de cada torre" << endl;

  sleep(3);
  cout << "Cada movimiento invalido contara como un movimiento hecho, esto en "
          "forma de penalizacion, cuidado con tus movimientos!"
       << endl;

  sleep(3);
  cout << "Ganas el juego si consigues realizarlo en la menor cantidad de "
          "movimientos posibles"
       << endl;
  sleep(2);
}
void start_game() {

  int opt = 1; // Variable para la opcion de muestra de reglas
  //

  cout << "Quieres leer las reglas?\n1.Si 2.No" << endl;
  cin >> opt;

  if (opt == 1) {
    print_rules(); // Llama a funcion de imprimir reglas en caso de ser
                   // requerida
  }

  // Inicializacion de tablero
  board();
}
