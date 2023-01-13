
select FLOOR(MONTHS_BETWEEN(SYSDATE,'22-NOV-22')*30) from dual;

select sysdate from dual;


--Display any two columns from employees table
select EMPLOYEE_ID, FIRST_NAME FROM EMPLOYEES;

select employee_id as "empID" from employees;

select Sysdate from dual;


--Display Hire_date from employees table, name it as Joining Date
SELECT HIRE_DATE AS "JOINING DATE" FROM EMPLOYEES;

--Display the first_name, last_name of Employees together in one column named 'FULL NAME'
select FIRST_NAME || LAST_NAME AS "FULL NAME" FROM EMPLOYEES;

--List all Employees having annual salary greater 20, 000 and lesser than 30,000.
SELECT *FROM EMPLOYEES WHERE SALARY BETWEEN 20000 AND 30000;

--List employee_id and first_name of employees from department # 60 todepartment #100.
SELECT EMPLOYEE_ID, FIRST_NAME FROM EMPLOYEES WHERE DEPARTMENT_ID BETWEEN 60 AND 100;

--List all the Employees belonging to cities like Toronto, Hiroshima and Sydney.
SELECT FIRST_NAME,CITY from EMPLOYEES, LOCATIONS WHERE CITY IN('Toronto','Hiroshima','Sydney');

--List all the Employees having an ‘ll’ in their first_names.
SELECT *FROM EMPLOYEES WHERE FIRST_NAME LIKE '%ll%';

--List all the employees with no commission.
SELECT *from employees where COMMISSION_PCT is NULL;

--List all employees in order of their decreasing salaries.
select *from EMPLOYEES order by SALARY desc;

--Print an employee name (first letter capital) and job title (lower Case)
select INITCAP(FIRST_NAME), LOWER(JOB_ID) from EMPLOYEES;

--Display employee name and job title together, length of employee name and the
--numeric position of letter A in employee name, for all employees who are in sales.
--Hint: For finding position you need to use string function “instr()”, this function worked
--as INSTR(string1, string2)(s1:sreaching string, s2:string/char you’re searching for).

select FIRST_NAME || ' ' || ' ' || JOB_ID as "Name_AND_Job", 
LENGTH(FIRST_NAME),INSTR(FIRST_NAME,'A') from Employees 
WHERE JOB_ID like 'S%' AND JOB_ID like '_A%';

select first_name || ' ' || job_title as "People at Position" ,length(first_name),
instr(upper(first_name), 'A') AS "Position" from employees, departments, jobs 
where lower(department_name) like '%sales%';


--Comparing the hire dates for all employees who started in 2003, 
--display the employee number, hire date, and month started using the conversion and date functions.
select employee_id,HIRE_DATE, TO_CHAR(HIRE_DATE,'Month') from Employees
where HIRE_DATE BETWEEN '01-JAN-03' AND '31-DEC-03';

select employee_id, TO_CHAR(hire_date,'YYYY') from employees
where hire_date between '01-JAN-00' and '31-DEC-10';

--To display the employee number, the month number and year of hiring.
SELECT employee_id, TO_CHAR(HIRE_DATE,'MM, YYYY') FROM EMPLOYEES;

--To display the employee’s name and hire date for all employees. The hire date appears as 16 September, 2021.
select employee_id,to_char(HIRE_DATE,'DD Month YYYY') from employees;

--Display the salary of employee Neena with $ sign preceded.
select to_char(SALARY,'$99999') FROM EMPLOYEES WHERE FIRST_NAME = 'Neena';

--Find the next ‘Monday’ considering today’s date as date.
select NEXT_DAY(Sysdate,'Monday') from Employees;
SELECT NEXT_DAY(SYSDATE,'Saturday') from employees;

--List all Employees who have an ‘A’ in their last names.
select last_name from Employees where Last_name like '%a%';

