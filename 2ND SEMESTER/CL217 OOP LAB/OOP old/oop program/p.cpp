
#include <iostream> 
#include <string> 
using namespace std; 
 
class Package // Base Class
{ 
private: // data members 
	string name, city, state, sender, recipient; 
    int zip; 
    string address; 
    float weight;  // in ounce 
    double cost;  // per ounce 
                     
public: //member functions 
    void setName(string name); 
    void setCity(string city); 
    void setState(string state); 
    void setZip(int zip); 
    void setAddress(string address); 
    void setSender(string sender); 
    void setRecipient(string recipient); 
    string getName()
	{ 
		return name;
	} 
    string getCity()
	{
		return city;
	} 
    string getState()
	{
		return state;
	} 
	int getZip()
	{
		return zip;
	} 
	string getAddress()
	{
		return address;
	} 
	
	string getSender()
	{
		return sender;
	} 
	string getRecipient()
	{
		return recipient;
	} 
                                
double calculateCost(float weight,double costPerOunce) //function that calculate the cost z 
{  
	double z;  //total cost = weight*cost per ounce 
    z = weight * costPerOunce;  //the cost z 
                                  
    cout<< "The Base Cost = " <<z << endl<<endl; 
    return z; 
}
}; // end class Package
 
void Package::setName(string n)
{
	name = n; 
} 
                                                    
void Package::setCity(string c)
{
	city = c;
} 
void Package::setState(string s)
{
	state = s;
} 
void Package::setZip (int zp)
{
	zip = zp;
} 
void Package::setAddress(string adr)
{
	address = adr; 
} 
void Package::setSender(string sen) 
{
	sender = sen;   
}  
void Package::setRecipient(string rec)   
{
	recipient = rec;                                             
}                                         
          
class TwoDayPackage: public Package // derived class
{     
public:
	double calcShippingCost(float weight, double costPerOunce, double flatFee) 
		/* function that calculate shipping cost by adding the flat fee to the weight-based cost 
		calculated by base class Package’s calculateCost function*/ 
	{
		double z; //shippingcost of Two day Package class
		
		z= calculateCost(weight,costPerOunce) + flatFee;  
		cout<< "The TwoDayPackage Cost = " <<z << endl;
		return z;
	}
private:
	double flatFee;
}; // end TwoDayPackage
 
class OvernightPackage: public Package //derived class that adds the additional fee per ounce
{
public:
	double calcCostOvernight(float weight,double costPerOunce,double additionalCost )
	{
		double z; //shippingcost of overnight class
		z = calculateCost(weight, costPerOunce)+(additionalCost * weight);
		
		cout<< "The OvernightPackage Cost = " <<z << endl;
		return z;
	}
private:
	double overnightCost; //per ounce 
}; // end class OvernightPackage
 
int main()
{
	int i;  //i represent the user`s choice number
	string customerName,customerAddress,city,state,senderAddress,recipientAddress; 
    float packageWeight; 
    string customerCity; 
    double costPerOunce; 
    double flatFee; 
    double additionalCost; 
    string customerState; 
    int customerZipcode;
	
	Package base;   //the object base of the package class 
    TwoDayPackage twoday;  //the object twoday of the first inhereted calss 
    OvernightPackage overnight;   //the object overnight of the second inhereted calss   
 
    cout<<"    *****Welcome To The American Package Delievery Services*****"<<endl<<endl; 
    cout<<"Please Fill In The Requested Data Follow:        "<<endl<<"-----------------------------------------"<<endl<<endl;; 
         
    cout<<"Enter Customer Name "<<endl<<endl; 
    cin>>customerName; 
    cout<<endl; 
    base.setName(customerName);  //call function setName 
         
    cout<<"Enter Customer Address"<<endl<<endl; 
    cin>>customerAddress; 
    cout<<endl; 
    base.setAddress(customerAddress); 
 
    cout<<"Enter Customer City"<<endl<<endl; 
    cin>>customerCity; 
    cout<<endl; 
    base.setCity(customerCity); 
         
    cout<<"Enter Customer State"<<endl<<endl; 
    cin>>customerState; 
    cout<<endl; 
    base.setState(customerState); 
         
    cout<<"Enter Customer ZIP code"<<endl<<endl; 
    cin>>customerZipcode; 
    cout<<endl; 
    base.setZip(customerZipcode); 
         
    cout<<"Enter Weight"<<endl; 
    cin>>packageWeight; 
    cout<<endl; 
    cout<<"Enter Cost Per Ounce"<<endl; 
    cin>>costPerOunce; 
    cout<<endl; 
         
    cout<<"Please Enter Your Choice From The Menu Below:"<<endl<<endl; 
    cout<<"   1- Calculate Base Cost  "<<endl<<endl; 
    cout<<"   2- Calculate Two Day Cost "<<endl<<endl; 
    cout<<"   3- Calculate Over Night Cost"<<endl<<endl; 
    cin>>i; 
    cout<<endl;  //i represent customer choice
	
	switch (i)
	{
	case 1 :
		base.calculateCost(packageWeight,costPerOunce);
		break;
	
	case 2 : 
		cout<<"Enter Flat Cost"<<endl<<endl;  //additonal(to weight and cost) needed information  
        cin>>flatFee;
		twoday.calcShippingCost(packageWeight,costPerOunce,flatFee); 
        break;
	
	case 3 : 
		cout<<"Enter The Additional Cost"<<endl<<endl; 
        cin>>additionalCost; 
        overnight.calcCostOvernight(packageWeight,costPerOunce,additionalCost); 
        break;
	
	default:
		cout<<"INVALID CHOICE....Please Enter ur Choice Number From 1-->3 "<<endl;
	} // end switch
	
	cout<<"Enter sender address "<<endl<<endl; 
    cin>>senderAddress; 
    cout<<endl; 
    base.setSender( senderAddress); 
         
    cout<<"Enter ricipent address"<<endl<<endl; 
    cin>>recipientAddress; 
    cout<<endl; 
    base.setRecipient(recipientAddress);    
         
    cout<<"address from:"<< senderAddress<<endl; 
    cout<<"To:"<<recipientAddress<<endl;
	
	system ("pause");
	return 0;
}
