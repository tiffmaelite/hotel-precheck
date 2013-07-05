CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE TRAINEES
(
ID SERIAL,
LOGIN VARCHAR(20) NOT NULL,
ENCRYPTEDPASS VARCHAR(255) NOT NULL,
CONSTRAINT PK_TRAINEES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_TRAINEES_LOGIN UNIQUE (LOGIN)
);


 COMMIT;
