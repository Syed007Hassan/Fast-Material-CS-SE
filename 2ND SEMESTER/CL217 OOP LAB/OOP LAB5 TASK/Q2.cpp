#include <iostream>

using namespace std;

class Student{
	private:
		int scores[5];
	public:
		input() {
			int i,j,sc,k=1;
			
			for(i=0;i<5;i++)
			{
				cout << "\nEnter the score of student " << k++ << ": ";
				cin >> sc;
				scores[i]=sc; 
			}
		}
		
		calculateTotalScore() {
			int i,tot=0;
			
			for(i=0;i<5;i++) {
				tot=tot+scores[i];
			}
			
			cout << "\n\nTotal Score = " << tot;
		}
};

main()
{
	Student s;
	s.input();
	s.calculateTotalScore();
}
