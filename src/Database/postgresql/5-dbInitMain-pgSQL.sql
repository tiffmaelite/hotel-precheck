SELECT genall_upsertID();

SELECT gen_upsert('BILLINGSTYPES', 'NBBILLS=to_number(NEW.NBBILLS,\'FMMI9G999G999D999\')', 'LABEL=NEW.LABEL');

SELECT gen_upsert('BILLS', 'BILLTYPE_ID=to_number(NEW.BILLTYPE_ID,\'FMMI9G999G999D999\'), NOTE=NEW.NOTE', 'BILLING_ID=to_number(NEW.BILLING_ID,\'FMMI9G999G999D999\') AND BILLINGBILLID=to_number(NEW.BILLINGBILLID,\'FMMI9G999G999D999\')');

SELECT gen_upsert('TRAINING_BILLS', 'BILLTYPE_ID=to_number(NEW.BILLTYPE_ID,\'FMMI9G999G999D999\'), NOTE=NEW.NOTE', 'BILLING_ID=to_number(NEW.BILLING_ID,\'FMMI9G999G999D999\') AND BILLINGBILLID=to_number(NEW.BILLINGBILLID,\'FMMI9G999G999D999\')');

SELECT gen_upsert('CHARGEDSERVICES', 'INVOICINGDATE=to_date(NEW.INVOICINGDATE,\'DD MM YYYY\'),QUANTITY=to_number(NEW.QUANTITY,\'FMMI9G999G999D999\'), CHARGEDUNITPRICE=to_number(NEW.CHARGEDUNITPRICE,\'FMMI9G999G999D999\'), VAT_PERCENTAGE=to_number(NEW.VAT_PERCENTAGE,\'FMMI9G999G999D999\'), ISPRINTED=to_number(NEW.hourlog,\'FMMI9G999G999D999\'), ISPAYED=to_char(NEW.ISPAYED,\'FM9\'), PAIEMENTDATE=to_date(NEW.PAIEMENTDATE, \'DD MM YYYY\')', 'SERVICE_ID=to_number(NEW.SERVICE_ID,\'FMMI9G999G999D999\') AND BILL_ID=to_number(NEW.BILL_ID,\'FMMI9G999G999D999\')');

SELECT gen_upsert('TRAINING_CHARGEDSERVICES', 'INVOICINGDATE=to_date(NEW.INVOICINGDATE, \'DD MM YYYY\'),QUANTITY=to_number(NEW.QUANTITY,\'FMMI9G999G999D999\'), CHARGEDUNITPRICE=to_number(NEW.CHARGEDUNITPRICE,\'FMMI9G999G999D999\'), VAT_PERCENTAGE=to_number(NEW.VAT_PERCENTAGE,\'FMMI9G999G999D999\'), ISPRINTED=to_char(NEW.ISPRINTED,\'FM9\'), ISPAYED=to_char(NEW.ISPAYED,\'FM9\'), PAIEMENTDATE=to_date(NEW.PAIEMENTDATE, \'DD MM YYYY\')', 'SERVICE_ID=to_number(NEW.SERVICE_ID,\'FMMI9G999G999D999\') AND BILL_ID=to_number(NEW.BILL_ID,\'FMMI9G999G999D999\')');

SELECT gen_upsertmult('REPORTSTYPES', array['GENERATIONQUERY=NEW.GENERATIONQUERY','LABEL=NEW.LABEL'], array['LABEL=NEW.LABEL','GENERATIONQUERY=NEW.GENERATIONQUERY']);
SELECT gen_upsert('ROOMS', 'ROOMTYPE_ID=to_number(NEW.ROOMTYPE_ID,\'FMMI9G999G999D999\'), FLOOR=to_number(NEW.FLOOR,\'FMMI9G999G999D999\'), ISCLEANED=to_char(NEW.ISCLEANED,\'FM9\')', 'NUMBER=to_number(NEW.NUMBER,\'FMMI9G999G999D999\')');

