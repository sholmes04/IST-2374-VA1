#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main(){
    std::string choice = "y";
    while(choice == "y"){
        HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); //creates handle for the screen

        //random d20 copied from ch3
        srand(time(NULL));
        int d20p1 = (rand() % 20) + 1;
        int d20p2 = (rand() % 20) + 1;
        
        //initialize crits
        bool critFailp1 = false;
        bool critSuccessp1 = false;
        bool critFailp2 = false;
        bool critSuccessp2 = false;

        //initialize players
        std::string player1 = "";
        std::string player2 = "";

        //menu
        std::cout << "======================\n";
        std::cout << "Dice Roll Comparison\n";
        std::cout <<"=======================\n";
        std::cout << "\n";

        std::cout << "Name player 1: \n";
        std::cin >> player1;
        std::cout << "Name player 2: \n";
        std:: cin >> player2;

        //rolls
        //p1 crits
        if(d20p1 == 1){
            critFailp1 = true;
        }
        else if(d20p1 == 20){
            critSuccessp1 = true;
        }
        else{
            critFailp1 = false;
            critSuccessp1 = false;
        }
        //p2 crits
        if(d20p2 == 1){
            critFailp2 = true;
        }
        else if(d20p2 == 20){
            critSuccessp2 = true;
        }
        else{
            critFailp2 = false;
            critSuccessp2 = false;
        }

        //compare
        if(d20p1 > d20p2){
            std::cout << player1 << " Win\n";
            std::cout << "P1: " << d20p1 << "\n";
            std::cout << "P2: " << d20p2 << "\n";
                if(critSuccessp1 == true){
                    SetConsoleTextAttribute(screen, 10);
                    std::cout << player1 << " Critical Success\n"; //grn
                }
                else if(critSuccessp1 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }

                if(critFailp2 == true){
                    SetConsoleTextAttribute(screen, 12);
                    std::cout << player2 << " Critical Failure\n"; //red
                }
                else if(critFailp2 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }
        }
        else if(d20p1 < d20p2){
            std::cout << player2 << " Win\n";
            std::cout << "P1: " << d20p1 << "\n";
            std::cout << "P2: " << d20p2 << "\n";
                if(critSuccessp2 == true){
                    SetConsoleTextAttribute(screen, 10);
                    std::cout << player2 << " Critical Success\n"; //grn
                }
                else if(critSuccessp2 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }

                if(critFailp1 == true){
                    SetConsoleTextAttribute(screen, 12);
                    std::cout << player1 << " Critical Failure\n"; //red
                }
                else if(critFailp1 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }
        }
        
        else if(d20p1 == d20p2){
            std::cout << "Players Evenly Matched \n";
            std::cout << "P1: " << d20p1 << "\n";
            std::cout << "P2: " << d20p2 << "\n";
                if(critSuccessp1 == true){
                    SetConsoleTextAttribute(screen, 10);
                    std::cout << player1 << " Critical Success\n"; //grn
                }
                else if(critSuccessp1 == false){
                    std::cout << "\n";
                }
        
                else if(critFailp1 == true){
                    SetConsoleTextAttribute(screen, 12);
                    std::cout << player1 << " Critical Failure\n"; //red
                }
                else if(critFailp1 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }

                if(critSuccessp2 == true){
                    SetConsoleTextAttribute(screen, 10);
                    std::cout << player2 << " Critical Success\n"; //grn
                }
                else if(critSuccessp2 == false){
                    std::cout << "\n";
                }
                
                else if(critFailp2 == true){
                    SetConsoleTextAttribute(screen, 12);
                    std::cout << player2 << " Critical Failure\n"; //red
                }
                else if(critFailp2 == false){
                    std::cout << "\n";
                }
                else{
                    std::cout << "ERR\n";
                }
        }
        SetConsoleTextAttribute(screen, 7); //wht
        std::cout << "\n Run Again? (y/n): \n";
        std::cin >> choice;
    }
    return 0;
}
    














