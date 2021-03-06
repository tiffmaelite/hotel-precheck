CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE BALANCELOG
(
YEARLOG INT,
MONTHLOG INT,
DAYLOG INT,
HOURLOG INT,
BALANCE FLOAT,
CONSTRAINT PK_BALANCELOG_DATE PRIMARY KEY (YEARLOG, MONTHLOG, DAYLOG, HOURLOG)
);


CREATE TABLE YEARLYBALCOUNT
(
CREATIONTIME TIMESTAMP,
YEARLOG INT,
BALANCE FLOAT,
CONSTRAINT PK_YEARLYBALCOUNT_CREATION PRIMARY KEY (CREATIONTIME)
);

CREATE TABLE MONTHLYBALCOUNT
(
CREATIONTIME TIMESTAMP,
YEARLOG INT,
MONTHLOG INT,
BALANCE FLOAT,
CONSTRAINT PK_MONTHLYBALCOUNT_CREATION PRIMARY KEY (CREATIONTIME)
);


CREATE TABLE DAYLYBALCOUNT
(
CREATIONTIME TIMESTAMP,
YEARLOG INT,
MONTHLOG INT,
DAYLOG INT,
BALANCE FLOAT,
CONSTRAINT PK_DAYLYBALCOUNT_CREATION PRIMARY KEY (CREATIONTIME)
);


CREATE TABLE HOURLYBALCOUNT
(
CREATIONTIME TIMESTAMP,
YEARLOG INT,
MONTHLOG INT,
DAYLOG INT,
HOURLOG INT,
BALANCE FLOAT,
CONSTRAINT PK_HOURLYBALCOUNT_CREATION PRIMARY KEY (CREATIONTIME)
);


COMMIT;
