CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE VIEW SERVICESINFOS AS
SELECT
SERVICES.ID, SERVICESFAMILIES.ID AS SERVICEFAMILY, SERVICETYPE_ID AS SERVICETYPE, SERVICES.NAME AS SERVICENAME, SERVICESTYPES.ROOMNEEDED AS ROOMNEEDED, SERVICES.ISAVAILABLE AS ISAVAILABLE
FROM SERVICES
LEFT JOIN SERVICESTYPES ON SERVICES.SERVICETYPE_ID=SERVICESTYPES.ID
LEFT JOIN SERVICESFAMILIES ON SERVICESTYPES.SERVICEFAMILY_ID=SERVICESFAMILIES.ID
--LEFT JOIN SERVICESDETAILS ON SERVICESDETAILS.SERVICE_ID=SERVICES.ID
--LEFT JOIN SERVICESFIELDS ON SERVICESFIELDS.ID=SERVICESDETAILS.SERVICEFIELD_ID
ORDER BY SERVICEFAMILY, SERVICETYPE, SERVICENAME;--,
--GROUP BY SERVICES.ID;

COMMIT;
