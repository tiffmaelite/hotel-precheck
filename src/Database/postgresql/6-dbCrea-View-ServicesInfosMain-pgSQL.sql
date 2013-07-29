SELECT genpivotcode('SERVICESDETAILS', 'SERVICE_ID', 'LABEL', 'FIELDVALUE', 'SQLTYPE', 'SERVICESFIELDS', 'SERVICEFIELD_ID', 'INTEGER', 'SERVICESDETAILSPIVOT');

CREATE VIEW SERVICESINFOS AS
  SELECT
	SERVICES.ID AS ID,
	SERVICES.ISAVAILABLE AS ISAVAILABLE,
	SERVICES.NAME AS SERVICENAME,
	SERVICESFAMILIES.LABEL AS SERVICEFAMILY,
	SERVICESTYPES.LABEL AS SERVICETYPE,
	TAXES.LABEL AS VAT,
	SERVICEFAMILY_ID,
	VAT_ID,
	SERVICETYPE_ID,
	SERVICESTYPES.ROOMNEEDED AS TYPENEEDSROOM,
	SERVICESDETAILSPIVOT.*
  FROM SERVICES
  LEFT JOIN SERVICESTYPES ON SERVICES.SERVICETYPE_ID=SERVICESTYPES.ID
  LEFT JOIN SERVICESFAMILIES ON SERVICESTYPES.SERVICEFAMILY_ID=SERVICESFAMILIES.ID
  LEFT JOIN SERVICESDETAILSPIVOT ON SERVICESDETAILSPIVOT.SERVICE_ID=SERVICES.ID
  LEFT JOIN TAXES ON SERVICESTYPES.VAT_ID = TAXES.ID
  ORDER BY SERVICEFAMILY, SERVICETYPE, SERVICENAME;--,
  --GROUP BY SERVICES.ID--;
  --WITH CASCADED CHECK OPTION;

CREATE OR REPLACE FUNCTION servicesinfos_ins_up_del()
RETURNS TRIGGER
AS $$
   BEGIN
   IF TG_OP = 'INSERT' OR TG_OP = 'UPDATE' THEN
	  IF old.SERVICEFAMILY_ID=new.SERVICEFAMILY_ID THEN
		UPDATE SERVICESFAMILIES SET LABEL=new.SERVICEFAMILY WHERE id=new.SERVICEFAMILY_ID;
	  ELSE
		INSERT INTO SERVICESFAMILIES(LABEL) VALUES(new.SERVICEFAMILY);
	  END IF;

	  IF old.SERVICETYPE_ID=new.SERVICETYPE_ID THEN
		UPDATE SERVICESTYPES SET LABEL=new.SERVICETYPE WHERE id=new.SERVICETYPE_ID;
	  ELSE
		SELECT genupsert_SERVICESTYPES(hstore(ARRAY[['LABEL','new.SERVICETYPE'],['SERVICEFAMILY_ID','(SELECT id FROM SERVICESFAMILIES WHERE LABEL=new.SERVICEFAMILY)'],['VAT_ID','new.VAT_ID'],['ROOMNEEDED','new.TYPENEEDSROOM']]));
		--INSERT INTO SERVICESTYPES(LABEL, SERVICEFAMILY_ID, VAT_ID, ROOMNEEDED) VALUES(new.SERVICETYPE, (SELECT id FROM SERVICESFAMILIES WHERE LABEL=new.SERVICEFAMILY), new.VAT_ID, new.TYPENEEDSROOM);
	  END IF;
	END IF;

  IF TG_OP = 'INSERT'
	  INSERT INTO SERVICES(SERVICETYPE_ID, NAME, ISAVAILABLE) VALUES((SELECT id FROM SERVICESFAMILIES WHERE LABEL=new.SERVICETYPE),new.SERVICENAME,new.ISAVAILABLE);
  ELSEIF TG_OP = 'UPDATE' THEN
	  --UPDATE ROOMS SET FLOOR=new.floor, ROOMTYPE_ID=(select id from roomstypes where LABEL=new.TYPE) WHERE number=new.number; //TODO
	  ELSIF TG_OP = 'DELETE' THEN
		DELETE FROM SERVICES WHERE name=old.servicename;
	   RETURN NULL;
   END IF;

	  RETURN NEW;
	END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_changeservicesinfos
	INSTEAD OF INSERT OR UPDATE OR DELETE ON SERVICESINFOS
	FOR EACH ROW EXECUTE PROCEDURE servicesinfos_ins_up_del();
