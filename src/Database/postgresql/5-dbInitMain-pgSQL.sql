SELECT genall_upsertID();

SELECT gen_upsert('BILLINGSTYPES', 'NBBILLS=new.NBBILLS', 'LABEL=new.LABEL');

SELECT gen_upsert('BILLS', 'BILLTYPE_ID=new.BILLTYPE_ID, NOTE=new.NOTE', 'BILLING_ID=new.BILLING_ID AND BILLINGBILLID=new.BILLINGBILLID');

SELECT gen_upsert('TRAINING_BILLS', 'BILLTYPE_ID=new.BILLTYPE_ID, NOTE=new.NOTE', 'BILLING_ID=new.BILLING_ID AND BILLINGBILLID=new.BILLINGBILLID');

SELECT gen_upsert('CHARGEDSERVICES', 'INVOICINGDATE=new.INVOICINGDATE,QUANTITY=NEW.QUANTITY, CHARGEDUNITPRICE=NEW.CHARGEDUNITPRICE, VAT_PERCENTAGE=NEW.VAT_PERCENTAGE, ISPRINTED=NEW.ISPRINTED, ISPAYED=NEW.ISPAYED, PAIEMENTDATE=NEW.PAIEMENTDATE', 'SERVICE_ID=new.SERVICE_ID AND BILL_ID=new.BILL_ID');

SELECT gen_upsert('TRAINING_CHARGEDSERVICES', 'INVOICINGDATE=new.INVOICINGDATE,QUANTITY=NEW.QUANTITY, CHARGEDUNITPRICE=NEW.CHARGEDUNITPRICE, VAT_PERCENTAGE=NEW.VAT_PERCENTAGE, ISPRINTED=NEW.ISPRINTED, ISPAYED=NEW.ISPAYED, PAIEMENTDATE=NEW.PAIEMENTDATE', 'SERVICE_ID=new.SERVICE_ID AND BILL_ID=new.BILL_ID');

SELECT gen_upsertmult('REPORTSTYPES', array['GENERATIONQUERY=new.GENERATIONQUERY','LABEL=new.LABEL'], array['LABEL=new.LABEL','GENERATIONQUERY=new.GENERATIONQUERY']);
SELECT gen_upsert('ROOMS', 'ROOMTYPE_ID=new.ROOMTYPE_ID, FLOOR=NEW.FLOOR, ISCLEANED=NEW.ISCLEANED', 'NUMBER=new.NUMBER');

SELECT gen_upsertmult('ROOMSOCCUPATIONS', array['ARRIVINGDATE=new.ARRIVINGDATE, DEPARTUREDATE=NEW.DEPARTUREDATE','BILLING_ID=new.BILLING_ID, DEPARTUREDATE=NEW.DEPARTUREDATE','ARRIVINGDATE=new.ARRIVINGDATE, BILLING_ID=NEW.BILLING_ID'], array['ROOM_ID=new.ROOM_ID AND BILLING_ID=NEW.BILLING_ID','ROOM_ID=new.ROOM_ID AND ARRIVINGDATE=NEW.ARRIVINGDATE','ROOM_ID=new.ROOM_ID AND DEPARTUREDATE=NEW.DEPARTUREDATE']);

SELECT gen_upsert('ROOMSTYPES', 'DESCRIPTION=new.DESCRIPTION, PRICEMIN=NEW.PRICEMIN, PRICEMAX=NEW.PRICEMAX', 'LABEL=new.LABEL');

SELECT gen_upsert('SERVICESDETAILS', 'FIELDVALUE=new.FIELDVALUE', 'SERVICEFIELD_ID=new.SERVICEFIELD_ID AND SERVICE_ID=new.SERVICE_ID');

SELECT gen_upsert('SERVICESFIELDS', 'SQLTYPE=new.SQLTYPE', 'LABEL=new.LABEL');

SELECT gen_upsert('SERVICES', 'SERVICETYPE_ID=new.SERVICETYPE_ID, ISAVAILABLE=NEW.ISAVAILABLE', 'NAME=new.NAME');

SELECT gen_upsert('SERVICESTYPES', 'SERVICEFAMILY_ID=new.SERVICEFAMILY_ID, VAT_ID=NEW.VAT_ID, ROOMNEEDED=NEW.ROOMNEEDED', 'LABEL=new.LABEL');

SELECT gen_upsert('USERS', 'ENCRYPTEDPASS=new.ENCRYPTEDPASS, ISRECEPTIONIST=NEW.ISRECEPTIONIST, ISMANAGERX=NEW.ISMANAGERX, ISMANAGERZ=NEW.ISMANAGERZ, ISADMINISTRATOR=NEW.ISADMINISTRATOR', 'LOGIN=new.LOGIN');

SELECT gen_upsert('TRAINEES', 'ENCRYPTEDPASS=new.ENCRYPTEDPASS, ISACTIVATED=NEW.ISACTIVATED', 'LOGIN=new.LOGIN');



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
  ('3,8%',3.8,null,null);

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
  (1, 'Taxe de séjour adulte', '1', 3),
  (1, 'Taxe de séjour enfant', '1', 4),
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

