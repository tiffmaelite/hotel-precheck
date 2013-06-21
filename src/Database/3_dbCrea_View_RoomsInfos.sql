CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE VIEW ROOMSINFOS AS
SELECT
ROOMS.ID, ROOMS.NUMBER, ROOMS.FLOOR,
ROOMSTYPES.LABEL, ROOMSTYPES.DESCRIPTION, ROOMSTYPES.PRICEMIN, ROOMSTYPES.PRICEMAX,
(CASE B.ISAVAILABLE WHEN '1' THEN (CASE ROOMS.ISCLEANED WHEN '1' THEN '1' ELSE '' END) ELSE '0' END) AS AVAILABILITY
FROM ROOMS
LEFT JOIN (SELECT CAST((CASE WHEN COUNT(*)>0 THEN '0' ELSE '1' END) AS BOOLEAN) AS ISAVAILABLE, ROOMSOCCUPATIONS.ROOM_ID FROM ROOMSOCCUPATIONS WHERE ROOMSOCCUPATIONS.DEPARTUREDATE>=CURRENT_DATE GROUP BY ROOMSOCCUPATIONS.ROOM_ID) AS B ON ROOMS.ID=B.ROOM_ID
LEFT JOIN ROOMSTYPES ON ROOMS.ROOMTYPE_ID=ROOMSTYPES.ID
ORDER BY ROOMS.NUMBER;

COMMIT;