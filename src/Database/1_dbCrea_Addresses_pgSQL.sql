CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE ADDRESSES
(
ID SERIAL,
CLIENT_ID INTEGER NOT NULL,
CONTACT VARCHAR(30) NOT NULL,
STREET VARCHAR(50) NOT NULL,
NUMBER VARCHAR(4),
COMPLEMENTARYLINE VARCHAR(50) NOT NULL,
CITY VARCHAR(40) NOT NULL,
ZIPCODE VARCHAR(9),
COUNTRY VARCHAR(30) NOT NULL,
PHONE VARCHAR(13),
CONSTRAINT PK_ADDRESSES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_ADDRESSES_CONTACTADDRESS UNIQUE (CONTACT,STREET,NUMBER,CITY,COUNTRY),
CONSTRAINT CK_VAL_ADDRESSES_PHONE CHECK (PHONE SIMILAR TO '[\+|00][[1-9]]{3}[[:DIGIT:]]{8}')
);


 COMMIT;