--Show all employees’ last three letters of first name.
select substr(first_name,length(first_name)-2,length(first_name)), first_name from employees;
select substr('Hassan',length('Hassan')-4,length('Hassan')) from dual; 


--For all employees employed for more than 100 months, display the employee number,
--hire date, number of months employed, first Friday after hire date and last day of the month hired.
select employee_id, hire_date, MONTHS_BETWEEN(SYSDATE,hire_date),
Next_day(hire_date,'Friday'),Last_day(hire_date) from employees
where MONTHS_BETWEEN(SYSDATE,hire_date) > 100  ;

--To display the employee number, name, salary of employee before and after 15%
--increment in the yearly salary. Name the calculated new salary as “Incremented
--Salary”. Do calculate the difference between before and after salaries & name this 
--amount as “Incremented Amount”.
select employee_id,first_name, salary, salary+(salary*15)/100 as "Incremented Salary", 
(salary*15)/100 as "Incremented Amount" from employees;

--List the name, hire date, and day of the week (labeled DAY) on which job was
--started. Order the result by day of week starting with Monday.
select first_name || ' ' || last_name as "Name", 
hire_date, to_char(hire_date,'Day')
from employees order by mod(to_char(hire_date,'D')+5,7); 

--Display the department and manager id for all employees and round the commission up to 1 decimal.
select * from employees;
select department_id, manager_id, ROUND(COMMISSION_PCT,1) from employees;

--Write a query to find the list of employees whose COMMISSION_PCT>0 and they do
--not belong to DEPARTMENT_ID 90 or 100 from Employees table
select *from employees where Commission_pct > 0 And department_id != 90 OR department_id != 100;

--Write a query to find the employees who are hired in year 2010 from Employees table.
select *from employees where to_char(hire_date,'YYYY') = 2010;

--Write a query to find the list of jobs whose min salary is greater than 8000 and less than
--15,000 and commission = 0 from employee table.
select * from Employees where SALARY Between 8000 AND 15000 And commission_pct is null;

--Write a query to find employee whose ID are greater than 100 and less than 150 and
--their department_id is greater than 90 and less than 100 along with their first_name,
--Last_name & Job ID.
Select employee_id,first_name,last_name,job_id from employees where (employee_id between 100 AND 150) 
AND (department_id between 90 AND 100);

--Write a query to find total salary (Total salary formula = salary + (commission_pct*
--salary)) as “Total Salary”, commission_pct where commission_pct is not equal to null.
select (salary + (commission_pct*salary)) as "Total Salary" from EMPLOYEES where commission_pct is not NUll;

select substr(first_name,1,3) as "Jali naam", first_name from employees;
select  employee_id,count(employee_id) as "No of employees"
from employees
group by department_id; 


--JUST FOR PRACTICE

SELECT *FROM EMPLOYEES WHERE FIRST_NAME LIKE '%a%';

select ALL(FIRST_NAME) from EMPLOYEES;

SELECT *FROM LOCATIONS;

SELECT *FROM JOBS WHERE JOB_TITLE IN ('Sales Manager','Purchasing Manager');

select *from dual;

select abs(-1052), ceil(1052.5 - 1.4),floor(1052.5 + 4) from dual;

select LOWER('HASSAN') from dual;

SELECT INITCAP('hasan') from dual;

SELECT substr('hassan ali',0,5) from dual;

SELECT lpad('hassanali',12,'*') from dual;

SELECT sysdate from dual;

select next_day('03-SEP-22','Saturday') from dual;

select extract(Day from hire_date), hire_date from employees;

select to_date('3SEP22') from dual;

SELECT NVL('hassanali','*') from dual;

select DECODE (&a, &b, 'a-b equal', &d, 'a-d equal', 'FAIL') from dual;

SELECT AVG(SALARY) FROM EMPLOYEES;

SELECT SUM(SALARY) FROM EMPLOYEES;

SELECT COUNT(*) FROM EMPLOYEES;