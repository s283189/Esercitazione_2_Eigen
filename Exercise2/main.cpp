#include <iostream>
#include "Eigen/Eigen"
#include "iomanip"

using namespace std;
using namespace Eigen;

int main()
{
    // Definizione delle matrici A e b per ciascun sistema
    Matrix2d A1, A2, A3;
    Vector2d b1, b2, b3;

    // Inizializzazione delle matrici A e vettori b per ciascun sistema
    A1 << 5.547001962252291e-01, -3.770900990025203e-02,
        8.320502943378437e-01, -9.992887623566787e-01;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;

    A2 << 5.547001962252291e-01, -5.540607316466765e-01,
        8.320502943378437e-01, -8.324762492991313e-01;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;

    A3 << 5.547001962252291e-01, -5.547001955851905e-01,
        8.320502943378437e-01, -8.320502947645361e-01;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;

    // Calcolo della soluzione per ciascun sistema utilizzando la decomposizione PALU
    Vector2d p1, p2, p3;
    p1 = A1.fullPivLu().solve(b1);
    p2 = A2.fullPivLu().solve(b2);
    p3 = A3.fullPivLu().solve(b3);

    // Calcolo dell'errore per ciascun sistema
    double perror1 = (A1 * p1 - b1).norm() / b1.norm();
    double perror2 = (A2 * p2 - b2).norm() / b2.norm();
    double perror3 = (A3 * p3 - b3).norm() / b3.norm();

    // Stampa delle soluzioni e degli errori della decomposizione PALU
    cout << "Soluzioni e errori decomposizione PALU" << endl << endl;
    cout << scientific << setprecision(1) << "Soluzione sistema 1: " << endl << p1 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 1: " << endl << perror1 << endl << endl;

    cout << scientific << setprecision(1) << "Soluzione sistema 2: " << endl << p2 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 2: " << endl << perror2 << endl << endl;

    cout << scientific << setprecision(1) << "Soluzione sistema 3: " << endl << p3 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 3: " << endl << perror3 << endl << endl;

    // Calcolo della soluzione per ciascun sistema utilizzando la decomposizione QR
    Vector2d q1, q2, q3;
    q1 = A1.colPivHouseholderQr().solve(b1);
    q2 = A2.colPivHouseholderQr().solve(b2);
    q3 = A3.colPivHouseholderQr().solve(b3);

    // Calcolo dell'errore per ciascun sistema
    double qerror1 = (A1 * q1 - b1).norm() / b1.norm();
    double qerror2 = (A2 * q2 - b2).norm() / b2.norm();
    double qerror3 = (A3 * q3 - b3).norm() / b3.norm();

    // Stampa delle soluzioni e degli errori della decomposizione QR
    cout << "Soluzioni e errori decomposizione QR" << endl << endl;
    cout << scientific << setprecision(1) << "Soluzione sistema 1: " << endl << q1 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 1: " << endl << qerror1 << endl << endl;

    cout << scientific << setprecision(1) << "Soluzione sistema 2: " << endl << q2 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 2: " << endl << qerror2 << endl << endl;

    cout << scientific << setprecision(1) << "Soluzione sistema 3: " << endl << q3 << endl;
    cout << scientific << setprecision(16) << "Errore sistema 3: " << endl << qerror3 << endl;
    return 0;
}
