#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

    struct menuItemType
{
     string menuItem;
     float menuPrice;
};

    int main(){
    cout << "\t\tWelcome to Johnny's Restaurant";

     int a[8]= {0,0,0,0,0,0,0,0},choice,qty;
     char ques;
     double total, tax, gross;

     menuItemType menuList[8];
     menuList[0].menuItem = "Plain Egg";
     menuList[0].menuPrice = 1.45;
     menuList[1].menuItem = "Bacon and Egg";
     menuList[1].menuPrice = 2.45;
     menuList[2].menuItem = "Muffin";
     menuList[2].menuPrice = 0.99;
     menuList[3].menuItem = "French Toast";
     menuList[3].menuPrice = 1.99;
     menuList[4].menuItem = "Fruit Basket";
     menuList[4].menuPrice = 2.49;
     menuList[5].menuItem = "Cereal";
     menuList[5].menuPrice = 0.69;
     menuList[6].menuItem = "Coffee";
     menuList[6].menuPrice = 0.50;
     menuList[7].menuItem = "Tea";
     menuList[7].menuPrice = 0.75;
   
     cout << endl << endl << "Breakfast items offered by the restaurant are" << endl;
     cout << 1 << "\t" << menuList[0].menuItem << setw(12) << "$. " << menuList[0].menuPrice << endl;
     cout << 2 << "\t" << menuList[1].menuItem << setw(8) << "$. " << menuList[1].menuPrice << endl;
     cout << 3 << "\t" << menuList[2].menuItem << setw(15) << "$. " << menuList[2].menuPrice << endl;
     cout << 4 << "\t" << menuList[3].menuItem << setw(9) << "$. " << menuList[3].menuPrice << endl;
     cout << 5 << "\t" << menuList[4].menuItem << setw(9) << "$. " << menuList[4].menuPrice << endl;
     cout << 6 << "\t" << menuList[5].menuItem << setw(15) << "$. " << menuList[5].menuPrice << endl;
     cout << 7 << "\t" << menuList[6].menuItem << setw(15) << "$. " << menuList[6].menuPrice << endl;
     cout << 8 << "\t" << menuList[7].menuItem << setw(18) << "$. " << menuList[7].menuPrice << endl;
   
   do{
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl << "Enter the Quantity: ";
        cin >> qty;
       
        switch(choice){
        case 1:
            {
                a[0] = a[0] + qty;
                cout << "You have Selected :" << menuList[0].menuItem << endl;
            break;
            }
            case 2:
            {
                a[1] = a[1] + qty;
                cout << "You have Selected: " << menuList[1].menuItem << endl;
            break;
            }
            case 3:
            {
                a[2] = a[2] + qty;
                cout << "You have Selected: " << menuList[2].menuItem << endl;
            break;
            }
            case 4:
            {
                a[3] = a[3] + qty;
                cout << "You have Selected: " << menuList[3].menuItem << endl;
            break;
            }
            case 5:
            {
                a[4] = a[4] + qty;
                cout << "You have Selected: " << menuList[4].menuItem << endl;
            break;
            }
            case 6:
            {
                a[5] = a[5] + qty;
                cout << "You have Selected: " << menuList[5].menuItem << endl;
            break;
            }
            case 7:
            {
                a[6] = a[6] + qty;
            cout << "You have Selected: " << menuList[6].menuItem << endl;
            break;
            }
            case 8:
            {
                a[7] = a[7] + qty;
            cout << "You have Selected: " << menuList[7].menuItem << endl;
            break;
            }
            default:
            cout << "invalid input" << endl;
        }
        cout << endl << "Enter (y/n) to select more items: ";
        cin >> ques;
        } while (ques != 'n');

      cout << "\n\n" << "********RECIPT********\n" << endl;
      for (int i = 0; i < 8; i++){
          if (a[i] > 0){
               cout << a[i] << "\t" << menuList[i].menuItem << " " << menuList[i].menuPrice << "$"<< endl;
               total = total + (menuList[i].menuPrice*a[i]); }
			   }

           tax = total*0.05;
           gross = total + tax;
           cout << "\tTax " << "\t" << tax << "$" << endl;
          cout << "***********************************************" << endl;
          cout << "Total Amount is  " << fixed << setprecision(2) << gross << "$" << endl;
          cout << "***********************************************";

         return 0;
}