SELECT gen_upsertmult('ROOMSOCCUPATIONS', array['ARRIVINGDATE=to_date(NEW.ARRIVINGDATE, \'DD MM YYYY\'), DEPARTUREDATE=to_date(NEW.DEPARTUREDATE, \'DD MM YYYY\')','BILLING_ID=to_number(NEW.BILLING_ID,\'FMMI9G999G999D999\'), DEPARTUREDATE=to_date(NEW.DEPARTUREDATE, \'DD MM YYYY\')','ARRIVINGDATE=to_date(NEW.ARRIVINGDATE, \'DD MM YYYY\'), BILLING_ID=to_number(NEW.BILLING_ID,\'FMMI9G999G999D999\')'], array['ROOM_ID=to_number(NEW.ROOM_ID,\'FMMI9G999G999D999\') AND BILLING_ID=to_number(NEW.BILLING_ID,\'FMMI9G999G999D999\')','ROOM_ID=to_number(NEW.ROOM_ID,\'FMMI9G999G999D999\') AND ARRIVINGDATE=to_date(NEW.ARRIVINGDATE, \'DD MM YYYY\')','ROOM_ID=to_number(NEW.ROOM_ID,\'FMMI9G999G999D999\') AND DEPARTUREDATE=to_date(NEW.DEPARTUREDATE, \'DD MM YYYY\')']);

SELECT gen_upsert('ROOMSTYPES', 'DESCRIPTION=NEW.DESCRIPTION, PRICEMIN=to_number(NEW.PRICEMIN,\'FMMI9G999G999D999\'), PRICEMAX=to_number(NEW.PRICEMAX,\'FMMI9G999G999D999\')', 'LABEL=NEW.LABEL');

SELECT gen_upsert('SERVICESDETAILS', 'FIELDVALUE=NEW.FIELDVALUE', 'SERVICEFIELD_ID=to_number(NEW.SERVICEFIELD_ID,\'FMMI9G999G999D999\') AND SERVICE_ID=to_number(NEW.SERVICE_ID,\'FMMI9G999G999D999\')');

SELECT gen_upsert('SERVICESFIELDS', 'SQLTYPE=NEW.SQLTYPE', 'LABEL=NEW.LABEL');

SELECT gen_upsert('SERVICES', 'SERVICETYPE_ID=to_number(NEW.SERVICETYPE_ID,\'FMMI9G999G999D999\'), ISAVAILABLE=to_char(NEW.ISAVAILABLE,\'FM9\')', 'NAME=NEW.NAME');

SELECT gen_upsert('SERVICESTYPES', 'SERVICEFAMILY_ID=to_number(NEW.SERVICEFAMILY_ID,\'FMMI9G999G999D999\'), VAT_ID=to_number(NEW.VAT_ID,\'FMMI9G999G999D999\'), ROOMNEEDED=to_char(NEW.ROOMNEEDED,\'FM9\')', 'LABEL=NEW.LABEL');

SELECT gen_upsert('USERS', 'ENCRYPTEDPASS=NEW.ENCRYPTEDPASS, ISRECEPTIONIST=to_char(NEW.ISRECEPTIONIST,\'FM9\'), ISMANAGERX=to_char(NEW.ISMANAGERX,\'FM9\'), ISMANAGERZ=to_char(NEW.ISMANAGERZ,\'FM9\'), ISADMINISTRATOR=to_char(NEW.ISADMINISTRATOR,\'FM9\')', 'LOGIN=NEW.LOGIN');

SELECT gen_upsert('TRAINEES', 'ENCRYPTEDPASS=NEW.ENCRYPTEDPASS, ISACTIVATED=to_char(NEW.ISACTIVATED,\'FM9\')', 'LOGIN=NEW.LOGIN');




SELECT gen_upsert('ADDRESSES_ARCHIVE', 'client_id=to_number(NEW.client_id,\'FMMI9G999G999D999\'), zipcode=NEW.zipcode, phone=NEW.phone,complementaryline=NEW.complementaryline', 'contact=NEW.contact AND street=NEW.street AND number=NEW.number AND city=NEW.city AND country=NEW.country');

SELECT gen_upsert('GROUPS_ARCHIVE', 'CONTACT_ID=to_number(NEW.CONTACT_ID,\'FMMI9G999G999D999\')', 'NAME=NEW.NAME');

