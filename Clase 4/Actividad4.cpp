#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    int caracol1 = 0;
    int caracol2 = 0;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int ronda = 1; ronda <= 5; ++ronda) {
        // Turno del caracol 1.
        int dado = std::rand() % 6 + 1;
        if (dado == 6) {
            caracol1 += 6;
            dado = std::rand() % 6 + 1;
            caracol1 += dado;
        } else if (dado == 1) {
            caracol1 -= 2;
            if (caracol1 < 0) {
                caracol1 = 0;
            }
        } else {
            caracol1 += dado;
        }

        // Turno del caracol 2.
        dado = std::rand() % 6 + 1;
        if (dado == 6) {
            caracol2 += 6;
            dado = std::rand() % 6 + 1;
            caracol2 += dado;
        } else if (dado == 1) {
            caracol2 -= 2;
            if (caracol2 < 0) {
                caracol2 = 0;
            }
        } else {
            caracol2 += dado;
        }

        std::cout << ".Ronda: " << ronda << '\n';
        std::cout << "Posicion caracol 1: " << caracol1 << " metros\n";
        std::cout << "Posicion caracol 2: " << caracol2 << " metros\n";
    }

    if (caracol1 > caracol2) {
        std::cout << "  Gano el caracol 1!\n";
    } else if (caracol2 > caracol1) {
        std::cout << "  Gano el caracol 2!\n";
    } else {
        std::cout << "  Hay empate!\n";
    }

    return 0;
}