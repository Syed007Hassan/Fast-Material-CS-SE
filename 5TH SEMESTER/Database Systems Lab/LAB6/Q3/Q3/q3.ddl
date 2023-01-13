CREATE TABLE Customers1
  (
    Customer_ID           INTEGER NOT NULL ,
    Name                  VARCHAR2 (4000) ,
    Product_Name          VARCHAR2 (4000) ,
    Quantity              INTEGER ,
    Address               VARCHAR2 (4000) ,
    Employees_Employee_ID INTEGER NOT NULL
  ) ;
ALTER TABLE Customers1 ADD CONSTRAINT Customers_PK PRIMARY KEY ( Customer_ID, Employees_Employee_ID ) ;


CREATE TABLE Employees1
  (
    Employee_ID INTEGER NOT NULL ,
    First_Name  VARCHAR2 (4000) ,
    Last_Name   VARCHAR2 (4000) ,
    Address     VARCHAR2 (4000)
  ) ;
ALTER TABLE Employees1 ADD CONSTRAINT Employees_PK PRIMARY KEY ( Employee_ID ) ;


CREATE TABLE Orders1
  (
    Order_no INTEGER NOT NULL ,
    Quantity              INTEGER ,
    Shipped_Date          DATE ,
    Recieved_Date         DATE ,
    Customers_Customer_ID INTEGER NOT NULL ,
    --  ERROR: Column name length exceeds maximum allowed length(30)
    Cus_Emp_Employee_ID INTEGER NOT NULL
  ) ;
ALTER TABLE Orders1 ADD CONSTRAINT Orders_PK PRIMARY KEY ( Order_no, Customers_Customer_ID, Cus_Emp_Employee_ID ) ;


CREATE TABLE Products
  (
    Product_ID INTEGER
    NOT NULL ,
    Name                  VARCHAR2 (4000) ,
    Price                 NUMBER (2) ,
    Stock                 INTEGER ,
    Employees_Employee_ID INTEGER NOT NULL
  ) ;
ALTER TABLE Products ADD CONSTRAINT Products_PK PRIMARY KEY ( Product_ID, Employees_Employee_ID ) ;


ALTER TABLE Customers1 ADD CONSTRAINT Customers_Employees_FK FOREIGN KEY ( Employees_Employee_ID ) REFERENCES Employees1 ( Employee_ID ) ;

ALTER TABLE Orders1 ADD CONSTRAINT Orders_Customers_FK FOREIGN KEY ( Customers_Customer_ID, Cus_Emp_Employee_ID ) REFERENCES Customers1 ( Customer_ID, Employees_Employee_ID ) ;

ALTER TABLE Products ADD CONSTRAINT Products_Employees_FK FOREIGN KEY ( Employees_Employee_ID ) REFERENCES Employees1 ( Employee_ID ) ;

insert into EMPLOYEES1 values (1,'aliyan','khan','fdgfdg');
insert into EMPLOYEES1 values (2,'Hassan','Ali','dfgfdg');
insert into EMPLOYEES1 values (3,'raza','ali','dfgdfg');

insert into CUSTOMERS1 values (1,'Ehtesham Zafar','Mobile',1,'abc street karachi',1);
insert into CUSTOMERS1 values (2,'Hassan Ali','Television',1,'def street karachi',1);
insert into CUSTOMERS1 values (3,'Furqan Fazal','Chocolate',5,'ijk street karachi',3);

insert into PRODUCTS values (1,'Mobile',34.00,10,2);
insert into PRODUCTS values (2,'Television',35.00,100,1);
insert into PRODUCTS values (1,'Chocolate',4.00,100,3);

insert into ORDERS1 values (1,2,'05-aug-2022','05-aug-2022',2,1);
insert into ORDERS1 values (2,4,'05-aug-2022','05-aug-2022',2,1);
insert into ORDERS1 values (3,1,'05-aug-2022','05-aug-2022',2,1);