SELECT gen_upsert('BALANCELOG_ARCHIVE', 'balance=to_number(NEW.balance,\'FMMI9G999G999D999\')', 'yearlog=to_number(NEW.yearlog,\'FMMI9G999G999D999\') AND monthlog=to_number(NEW.monthlog,\'FMMI9G999G999D999\') AND daylog=to_number(NEW.daylog,\'FMMI9G999G999D999\') AND hourlog=to_number(NEW.hourlog,\'FMMI9G999G999D999\')');

SELECT gen_upsert('NATIONALITIES_ARCHIVE', 'COUNTRY=NEW.COUNTRY, CODE=to_number(NEW.CODE,\'FMMI9G999G999D999\'), ISOCODE=NEW.ISOCODE', 'LONGISOCODE=NEW.LONGISOCODE');

SELECT gen_upsertmult('CLIENTS_ARCHIVE', array['NAME=NEW.NAME, PHONE=NEW.PHONE, IDCARDSCAN=NEW.IDCARDSCAN, NATIONALITY_ID=to_number(NEW.NATIONALITY_ID,\'FMMI9G999G999D999\'), HOMEADDRESS_ID=to_number(NEW.HOMEADDRESS_ID, \'FMMI9G999G999D999\'), ISCURRENT=NEW.ISCURRENT','EMAIL=NEW.EMAIL, PHONE=NEW.PHONE, NATIONALITY_ID=to_number(NEW.NATIONALITY_ID,\'FMMI9G999G999D999\'), HOMEADDRESS_ID=to_number(NEW.HOMEADDRESS_ID, \'FMMI9G999G999D999\'),ISCURRENT=NEW.ISCURRENT', 'EMAIL=NEW.EMAIL, PHONE=NEW.PHONE, IDCARDSCAN=NEW.IDCARDSCAN, NATIONALITY_ID=to_number(NEW.NATIONALITY_ID,\'FMMI9G999G999D999\'), ISCURRENT=NEW.ISCURRENT'], array['EMAIL=NEW.EMAIL','NAME=NEW.NAME AND IDCARDSCAN=NEW.IDCARDSCAN AND IDCARDSCAN IS NOT NULL','NAME=NEW.NAME AND HOMEADDRESS_ID=to_number(NEW.HOMEADDRESS_ID, \'FMMI9G999G999D999\') AND HOMEADDRESS_ID IS NOT NULL']);



INSERT INTO ROOMSTYPES
  (LABEL, DESCRIPTION, PRICEMIN, PRICEMAX)
VALUES
  ('1L+D', '1 lit en 80x200 + 1 douche', 100, 120),
  ('1GL+D', '1 lit en 160x200 + 1 douche', 120, 150),
  ('1pGL+D', '1 lit en 140x190 ou en 140x200 + 1 douche', 135, 145),
  ('2L+D', '2 lits en 80x200 + 1 douche', 150, 165),
  ('2L+B', '2 lits en 80x200 + 1 baignoire', 150, 165),
  ('2Lc+D', '2 lits en 90x200 + 1 douche', 160, 180),
  ('2Lc+B', '2 lits en 90x200 + 1 baignoire', 160, 180),
  ('Junior Suite', '2 lits en 90x200 ou 1 lit 140x200 + 1 baignoire', 170, 195),
  ('3L+B', '3 lits en 80x200 + 1 baignoire', 175, 200),
  ('2L+1pGL+B', '2 lits en 80x200 + 1 lit 140x200 + 1 baignoire', 185, 215),
  ('3L+1pGL+B', '3 lits en 80x200 + 1 lit 140x200 + 1 baignoire', 195, 255),
  ('appartement', '', 300, 300),
  ('studio', '', 350, 350);



INSERT INTO ROOMS
  (ROOMTYPE_ID, NUMBER, FLOOR)
