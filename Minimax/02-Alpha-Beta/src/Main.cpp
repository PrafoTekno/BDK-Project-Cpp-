
#include <iostream>
using namespace std;

const int Max = 100000;
const int Min = -100000;

int minimax (int nilai[], int index_node, int depth, bool cekMax, int alpha, int beta) {

    if (depth == 3) {
        return nilai[index_node];
    }

    if (cekMax) {

        int bestVal = Min;
        
        for (int i = 0; i < 2; i++) {

            int eval = minimax (nilai, index_node * 2 + i, depth + 1, false, alpha, beta);

            bestVal = max (bestVal, eval); 
            int alpha = max (alpha, bestVal);

            if (alpha <= beta) {
                break;
            }

        }

        return bestVal;

    }

    else {

        int bestVal = Max;

        for (int i = 0; i < 2; i++) {

            int eval = minimax (nilai, index_node * 2 + i, depth + 1, true, alpha, beta);
            
            bestVal = min (bestVal, eval);
            beta = min (beta, bestVal);

            if (alpha <= beta) {
                break;
            }

        }

        return bestVal;

    }

}

int main () {

    cout << "\n\t======= Alpha Beta ======\n" << endl;

    int bilangan[] = {1,3,5,4,8,9,10,20};    
    int hasil = minimax (bilangan, 0, 0, true, Max, Min);

    cout << "Bilangannya adalah : ";

    for (int i = 0; i < sizeof (bilangan) / sizeof (bilangan[0]); i++) {
        cout << bilangan[i] << ", ";
    }

    cout << "\n\nHasilnya adalah : " << hasil << endl;

    cout << endl;

    return 0;

}