#include<iostream>
using namespace std;



int main(){


int rows;
    
	cout << "Enter no of rows of array: ";
    cin  >> rows;
    int *numbers = new int[rows]; /// array to store no of columns
    int **array=new int*[rows];   /// jagged array

    for(int i=0; i<rows; i++){

        cout<< "Enter no of col in row"<< i<< ": ";
        cin>> numbers[i];
        array[i]=new int[numbers[i]];
    }

    for(int i=0; i<rows; i++){

        for(int j=0; j< numbers[i]; j++){

            cout<<"Rows "<< i<<": Enter value"<< i*numbers[i]+j <<": ";
            cin>> array[i][j];
        }
    }
    cout<< "Showing all the Inputed data in a matrix form"<< endl;
    for(int i=0; i< rows ; i++){

        for(int j=0; j< numbers[i]; j++){
            cout<< array[i][j]<< " ";

        }
        cout<< "\n";
    }
    
    cout<< "Dellocating the array..."<< endl;
    for(int i=0; i<rows; i++){
       delete [] array[i];

    }
    delete [] array;
    cout<< "done!";
    
}
