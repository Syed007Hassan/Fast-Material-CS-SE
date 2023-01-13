#include<iostream>
#include<string>
#include <iomanip>

using namespace std;



	struct menuItemType
	{
	    string menuItem;
	    double menuPrice;
	};
   
   
        menuItemType menu[8];
        void input(); //prototype of a function to loads data about the items in struct
        void output(); // prototype of a function show the loaded data
        void selectItems(); //prototype of a function  to select the items
        void cal(); //prototype of a function to calculate the bill
        int c[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

int main()
{
	   menuItemType menu[8];
       double t;
       input(); 
       output();
       selectItems(); 
       cal(); 
       return 0;

}
    void input(){
       menu[1].menuItem = "Plain Egg";
       menu[1].menuPrice = 1.45;
       menu[2].menuItem = "Bacon and Egg";
       menu[2].menuPrice = 2.45;
       menu[3].menuItem = "Muffin";
       menu[3].menuPrice = 0.99;
       menu[4].menuItem = "French Toast";
       menu[4].menuPrice = 1.99;
       menu[5].menuItem = "Fruit Basket";
       menu[5].menuPrice = 2.49;
       menu[6].menuItem = "Coffee";
       menu[6].menuPrice = 0.69;
       menu[7].menuItem = "Tea";
       menu[7].menuPrice = 0.75;

}
    void output(){
       cout << "*******Welcome to Johnny's Restaurant*******" << endl;
       cout << 1 << "\t" << menu[1].menuItem << setw(12) << "$ " << menu[1].menuPrice << endl;
       cout << 2 << "\t" << menu[2].menuItem << setw(8) << "$ " << menu[2].menuPrice << endl;
       cout << 3 << "\t" << menu[3].menuItem << setw(14) << "$ " << menu[3].menuPrice << endl;
       cout << 4 << "\t" << menu[4].menuItem << setw(9) << "$ " << menu[4].menuPrice << endl;
       cout << 5 << "\t" << menu[5].menuItem << setw(9) << "$ " << menu[5].menuPrice << endl;
       cout << 6 << "\t" << menu[6].menuItem<< setw(15) << "$ " << menu[6].menuPrice << endl;
       cout << 7 << "\t" << menu[7].menuItem << setw(18) << "$ " << menu[7].menuPrice << endl;

}
void selectItems() 
{
       int choice,quantity;
       char nn;
       do{
              cout << "Enter your choice :";
              cin >> choice;
              cout << "Enter the Quantity :";
              cin >> quantity;
              switch (choice)
              {
              case 1:
              {
                     c[1] = c[1] + quantity;
                     cout << "You have Selected :" << menu[1].menuItem << endl;

                     break;
              }
              case 2:
              {
                     c[2] = c[2] + quantity;
                     cout << "You have Selected :" << menu[2].menuItem << endl;

                     break;
              }
              case 3:
              {
                     c[3] = c[3] + quantity;
                     cout << "You have Selected :" << menu[3].menuItem<< endl;

                     break;
              }
              case 4:
              {
                     c[4] = c[4] + quantity;
                     cout << "You have Selected :" << menu[4].menuItem << endl;

                     break;
              }
              case 5:
              {
                     c[5] = c[5] + quantity;
                     cout << "You have Selected :" << menu[5].menuItem << endl;

                     break;
              }
              case 6:
              {
                     c[6] = c[6] + quantity;
                     cout << "You have Selected :" << menu[6].menuItem << endl;

                     break;
              }
              case 7:
              {
                     c[7] = c[7] + quantity;
                     cout << "You have Selected :" << menu[7].menuItem << endl;


                     break;
              }
              default:
                     cout << "invalid input" << endl;
              }
              cout << "to select more items (y/n)";
              cin >> nn;


       } while (nn != 'n');
       cout << endl;
}
    void cal(){
       
	   double total = 0, tax, due;
       cout << "*******Welcome to Johnny's Restaurant*******" << endl;
       for (int i = 1; i < 8; i++)
       {
              if (c[i] > 0)
              {
                     cout << c[i] <<"- "<<menu[i].menuItem << " =     $ " << menu[i].menuPrice << endl;
                     total = total + (menu[i].menuPrice*c[i]);
              }

       }
       tax = total*0.17; 
       due = total + tax; 
       cout << "        Tax " << "\t" << tax << endl;
       cout << "-----------------------------------------------" << endl;
       cout << "Amount due      $" << due << endl;
       cout << "-----------------------------------------------" << endl;


}
