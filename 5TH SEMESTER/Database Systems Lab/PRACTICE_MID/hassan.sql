




select  * from JOBS where JOB_TITLE like '%M%';


select job_id from jobs where JOB_ID = 111;


select Greatest(3,5,7) from dual;

SELECT * FROM BOOKS;

ALTER TABLE BOOKS 
ADD (BOOK_AMOUNT INT );

ALTER TABLE BOOKS ADD CHECK (BOOKS_ID > 0);
ALTER TABLE BOOKS MODIFY BOOK_AMOUNT DEFAULT 200;


INSERT INTO BOOKS VALUES(1,'Harry potter','Jk Rolling','Av',23);


CREATE TABLE BORROWED_BY(

 BOOKS_ID INT ,
 MEMBER_ID INT,
 START_DATE DATE,
 RETURN_DATE DATE,
 DUE_DATE DATE,
  CONSTRAINT BOOKIDFK FOREIGN KEY (BOOKS_ID) REFERENCES BOOKS(BOOKS_ID)
 );

DROP TABLE BORROWED_BY;

CREATE TABLE MEMBERS(

  MEMBER_ID INT,
  MEMBER_NAME VARCHAR(25),
  MEMBER_ADDRESS VARCHAR(50),
  MEMBER_EXPIRYDATE DATE,
  MEMBER_STARTDATE DATE,
  CONSTRAINT MEMBERIDPK PRIMARY KEY (MEMBER_ID)
  
);

ALTER TABLE BORROWED_BY 
ADD CONSTRAINT MEMBERIDFK FOREIGN KEY (MEMBER_ID) REFERENCES MEMBERS(MEMBER_ID);


ALTER TABLE BORROWED_BY 
ADD CONSTRAINT BOOKID_MEMBERID PRIMARY KEY (BOOKS_ID,MEMBER_ID);


ALTER TABLE BORROWED_BY
DROP CONSTRAINT BOOKID_MEMBERID;


ALTER TABLE BORROWED_BY
DROP CONSTRAINT MEMBERIDFK;
