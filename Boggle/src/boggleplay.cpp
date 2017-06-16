// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header
////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "lexicon.h"
#include "Boggle.h"
#include <cctype> // for tolower()


/*
No heavy logic and knows nothing about rules of boggle
used boggle class for all the heavy logic
*/

bool isValidString(string word){
    int strSize = word.size();
    if (strSize != 16)
        return false;
    for(int i=0; i< (int) word.size(); i++){
        if(!isalpha(word[i]))
            return false;
    }
    return true;
}

void playOneGame(Lexicon& dictionary) {
    cout<<"\n Play one game called...";

    cout<<"\nDo you want to generate a random board? ";
    string str; getline(cin, str);
    char resp; resp = tolower(str[0]);

    // cout<<"\n response entered: "<<resp;
    string initStr = "";                            // string = "" for random cubes of boggle, ELSE a valid 16-letter string
    while(1){                                       // loop until correct response is entered
        if(resp == 'y'){                            // you get yes | generate random board and play
            break;
        }
        else if(resp == 'n'){                       // you get no | generate custom board and play

            cout<<"Type the 16 letters to appear on the board: ";
            string boardLetters;
            getline(cin, boardLetters);
            while(1){
                if( !isValidString(boardLetters) ){ // incorrect string
                    cout<<"That is not a valid 16-letter board string. Try again.\n";
                    cout<<"Type the 16 letters to appear on the board: ";
                    getline(cin, boardLetters);
                }else{ // correct string
                    initStr = boardLetters;
                    break;
                }
            }
            break;
        }
        else{                                      // invalid response | ask again
            cout<<"\nPlease type a word that begins with 'y' or 'n'.";
            cout<<"\nDo you want to generate a random board? ";
            cin>>resp; resp = tolower(resp);
        }
    }

    Boggle currGame(dictionary, initStr);          // initialise board

    while (1) {                                    // play game until user says NO
        // game play logic starts
        string humanInput;
        cout<<"Your words ("<<currGame.getScoreHuman()<<"): "<<currGame.printHumanWords()<<endl;
        cout<<"Your score: "<<currGame.getScoreHuman()<<"\n";
        cout<<"Type a word (or Enter to stop): ";
        getline(cin,humanInput);
        if(humanInput == ""){                     // user wants to stop the game
        }

        else{                                     // user will enter more words
            Vector<string> enteredWords = currGame.splitStringToWords(humanInput, ' ');
            Vector<int> indexesToRemove;
            int idx = 0;
            for (Vector<string>::iterator it = enteredWords.begin() ; it != enteredWords.end(); ++it){

                // std::cout << ' ' << *it;
                // if  word is not valid, save it
                if(!currGame.humanWordSearch(*it)){
                    // enteredWords.remove(idx); idx--;
                    cout<<"\n Will delete "<<*it;
                    indexesToRemove.push_back(idx);
                }
                idx++;
            }
            for(int i=indexesToRemove.size()-1; i>-1; i--){
                enteredWords.remove(indexesToRemove[i]);
            }

            cout<<"\n Valid entered words are: "<<enteredWords.toString();
        }

        break;

        // game play logic ends
    }

    cout<<"Have a nice day.";




    cout<<"\n Play one game exiting...";

}
