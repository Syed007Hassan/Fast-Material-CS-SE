--Create table emp20 (id number, name varchar(20), age number, address varchar(20), salaray number);
--
--
--
--create or replace trigger emp20_trigger
--before delete or insert or update on emp20
--for each row 
--declare 
--new_sal number;
--begin
--new_sal := :new.salaray - :old.salaray;
--dbms_output.put_line('');
--dbms_output.put_line('Old Salary ' || :old.salaray);
--dbms_output.put_line('New Slaray ' || :new.salaray);
--dbms_output.put_line('Difference ' || new_sal);
--dbms_output.put_line('');
--end;
--
--
--
--Insert into emp20(id, name, age, address, salaray)
--Select 1, 'Adams', 25, 'South Wales', 2400 from dual union all
--Select 2, 'James', 23, 'Orlando', 2100 from dual union all
--Select 3, 'Leena', 27, 'Vatican City', 2900 from dual union all
--Select 4, 'John', 29, 'North Hampshire', 3100 from dual union all
--Select 5, 'Nancy', 24, 'Dublin', 2500 from dual union all
--Select 5, 'Sarah', 22, 'Dublin', 2700 from dual;
--
--
--set serveroutput on;
--insert into emp20 values(8,'bari',25,'India',3900);
--
--set serveroutput on;
--update emp20 set salaray = 55000
--where id = 8;
--(8,'bari',25,'India',5500);



CREATE TABLE Person (
ID int NOT NULL,
Name varchar (50) NOT NULL,
PreviousName varchar (50) NULL,
SameNameCount int NULL,
CONSTRAINT pk_Person PRIMARY KEY (ID));

--1--------------------------------------
--CREATE OR REPLACE TRIGGER update_previous_name
--BEFORE UPDATE ON Person
--FOR EACH ROW
--BEGIN
--	:new.PreviousName := :old.Name;
--	dbms_output.put_line('');
--	dbms_output.put_line('Old Name was ' || :old.PreviousName);
--	dbms_output.put_line('New Name is ' || :new.Name);
--	dbms_output.put_line('');
--END;
----

ALTER TRIGGER UPDATE_PREVIOUS_NAME ENABLE;

INSERT INTO Person (ID, Name) values (1, 'Hassan');
INSERT INTO Person (ID, Name) values (3, 'Ali');

UPDATE Person SET Name = 'Syed Hassan' WHERE ID = 1;
SELECT * FROM Person;

--2-----------------------------------
--CREATE OR REPLACE TRIGGER set_same_name_count
--AFTER INSERT OR DELETE OR UPDATE OF Name
--ON Person
--BEGIN
--	UPDATE Person A SET SameNameCount = (SELECT COUNT(*) FROM Person WHERE NAME = A.Name);
--END;
--
--INSERT INTO Person (ID, Name) values (2, 'Ali');
--
--SELECT * FROM Person;
--
--
--
--
--
--insert into emp20 values(8,'bari',25,'India',3900);


