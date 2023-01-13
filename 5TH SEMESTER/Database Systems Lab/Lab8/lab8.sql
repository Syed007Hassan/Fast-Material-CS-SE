--LAB 8 
--K20-1052, S.M.HASSAN ALI

-- TASK 1

--set serveroutput on
--
--Declare
--
--Sec_Name varchar2(20):= 'Lab8';
--Course_Name varchar(20) := 'Database Systems Lab'; Begin
--dbms_output.put_line('This is : '|| Sec_Name||' and the courseis' || Course_Name);
--
--End;

--
-- TASK 2

set serveroutput on;
Declare 

 a integer:=20;
 b integer:=31;
 f real;
BEGIN

DBMS_OUTPUT.PUT_LINE('a+b ' || (a+b));
DBMS_OUTPUT.PUT_LINE('a+b/3 ' || (a+b)/3);
DBMS_OUTPUT.PUT_LINE('a*b ' || (a*b)/3);

END;



--
---- TASK 3
--
--set serveroutput on;
--
--Accept emp_id EMPLOYEES.EMPLOYEE_ID%type Prompt 'Enter your Employee_id: '
--
--Declare
--
--  emp_id EMPLOYEES.EMPLOYEE_ID%type;
--  emp_salary EMPLOYEES.SALARY%type;
--  bonus_amount REAL;
--
-- Begin
--
--  EMP_ID := &EMP_ID;
--  SELECT SALARY INTO emp_salary from EMPLOYEES WHERE EMPLOYEE_ID = emp_id;
--  if(emp_salary < 1000) THEN
--  bonus_amount := emp_salary * 0.1;
--  
--  ELSIF (emp_salary>=1000 AND emp_salary<=1500) THEN
--    bonus_amount := emp_salary*0.15;
--    
--  ELSE
--    bonus_amount := emp_salary*0.20;
--  dbms_output.put_line('Bonus Amount: ' || bonus_amount);
--
--End IF; 
--End;
--
--
---- TASK 4
--
--set serveroutput on;
--
--Accept emp_id EMPLOYEES.EMPLOYEE_ID%type Prompt 'Enter your Employee_id: '
--
--Declare
--
--   emp_id EMPLOYEES.EMPLOYEE_ID%type;
--   emp_com EMPLOYEES.COMMISSION_PCT%type;
--   emp_salary EMPLOYEES.SALARY%type;
-- 
--BEGIN
--   emp_id := &emp_id;
--  SELECT SALARY, COMMISSION_PCT INTO emp_salary, emp_com FROM EMPLOYEES WHERE EMPLOYEE_ID = emp_id;
--  
--  if(emp_com is null) THEN
--  Update Employees set Salary = emp_salary + emp_com where Employee_id = emp_id;
--  END IF;
--  
--  dbms_output.put_line('Salary Updated');
-- 
--END;
--
--
---- TASK 5
--
--set serveroutput on;
--
--Declare
--
--   dep_Name DEPARTMENTS.DEPARTMENT_NAME%type;
--   dep_id DEPARTMENTS.DEPARTMENT_ID%type := 30;
--
--Begin
--
--   Select Distinct D.DEPARTMENT_NAME INTO dep_Name 
--   From Employees E, Departments D
--   where (D.DEPARTMENT_ID = E.DEPARTMENT_ID) and (D.DEPARTMENT_ID = dep_id);
--
--   dbms_output.put_line('Department Name : ' || dep_name);
--
--End;
--
--
---- TASK 6
--
--SET SERVEROUTPUT ON;
--
--CREATE OR REPLACE PROCEDURE UPDATE_SALARY (emp_no in NUMBER)
--IS
--emp_salary EMPLOYEES.SALARY%TYPE;
--
--BEGIN
-- SELECT SALARY INTO emp_salary from Employees where employee_id = emp_no;
-- UPDATE EMPLOYEES SET SALARY = emp_salary + (emp_salary*0.10) WHERE EMPLOYEES_ID = emp_no;
-- dbms_output.put_line('Salary of the employee ' || emp_no || ' updated!');
--
--END;
--EXEC UPDATE_SALARY(100);
--
--
---- TASK 7
--
--SET SERVEROUTPUT ON;
--
--CREATE OR REPLACE PROCEDURE ADD_SALARY (DEP_NO IN NUMBER)
--IS
--emp_salary EMPLOYEES.SALARY%TYPE;
--
--BEGIN
-- for c in (Select Employee_id , Salary from EMPLOYEES WHERE DEPARTMENT_ID = dept_no)
-- LOOP 
--   IF(C.salary > 5000) THEN 
--    UPDATE EMPLOYEES SET SALARY = C.SALARY + 1000 WHERE EMPLOYEE_ID = C.EMPLOYEE_ID;
--    dbms_output.put_line('Salary of the employee ' || c.EMPLOYEE_ID || ' updated!');
--           END IF;
--    END LOOP;
--END;
--
--
---- TASK 8
--A)
--CREATE OR REPLACE VIEW EMP_DESIGNATION(JOB_ID, COUNT_EMPLOYEES)
--SELECT JOB_ID, COUNT(JOB_ID) AS COUNT_EMPLOYEES FROM EMPLOYEES GROUP BY JOB_ID;
--SELECT * FROM EMP_DESIGNATION; 
--
--B)
--CREATE OR REPLACE VIEW DISPLAY_EMPLOYEE(EMPLOYEE_ID, EMPLOYEE_NAME, DEPARTMENT_ID, DEPARTMENT_NAME)
--AS SELECT E.EMPLOYEE_ID, E.FIRST_NAME, E.DEPARTMENT_ID, D.DEPARTMENT_NAME
--FROM EMPLOYEES E, DEPARTMENTS D WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID AND lower(E.FIRST_NAME) <> 'king';
--SELECT * FROM DISPLAY_EMPLOYEE;
--
--C)
--CREATE OR REPLACE VIEW  DISPLAY_EMPLOYEES(EMPLOYEE_ID, EMP
LOYEE_NAME, DEPARTMENT_ID, DEPARTMENT_NAME)
--AS SELECT E.EMPLOYEE_ID, E.FIRST_NAME || ' ' || E.LAST_NAME AS empname, E.DEPARTMENT_ID, D.DEPARTMENT_NAME
--FROM EMPLOYEES E, DEPARTMENTS D WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID;
--SELECT * FROM DISPLAY_EMPLOYEES;
--
--
------ TASK 9
--
--set serveroutput on;
--DECLARE
--    N1 INTEGER;
--    N2 INTEGER;
--    N3 INTEGER;
--BEGIN
--    N1 := &N1;
--    N2 := &N2;
--    N3 := N1 + N2;
--    dbms_output.put_line('Total Sum: ' || N3);
--END;
--
--
--
------ TASK 10
--
--set serveroutput on;
--DECLARE
--  N1 INTEGER;
--  N2 INTEGER;
--  TOTAL INTEGER:=0;
--BEGIN 
--  N1:=&N1;
--  N2:=&N2;
--  FOR C IN N1 .. N1
--  LOOP
--     TOTAL:=TOTAL+C;
--  END LOOP;
--    dbms_output.put_line('Total Sum: ' || TOTAL);
--END;
--
------ TASK 11
--
--set serveroutput on;
--DECLARE
--    employee_no EMPLOYEES.EMPLOYEE_ID%type;
--    employee_name EMPLOYEES.FIRST_NAME%type;
--    employee_hire_date EMPLOYEES.HIRE_DATE%type;
--    employee_department_name DEPARTMENTS.DEPARTMENT_NAME%type;
--BEGIN
--    employee_no := &employee_no;
--    SELECT E.EMPLOYEE_ID, E.FIRST_NAME || ' ' || E.LAST_NAME,  E.HIRE_DATE, D.DEPARTMENT_NAME INTO employee_no, 
--    employee_name, employee_hire_date, employee_department_name
--    FROM EMPLOYEES E, DEPARTMENTS D WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID AND E.EMPLOYEE_ID = employee_no;
--    dbms_output.put_line('Employee Id: ' || employee_no || ' , Employee Name: ' || employee_name || ' , Hire Date: ' || employee_hire_date || ' ,Department Name: ' || employee_department_name);
--END;
--
--
------ TASK 12
--
--set serveroutput on;
--DECLARE
--    PALINDROMECHECK VARCHAR(20);
--    REVERSE_NUMBER VARCHAR(20);
--BEGIN 
--    PALINDROMECHECK := &PALINDROMECHECK;
--    --reverse function will directly reverse the string of numbers
--    SELECT REVERSE(PALINDROMECHECK) INTO REVERSE_NUMBER FROM DUAL;
--    IF(PALINDROMECHECK = REVERSE_NUMBER) THEN
--        dbms_output.put_line('The number ' ||PALINDROMECHECK|| ' is palindrome.');
--    ELSE
--        dbms_output.put_line('The number ' ||PALINDROMECHECK|| ' is not palindrome.');
--    END IF;
--END;
--
--
------ TASK 13
--
--set serveroutput on;
--DECLARE
--    emp_id  EMPLOYEES.EMPLOYEE_ID%type;
--    emp_first EMPLOYEES.FIRST_NAME%type;
--    emp_last EMPLOYEES.LAST_NAME%type;
--    emp_email EMPLOYEES.EMAIL%type;
--    emp_phone EMPLOYEES.PHONE_NUMBER%type;
--    emp_hire EMPLOYEES.HIRE_DATE%type;
--    emp_job_id EMPLOYEES.JOB_ID%type;
--    emp_salary EMPLOYEES.SALARY%type;
--    emp_comm EMPLOYEES.COMMISSION_PCT%type;
--    emp_manager_id EMPLOYEES.MANAGER_ID%type;
--    emp_depno EMPLOYEES.DEPARTMENT_ID%type;
--    emp_depart_name DEPARTMENTS.DEPARTMENT_NAME%type;
--    emp_location_id DEPARTMENTS.LOCATION_ID%type;
--BEGIN
--    emp_id := &emp_id;
--    emp_first := &emp_first;
--    emp_last := &emp_last;
--    emp_email := &emp_email;
--    emp_phone := &emp_phone;
--    emp_hire := &emp_hire;
--    emp_job_id := &emp_job_id;
--    emp_salary := &emp_salary;
--    emp_comm := &emp_comm;
--    emp_manager_id := &emp_manager_id;
--    emp_depno := &emp_depno;
--    emp_depart_name := &emp_depart_name;
--    emp_location_id := &emp_location_id;
--    INSERT INTO EMPLOYEES (employee_id,first_name,last_name,email,phone_number,hire_date,job_id,salary,commission_pct, manager_id,department_id) 
--        VALUES (emp_id,emp_first,emp_last,emp_email,emp_phone,emp_hire,emp_job_id,emp_salary,emp_comm,emp_manager_id,emp_depno)
--    INSERT INTO DEPARTMENTS(DEPARTMENT_ID, DEPARTMENT_NAME, MANAGER_ID, LOCATION_ID)
--        VALUES(emp_depno,emp_depart_name,emp_manager_id,emp_location_id);
--    dbms_output.put_line('Record for Employee # : '|| emp_id || ' entered!');
--END;
--
------ TASK 14
--
--set serveroutput on;
--DECLARE
--    emp_salary EMPLOYEES.SALARY%type:=0;
--    emp_first_name EMPLOYEES.FIRST_NAME%type;
--    emp_last_name EMPLOYEES.LAST_NAME%type;
--    emp_employee_id EMPLOYEES.EMPLOYEE_ID%type := 7499;
--    emp_manager_id EMPLOYEES.MANAGER_ID%type := 7499;
--BEGIN
--    SELECT MANAGER_ID INTO emp_manager_id FROM EMPLOYEES WHERE EMPLOYEE_ID = emp_employee_id;
--    WHILE(emp_salary <= 2500)
--    LOOP
--        SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, SALARY INTO emp_employee_id, emp_first_name, emp_last_name, emp_salary
--        FROM EMPLOYEES WHERE EMPLOYEE_ID = emp_employee_id;
--    END LOOP;
--    dbms_output.put_line('The Employe who is higher in chain of command: ' || emp_first_name || ' ' || emp_last_name || ' with salary: ' || emp_salary);
--EXCEPTION
--    WHEN NO_DATA_FOUND
--    THEN
--        dbms_output.put_line('Record with employee id: ' || emp_employee_id || ' does not exists.');
--END;
--
--
---- TASK 15
--
--set serveroutput on;
--DECLARE
--    i NUMBER := 1;
--    j NUMBER := 100;
--    SUM NUMBER := 0;
--BEGIN
--    FOR c in i .. j
--    LOOP
--        SUM :=SUM+c;
--    END LOOP;
--    dbms_output.put_line('Total Sum : ' || SUM);
--END;
--    
--    
--  



