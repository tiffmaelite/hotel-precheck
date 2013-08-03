CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

CREATE VIEW BILLINGSINFOS AS
SELECT
BILLINGS.ID,
CLIENTS.NAME,
ROOMDESC,
CAST((CASE WHEN BILLINGS.NBADULTS IS NULL THEN 0 WHEN BILLINGS.NBCHILDREN IS NULL THEN 0 ELSE CAST(CAST(BILLINGS.NBADULTS AS INTEGER)+CAST(BILLINGS.NBCHILDREN AS INTEGER) AS INTEGER) END) AS INTEGER) AS NBPEOPLE,
BILLINGS.ARRIVINGDATE, BILLINGS.DEPARTUREDATE, BILLINGS.EXPECTEDDEPARTUREDATE,
BILLINGSTYPES.LABEL
FROM BILLINGS
LEFT JOIN ROOMSOCCUPATIONS ON ROOMSOCCUPATIONS.BILLING_ID = BILLINGS.ID 
LEFT JOIN (SELECT ROOMS.ID, (ROOMS.NUMBER || '(' || ROOMSTYPES.LABEL || ')') AS ROOMDESC FROM ROOMS LEFT JOIN ROOMSTYPES ON ROOMS.ROOMTYPE_ID = ROOMSTYPES.ID) AS R ON R.ID = ROOMSOCCUPATIONS.ROOM_ID 
LEFT JOIN BILLINGSGROUPS ON BILLINGSGROUPS.BILLING_ID = BILLINGS.ID 
LEFT JOIN BILLINGSCLIENTS ON BILLINGSCLIENTS.BILLING_ID = BILLINGS.ID 
LEFT JOIN CLIENTS ON CLIENTS.ID = BILLINGSCLIENTS.CLIENT_ID 
LEFT JOIN GROUPS ON GROUPS.ID = BILLINGSGROUPS.GROUP_ID 
LEFT JOIN BILLINGSTYPES ON BILLINGSTYPES.ID = BILLINGS.BILLINGSTYPE_ID 
WHERE BILLINGS.ISCLOSED = '0' 
ORDER BY BILLINGS.ARRIVINGDATE;

COMMIT;