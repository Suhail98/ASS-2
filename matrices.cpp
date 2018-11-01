// Program: Assignment 1 - Problem 0
// Purpose: Operator overloading for matrices
// Author:  Suhail Hany - Abdelrahman Morsi - Shahesta Alkady
// Date:    30 October 2018
// Version: 1.0

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int row,col;
    matrix mat1(4,2,data1), mat2(2,4,data2), mat3(4,2,data3);

    int choice , scaler;
    while(1)
    {
        cout << "Do you want to enter a matrix ?" << endl
             << "1- Yes" << endl
             << "2- No" << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "Which matrix do you want to insert " << endl
                 << "1- Mat1" << endl
                 << "2- Mat2" << endl;
            cin >> choice;
            if(choice == 1)
                cin >> mat1;
            else if(choice == 2)
                cin >> mat2;
            else
                cout << "wrong input" << endl;
        }
        cout << "What do you want to do today ? " << endl
             << "1- Mat1 + Mat2 " << endl
             << "2- Mat1 - Mat2 " << endl
             << "3- Mat1 * Mat2 " << endl
             << "4- Mat1 + scaler " << endl
             << "5- Mat1 - scaler " << endl
             << "6- Mat1 * scaler " << endl
             << "7- Mat1 += Mat2" << endl
             << "8- Mat1 -= Mat2" << endl
             << "9- Mat1 ++ " << endl
             << "10- Mat1 --" << endl
             << "11- Print Mat1" << endl
             << "12- Mat1 == Mat2" << endl
             << "13- Mat1 != Mat2" << endl
             << "14- is Mat1 Square ? " << endl
             << "15- is Mat1 Symmetric ?" << endl
             << "16- is Mat1 identity ?" << endl
             << "17- Matrix transpose " << endl << endl;

             cin >> choice;

             if(choice == 1)                    // Mat1 + Mat2
                cout << mat1+mat2 << endl;

             else if(choice == 2)              // Mat1 - Mat2
                cout << mat1-mat2 << endl;

             else if(choice == 3)              // Mat1 * Mat2
             {
                 if(mat1.col == mat2.row)
                    cout << mat1*mat2 << endl;
                 else
                    cout << "Can't Multiply " << endl;
             }

             else if(choice == 4)             // Mat1 + scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 + scaler << endl;
             }

             else if(choice == 5)           // Mat1 - scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 - scaler << endl;
             }

             else if(choice == 6)          // Mat1 * scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 * scaler << endl;
             }

             else if(choice == 7)         // mat1 += mat2
                 cout << (mat1 += mat2) << endl;

             else if(choice == 8)        // mat1 -= mat2
                cout << (mat1 -= mat2) << endl;

             else if(choice == 9)       // mat1 ++
             {
                 ++mat1;
                 cout << mat1 << endl;
             }

             else if(choice == 10)     // mat1 --
             {
                 --mat1;
                 cout << mat1;
             }

             else if(choice == 11)     // Print mat1
                cout << mat1 << endl;

             else if(choice == 12)    // mat1 == mat2
                if(mat1 == mat2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

             else if( choice == 13)   // mat1 != mat2
                if(mat1 != mat2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 14)      // is Mat1 square
                if(mat1.isSquare()))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 15)         // is mat1 symmetric
                if(mat1.isSummetric())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 16)        // is mat1 Identity
                if(mat1.isIdentity())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 17)       // transpose mat1
                cout << mat1.transpose() << endl;

            else
                cout << "Wrong Input" << endl;



    }
    return 0;
}
