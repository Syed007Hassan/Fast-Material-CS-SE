--1
select * from Employees;

--2
select MIN_SALARY,MAX_SALARY from Jobs
where JOB_TITLE = 'President';

--3
select * from EMPLOYEES
where salary = 20000;

--4
select *from EMPLOYEES
where salary >= 15000;

--5
select EMPLOYEE_ID, FIRST_NAME, LAST_NAME, DEPARTMENT_ID from Employees
where LAST_NAME = 'King';

--6
select EMPLOYEE_ID, FIRST_NAME, LAST_NAME, DEPARTMENT_ID from EMPLOYEES
where DEPARTMENT_ID = '50';

--7
select PHONE_NUMBER from EMPLOYEES
WHERE DEPARTMENT_ID = '80' AND MANAGER_ID='100';

--8
select * from EMPLOYEES
WHERE FIRST_NAME = 'John' OR FIRST_NAME = 'Neena' OR FIRST_NAME = 'Lency'; 

--9 
select CITY from LOCATIONS
where COUNTRY_ID = 'IT';

--10
select City from LOCATIONS
where COUNTRY_ID != 'IN' AND COUNTRY_ID != 'CH';  

--11
select * from Jobs
where MIN_SALARY >= 8000 AND MIN_SALARY < 15000; 

--12
SELECT PHONE_NUMBER from EMPLOYEES 
WHERE DEPARTMENT_ID = 90 AND JOB_ID != 'IT_PROG';

--13
select * from EMPLOYEES
where HIRE_DATE > '12-Dec-07';

--14
select * from EMPLOYEES
where HIRE_DATE > '12-Dec-07' AND DEPARTMENT_ID = 100;

--15
select * from EMPLOYEES
where HIRE_DATE > '12-Dec-07' AND DEPARTMENT_ID != 100;



