CREATE VIEW ROOMSINFOS AS
  SELECT
	ROOMS.ID AS ID,
	ROOMS.NUMBER AS NUMBER,
	ROOMS.FLOOR AS FLOOR,
	ROOMTYPE_ID,
	ROOMSTYPES.LABEL AS TYPE,
	ROOMSTYPES.DESCRIPTION AS DESCRIPTION,
	ROOMSTYPES.PRICEMIN AS PRICEMIN,
	ROOMSTYPES.PRICEMAX AS PRICEMAX,
	ROOMS.ISCLEANED AS ISCLEANED,
	B.ISAVAILABLE AS ISAVAILABLE
  FROM ROOMS
  LEFT JOIN (
  SELECT
		  CAST((CASE WHEN COUNT(CASE WHEN ROOMSOCCUPATIONS.DEPARTUREDATE>=CURRENT_DATE THEN 1 ELSE 0 END)>0 THEN '0' ELSE '1' END) AS BOOLEAN) AS ISAVAILABLE,
		  ROOMS.ID AS ROOMID
		FROM ROOMSOCCUPATIONS
		RIGHT JOIN ROOMS ON ROOMS.ID=ROOMSOCCUPATIONS.ROOM_ID
		GROUP BY ROOMS.ID
	) AS B ON ROOMS.ID=B.ROOMID
  LEFT JOIN ROOMSTYPES ON ROOMS.ROOMTYPE_ID=ROOMSTYPES.ID
  ORDER BY ROOMS.NUMBER;
  --WITH CASCADED CHECK OPTION;

CREATE OR REPLACE FUNCTION roomsinfos_ins_up_del()
RETURNS TRIGGER
AS $$
   BEGIN
	  IF TG_OP = 'INSERT' OR TG_OP = 'UPDATE' THEN
	  IF old.ROOMTYPE_ID=new.ROOMTYPE_ID THEN
		UPDATE ROOMSTYPES SET DESCRIPTION=new.description, PRICEMIN=new.pricemin, PRICEMAX=new.pricemax, label=new.TYPE WHERE id=new.ROOMTYPE_ID;
   ELSE
	  SELECT genupsert_ROOMSTYPES(hstore(ARRAY[['DESCRIPTION','new.DESCRIPTION'],['PRICEMIN','new.PRICEMIN'],['PRICEMAX','new.PRICEMAX'],['label','new.type']]));
	  --INSERT INTO ROOMSTYPES(LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(new.TYPE, new.description, new.pricemin, new.pricemax);
END IF;
END IF;

IF TG_OP = 'INSERT' THEN
	  INSERT INTO ROOMS(NUMBER, FLOOR, ROOMTYPE_ID, ISCLEANED) VALUES(new.number,new.floor,(select id from roomstypes where LABEL=new.TYPE), new.ISCLEANED);

  ELSEIF TG_OP = 'UPDATE' THEN
	  UPDATE ROOMS SET FLOOR=new.floor, ROOMTYPE_ID=(select id from roomstypes where LABEL=new.TYPE), ISCLEANED=new.ISCLEANED WHERE number=new.number;

  ELSIF TG_OP = 'DELETE' THEN
		DELETE FROM ROOMS WHERE number=old.number;

	   RETURN NULL;

  END IF;
	  RETURN NEW;
	END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_changeroomsinfos
	INSTEAD OF INSERT OR UPDATE OR DELETE ON ROOMSINFOS
	FOR EACH ROW EXECUTE PROCEDURE roomsinfos_ins_up_del();