VALUES
  (1, 309, 3),
  (1, 509, 5),
  (1, 710, 7),
  (1, 711, 7),
  (1, 712, 7),
  (3, 308, 3),
  (3, 307, 3),
  (3, 407, 4),
  (3, 507, 5),
  (3, 607, 6),
  (2, 707, 7),
  (2, 605, 6),
  (2, 207, 2),
  (4, 201, 2),
  (4, 202, 2),
  (4, 203, 2),
  (4, 205, 2),
  (4, 206, 2),
  (4, 301, 3),
  (4, 302, 3),
  (4, 303, 3),
  (4, 305, 3),
  (4, 306, 3),
  (8, 310, 3),
  (7, 311, 3),
  (4, 401, 4),
  (4, 402, 4),
  (4, 403, 4),
  (4, 405, 4),
  (4, 406, 4),
  (5, 408, 4),
  (5, 411, 4),
  (4, 501, 5),
  (4, 502, 5),
  (4, 503, 5),
  (4, 505, 5),
  (4, 506, 5),
  (5, 508, 5),
  (4, 601, 6),
  (4, 602, 6),
  (4, 603, 6),
  (4, 606, 6),
  (4, 701, 7),
  (4, 705, 7),
  (4, 706, 7),
  (4, 708, 7),
  (8, 510, 5),
  (7, 511, 5),
  (7, 704, 7),
  (9, 304, 3),
  (9, 504, 5),
  (9, 604, 6),
  (10, 204, 2),
  (10, 404, 4),
  (12, 410, 4),
  (12, 702, 7),
  (13, 132, 7);


INSERT INTO TAXES
  (LABEL, PERCENTAGE, STARTDATE, ENDDATE)
VALUES
  ('0%',0.0,null,null),
  ('2,5%',2.5,null,null),
  ('3,8%',3.8,'1996-01-01','2017-01-01'),
  ('8%',8.0,null,null);

INSERT INTO SERVICESFAMILIES
  (LABEL)
VALUES
  ('Arrangement'),
  ('Repas'),
  ('Prestations');

INSERT INTO SERVICESTYPES
  (LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED, CODE)
VALUES
  ('Autre',3,1, '1', 1),
  ('Taxe de séjour',1,1, '1', 1),
  ('Accomodation',1,1, '1', 2),
  ('Repas',2,1, '1', 1),
  ('Prestation extra',3,1, '1', 2),
  ('Vente au comptant',3,1, '0', 3);



INSERT INTO SERVICESFIELDS
  (LABEL, SQLTYPE)
VALUES
  ('DISPLAYEDNAME','VARCHAR(100)'),
  ('PRINTEDNAME','VARCHAR(100)'),
  ('PRICEMIN','FLOAT'),
  ('PRICEMAX','FLOAT');


INSERT INTO SERVICES
  (ID, SERVICETYPE_ID, NAME, ISAVAILABLE, CODE)
VALUES
  (-1, 1, 'Autre...', '1', 1),
  (0, 1, 'Autre', '1', 2);

INSERT INTO SERVICES
  (SERVICETYPE_ID, NAME, ISAVAILABLE, CODE)
VALUES
  (2, 'Taxe de séjour adulte', '1', 1),
  (2, 'Taxe de séjour enfant', '1', 2),
  (3, 'Logement', '1', 1),
  (3, 'Logement et petit-déjeuner','1', 2),
  (3, 'Arrangement demi-pension', '1', 3),
  (3, 'Arrangement pension complète','1', 4),
  (4, 'Demi-pension', '1', 1),
  (4, 'Pension complète','1', 2),
  (4, 'Restaurant','1',3),
  (4, 'Bistro','1', 4),
  (5, 'Petit-déjeuner','1', 1),
  (5, 'Extras petit-déjeuner','1',2),
  (5, 'Fax','1', 3),
  (5, 'Garage', '1', 4),
  (5, 'Téléphone','1', 5),
  (5, 'Wifi chambre','0', 6),
  (5, 'Lingerie','1', 7),
  (5, 'Service en chambre','1', 8),
  (6, 'Timbre', '1', 1),
  (6, 'Location salle','1', 2),
  (6, 'Débours', '1', 3),
  (6, 'Rabais', '1', 4);


INSERT INTO SERVICESDETAILS
  (SERVICE_ID,SERVICEFIELD_ID, FIELDVALUE)
