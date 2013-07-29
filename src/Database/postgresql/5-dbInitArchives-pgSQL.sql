SELECT gen_upsert('ADDRESSES', 'client_id=new.client_id, zipcode=new.zipcode, phone=new.phone,complementaryline=new.complementaryline', 'contact=new.contact AND street=new.street AND number=new.number AND city=new.city AND country=new.country');

SELECT gen_upsert('GROUPS', 'CONTACT_ID=new.CONTACT_ID', 'NAME=new.NAME');

SELECT gen_upsert('BALANCELOG', 'balance=new.balance', 'yearlog=new.yearlog AND monthlog=new.monthlog AND daylog=new.daylog AND hourlog=new.hourlog');

SELECT gen_upsert('NATIONALITIES', 'COUNTRY=new.COUNTRY, CODE=NEW.CODE', 'LABEL=new.LABEL');

SELECT gen_upsertmult('CLIENTS', array['NAME=new.NAME, PHONE=new.PHONE, IDCARDSCAN=new.IDCARDSCAN, NATIONALITY_ID=new.NATIONALITY_ID, HOMEADDRESS_ID=NEW.HOMEADDRESS_ID, ISCURRENT=NEW.ISCURRENT','EMAIL=new.EMAIL, PHONE=new.PHONE, NATIONALITY_ID=new.NATIONALITY_ID, HOMEADDRESS_ID=NEW.HOMEADDRESS_ID,ISCURRENT=NEW.ISCURRENT', 'EMAIL=new.EMAIL, PHONE=new.PHONE, IDCARDSCAN=new.IDCARDSCAN, NATIONALITY_ID=new.NATIONALITY_ID, ISCURRENT=NEW.ISCURRENT'], array['EMAIL=new.EMAIL','NAME=new.NAME AND IDCARDSCAN=new.IDCARDSCAN AND IDCARDSCAN IS NOT NULL','NAME=new.NAME AND HOMEADDRESS_ID=new.HOMEADDRESS_ID AND HOMEADDRESS_ID IS NOT NULL']);

