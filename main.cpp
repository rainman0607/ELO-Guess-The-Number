/**
 * Number Guess Game, twisted with Elo Rating
 * Link to elo: https://en.wikipedia.org/wiki/Elo_rating_system
 *
 * <3The most beautiful rating algorithm<3
 *
 * Created by: <Aske Merci, raimman@merci>
 * Created at: 11/06/19 - 9:30
 */

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
/**
 * Secret = The random number from 1-10
 * Ra = Rating for player 1, a thumb rule is that all players start at 1000
 * Rb = Same as Ra
 * PaG = Player A Guess
 * PbG = Player B Guess
 * K = Is the K factor, usally when a rating is significantly
 * lower that the opponents, the opponents K Factor would be 16, but i'm too lazy for that
 *
 * Ea = Expected Winning percentage for Player A
 * Eb = Same as Ea
 */
int Secret, Ra=1000, Rb=1000, PaG=0, PbG=0, K=32;
double Ea, Eb;

int main() {
    // init seeder
    srand(time(NULL));


    cout << "Guess the secret number! (Shh, It's from 1-10)" << Secret << endl;
    // Calculate estimated winning chances
    // https://wikimedia.org/api/rest_v1/media/math/render/svg/51346e1c65f857c0025647173ae48ddac904adcb
    Ea =  1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Rb - Ra) / 400));
    Eb = 1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Ra - Rb) / 400));
    while(true) {
        // Secret number from 1-10
        Secret = rand() % 10 + 1;
        cout << "Player 1 (Elo: " << Ra << " Chances of winning: " << Ea << "%" << endl;
        cin >> PaG;

        cout << "Player 2 (Elo: " << Rb << " Chances of winning: " << Eb << "%" << endl;
        cin >> PbG;

        if(PaG == Secret && PbG != Secret) {
            // For a Win, one point assigned
            // For a lose, zero points assigned
            Ra = Ra + K * (1 - Ea);
            Rb = Rb + K * (0 - Eb);
            Ea =  1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Rb - Ra) / 400));
            cout << "Player 1 wins! New rating: " << Ra << endl ;
        } else if(PbG == Secret && PaG != Secret)
        {
            // For a Win, one point assigned
            // For a lose, zero points assigned
            Rb = Rb + K * (1 - Eb);
            Ra = Ra + K * (0 - Ea);
            Eb =  1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Ra - Rb) / 400));
            cout << "Player 2 wins! New rating: " << Rb << endl;

        } else if(PbG == Secret && PaG == Secret)
            {
                // If a draw, all players are assigned 0.5 points
                Rb = Rb + K * (0.5 - Eb);
                Ra = Ra + K * (0.5 - Ea);
                Ea =  1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Rb - Ra) / 400));
                Eb = 1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (Rb - Ra) / 400));
                cout << "It's a draw! "<< endl;
            }
        else {
            cout << "Ain't nobody had it right! "<< endl;

        }
    }

}