VALUES
  (-1,1,'Autre...'),
  (-1,2,'Autre...'),
  (-1,3,'0'),
  (-1,4,'0'),
  (0, 1,'Autre'),
  (0, 2,'Autre'),
  (0, 3,'0'),
  (0, 4,'0'),
  (1,1,'Taxe de séjour adulte'),
  (1,2,'Taxe de séjour adulte'),
  (1,3,'2'),
  (1,4,'2'),
  (2,1,'Taxe de séjour enfant'),
  (2,2,'Taxe de séjour enfant'),
  (2,3,'1'),
  (2,4,'1'),
  (3,1,'Logement'),
  (3,2,'Logement'),
  (3,3,'-1'),
  (3,4,'-1'),
  (4,1,'Logement et petit-déjeuner'),
  (4,2,'Logement+p.dej'),
  (4,3,'-1'),
  (4,4,'-1'),
  (5,1,'Arrangement demi-pension'),
  (5,2,'Arrangement 1/2 pension'),
  (5,3,'-1'),
  (5,4,'-1'),
  (6,1,'Arrangement pension complète'),
  (6,2,'Arrangement pension comp.'),
  (6,3,'-1'),
  (6,4,'-1'),
  (7,1,'Demi-pension'),
  (7,2,'1/2 pension'),
  (7,3,'25'),
  (7,4,'25'),
  (8,1,'Pension complète'),
  (8,2,'Pension complète'),
  (8,3,'50'),
  (8,4,'50'),
  (9,1,'Petit-déjeuner'),
  (9,2,'Petit-déjeuner'),
  (9,3,'0'),
  (9,4,'0'),
  (10,1,'Extras petit-déjeuner'),
  (10,2,'Extras p.dej'),
  (10,3,'0'),
  (10,4,'0'),
  (11,1,'Restaurant'),
  (11,2,'Restaurant'),
  (11,3,'0'),
  (11,4,'0'),
  (12,1,'Bistro'),
  (12,2,'Bistro'),
  (12,3,'0'),
  (12,4,'0'),
  (13,1,'Fax'),
  (13,2,'Fax'),
  (13,3,'0'),
  (13,4,'0'),
  (14,1,'Garage'),
  (14,2,'Garage'),
  (14,3,'0'),
  (14,4,'0'),
  (15,1,'Téléphone'),
  (15,2,'Téléphone'),
  (15,3,'0'),
  (15,4,'0'),
  (16,1,'Wifi chambre'),
  (16,2,'Wifi chambre'),
  (16,3,'5'),
  (16,4,'5'),
  (17,1,'Timbre'),
  (17,2,'Timbre'),
  (17,3,'0'),
  (17,4,'0'),
  (18,1,'Lingerie'),
  (18,2,'Lingerie'),
  (18,3,'0'),
  (18,4,'0'),
  (19,1,'Location salle'),
  (19,2,'Location salle'),
  (19,3,'0'),
  (19,4,'0'),
  (20,1,'Débours'),
  (20,2,'Débours'),
  (20,3,'0'),
  (20,4,'0'),
  (21,1,'Rabais'),
  (21,2,'Rabais'),
  (21,3,'0'),
  (21,4,'0'),
  (22,1,'Service en chambre'),
  (22,2,'Service en chambre'),
  (22,3,'0'),
  (22,4,'0');



INSERT INTO USERS
  (LOGIN, ENCRYPTEDPASS, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR)
VALUES
  ('hotel','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','0','0','0'),
 ('manX','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','1','0','0'),
 ('manZ','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','1','1','1','0'),
 ('admin','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF','0','0','1','1');



INSERT INTO TRAINEES
  (LOGIN, ENCRYPTEDPASS, ISACTIVATED)
VALUES
  ('formation','EE26B0DD4AF7E749AA1A8EE3C10AE9923F618980772E473F8819A5D4940E0DB27AC185F8A0E1D5F84F88BC887FD67B143732C304CC5FA9AD8E6F57F50028A8FF', '1');


INSERT INTO REPORTSTYPES
  (LABEL, DESCRIPTION, GENERATIONQUERY)
VALUES
  ('today balance','Comptabilisateurs journaliers', 'SELECT dbalance, ddaylog, dmonthlog, dyearlog FROM dailybalcount GROUP BY dyearlog, dmonthlog, ddaylog HAVING dcreationtime = (SELECT MAX(dcreationtime) FROM dailybalcount);'),
  ('total balance','Journal des comptabilisateurs', 'SELECT balance, hourlog, daylog, monthlog, yearlog FROM balance_archiveORDER BY yearlog, monthlog, daylog, hourlog;');

