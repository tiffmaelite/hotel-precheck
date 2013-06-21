CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

ALTER TABLE SERVICESTYPES
ADD CONSTRAINT FK_SERVICESTYPES_TAXES	FOREIGN KEY (VAT_ID) REFERENCES TAXES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_SERVICESTYPES_FAMILY	FOREIGN KEY (SERVICEFAMILY_ID) REFERENCES SERVICESFAMILIES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;;

ALTER TABLE SERVICES
ADD CONSTRAINT FK_SERVICES_TYPE	FOREIGN KEY (SERVICETYPE_ID) REFERENCES SERVICESTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE ROOMS
ADD CONSTRAINT FK_ROOMS_TYPE	FOREIGN KEY (ROOMTYPE_ID) REFERENCES ROOMSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE GROUPS
ADD CONSTRAINT FK_GROUPS_CONTACTCLIENT FOREIGN KEY (CONTACT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE CLIENTS
ADD CONSTRAINT FK_CLIENTS_ADDRESS FOREIGN KEY (HOMEADDRESS_ID) REFERENCES ADDRESSES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CLIENTS_NATIONALITY FOREIGN KEY (NATIONALITY_ID) REFERENCES NATIONALITIES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE CHARGEDSERVICES
ADD CONSTRAINT FK_CHARGEDSERVICES_USER FOREIGN KEY (RECEPTIONIST_ID) REFERENCES USERS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CHARGEDSERVICES_SERVICE FOREIGN KEY (SERVICE_ID) REFERENCES SERVICES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CHARGEDSERVICES_BILL FOREIGN KEY (BILL_ID) REFERENCES BILLS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLS
ADD CONSTRAINT FK_BILLS_BILLING FOREIGN KEY (BILLING_ID) REFERENCES BILLINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLS_TYPE FOREIGN KEY (BILLTYPE_ID) REFERENCES BILLSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLINGSGROUPS
ADD CONSTRAINT FK_BILLINGSGR_BILLINGSID FOREIGN KEY (BILLING_ID) REFERENCES BILLINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGSGR_GROUP FOREIGN KEY (GROUP_ID) REFERENCES GROUPS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLINGSCLIENTS
ADD CONSTRAINT FK_BILLINGSCL_BILLINGSID FOREIGN KEY (BILLING_ID) REFERENCES BILLINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGSCL_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE ROOMSOCCUPATIONS
ADD CONSTRAINT FK_ROOMSOCC_ROOM FOREIGN KEY (ROOM_ID) REFERENCES ROOMS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_ROOMSOCC_BILLINGSID FOREIGN KEY (BILLING_ID) REFERENCES BILLINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLINGS
ADD CONSTRAINT FK_BILLINGS_ADDRESS FOREIGN KEY (BILLINGADDRESS_ID) REFERENCES ADDRESSES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_TYPE FOREIGN KEY (BILLINGSTYPE_ID) REFERENCES BILLINGSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_BOOKING FOREIGN KEY (BOOKING_ID) REFERENCES BOOKINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BOOKINGS
ADD CONSTRAINT FK_BOOKINGS_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BOOKINGS_ROOMTYPE FOREIGN KEY (ROOMTYPE_ID) REFERENCES ROOMSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE ADDRESSES
ADD CONSTRAINT FK_ADDRESSES_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

COMMIT;