CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '1L+D', '1 lit en 80x200 + 1 douche', 100, 120);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '1GL+D', '1 lit en 160x200 + 1 douche', 120, 150);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '1pGL+D', '1 lit en 140x190 ou en 140x200 + 1 douche', 135, 145);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '2L+D', '2 lits en 80x200 + 1 douche', 150, 165);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '2L+B', '2 lits en 80x200 + 1 baignoire', 150, 165);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '2Lc+D', '2 lits en 90x200 + 1 douche', 160, 180);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '2Lc+B', '2 lits en 90x200 + 1 baignoire', 160, 180);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, 'Junior Suite', '2 lits en 90x200 ou 1 lit 140x200 + 1 baignoire', 170, 195);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '3L+B', '3 lits en 80x200 + 1 baignoire', 175, 200);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '2L+1pGL+B', '2 lits en 80x200 + 1 lit 140x200 + 1 baignoire', 185, 215);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, '3L+1pGL+B', '3 lits en 80x200 + 1 lit 140x200 + 1 baignoire', 195, 255);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, 'appartement', '', 300, 300);
INSERT INTO ROOMSTYPES(ID, LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(0, 'studio', '', 350, 350);

COMMIT;

INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 1, 309, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 1, 509, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 1, 710, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 1, 711, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 1, 712, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 3, 308, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 3, 307, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 3, 407, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 3, 507, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 3, 607, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 2, 707, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 2, 605, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 2, 207, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 201, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 202, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 203, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 205, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 206, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 301, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 302, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 303, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 305, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 306, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 8, 310, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 7, 311, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 401, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 402, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 403, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 405, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 406, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 5, 408, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 5, 411, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 501, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 502, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 503, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 505, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 506, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 5, 508, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 601, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 602, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 603, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 606, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 701, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 705, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 706, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 4, 708, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 8, 510, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 7, 511, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 7, 704, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 9, 304, 3);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 9, 504, 5);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 9, 604, 6);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 10, 204, 2);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 10, 404, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 12, 410, 4);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 12, 702, 7);
INSERT INTO ROOMS(ID, ROOMTYPE_ID, NUMBER, FLOOR) VALUES(0, 13, 132, 7);

COMMIT;

INSERT INTO TAXES(ID, LABEL, PERCENTAGE, STARTDATE, ENDDATE) VALUES(0,'0%',0.0,null,null);
INSERT INTO TAXES(ID, LABEL, PERCENTAGE, STARTDATE, ENDDATE) VALUES(0,'3,8%',3.8,null,null);

INSERT INTO SERVICESFAMILIES(ID, LABEL) VALUES(0,'Arrangement');
INSERT INTO SERVICESFAMILIES(ID, LABEL) VALUES(0,'Repas');
INSERT INTO SERVICESFAMILIES(ID, LABEL) VALUES(0,'Prestations');

INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Autre',3,1, '1');
INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Taxe de séjour',1,1, '1');
INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Accomodation',1,1, '1');
INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Repas',2,1, '1');
INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Prestation extra',3,1, '1');
INSERT INTO SERVICESTYPES(ID, LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(0,'Vente au comptant',3,1, '0');

COMMIT;

INSERT INTO SERVICESFIELDS(ID, LABEL, SQLTYPE) VALUES(0,'DISPLAYEDNAME','VARCHAR(100)');
INSERT INTO SERVICESFIELDS(ID, LABEL, SQLTYPE) VALUES(0,'PRINTEDNAME','VARCHAR(100)');
INSERT INTO SERVICESFIELDS(ID, LABEL, SQLTYPE) VALUES(0,'PRICEMIN','FLOAT');
INSERT INTO SERVICESFIELDS(ID, LABEL, SQLTYPE) VALUES(0,'PRICEMAX','FLOAT');

COMMIT;
ALTER SEQUENCE SEQ_SERVICES_ID RESTART WITH -1;
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,1, 'Autre...', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,1, 'Autre', '1');
ALTER SEQUENCE SEQ_SERVICES_ID RESTART WITH 1;
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,1, 'Taxe de séjour adulte', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,1, 'Taxe de séjour enfant', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,3, 'Logement', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,3, 'Logement et petit-déjeuner','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,3, 'Arrangement demi-pension', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,3, 'Arrangement pension complète','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,4, 'Demi-pension', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,4, 'Pension complète','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Petit-déjeuner','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Extras petit-déjeuner','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,4, 'Restaurant','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,4, 'Bistro','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Fax','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Garage', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Téléphone','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Wifi chambre','0');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,6, 'Timbre', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Lingerie','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,6, 'Location salle','1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,6, 'Débours', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,6, 'Rabais', '1');
INSERT INTO SERVICES(ID, SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES(0,5, 'Service en chambre','1');
COMMIT;

INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(-1,1,'Autre...');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(-1,2,'Autre...');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(-1,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(-1,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(0,1,'Autre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(0,2,'Autre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(0,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(0,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(1,1,'Taxe de séjour adulte');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(1,2,'Taxe de séjour adulte');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(1,3,'2');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(1,4,'2');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(2,1,'Taxe de séjour enfant');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(2,2,'Taxe de séjour enfant');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(2,3,'1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(2,4,'1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(3,1,'Logement');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(3,2,'Logement');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(3,3,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(3,4,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(4,1,'Logement et petit-déjeuner');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(4,2,'Logement+p.dej');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(4,3,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(4,4,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(5,1,'Arrangement demi-pension');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(5,2,'Arrangement 1/2 pension');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(5,3,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(5,4,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(6,1,'Arrangement pension complète');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(6,2,'Arrangement pension comp.');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(6,3,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(6,4,'-1');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(7,1,'Demi-pension');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(7,2,'1/2 pension');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(7,3,'25');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(7,4,'25');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(8,1,'Pension complète');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(8,2,'Pension complète');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(8,3,'50');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(8,4,'50');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(9,1,'Petit-déjeuner');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(9,2,'Petit-déjeuner');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(9,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(9,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(10,1,'Extras petit-déjeuner');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(10,2,'Extras p.dej');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(10,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(10,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(11,1,'Restaurant');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(11,2,'Restaurant');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(11,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(11,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(12,1,'Bistro');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(12,2,'Bistro');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(12,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(12,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(13,1,'Fax');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(13,2,'Fax');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(13,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(13,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(14,1,'Garage');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(14,2,'Garage');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(14,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(14,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(15,1,'Téléphone');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(15,2,'Téléphone');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(15,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(15,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(16,1,'Wifi chambre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(16,2,'Wifi chambre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(16,3,'5');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(16,4,'5');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(17,1,'Timbre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(17,2,'Timbre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(17,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(17,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(18,1,'Lingerie');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(18,2,'Lingerie');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(18,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(18,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(19,1,'Location salle');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(19,2,'Location salle');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(19,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(19,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(20,1,'Débours');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(20,2,'Débours');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(20,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(20,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(21,1,'Rabais');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(21,2,'Rabais');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(21,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(21,4,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(22,1,'Service en chambre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(22,2,'Service en chambre');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(22,3,'0');
INSERT INTO SERVICESDETAILS(SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE) VALUES(22,4,'0');
COMMIT;

INSERT INTO USERS(ID, LOGIN, ENCRYPTEDPASS, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR) VALUES(0, 'hotel','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','0','0','0');
INSERT INTO USERS(ID, LOGIN, ENCRYPTEDPASS, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR) VALUES(0, 'manX','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','1','0','0');
INSERT INTO USERS(ID, LOGIN, ENCRYPTEDPASS, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR) VALUES(0, 'manZ','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','1','1','0');
INSERT INTO USERS(ID, LOGIN, ENCRYPTEDPASS, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR) VALUES(0, 'admin','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','0','0','1','1');
INSERT INTO TRAINEES(ID, LOGIN, ENCRYPTEDPASS) VALUES(0,'formation','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF');
COMMIT;


