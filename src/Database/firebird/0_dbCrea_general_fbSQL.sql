CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

CREATE DOMAIN BOOLEAN AS CHAR(1) CHECK (value is null or value in ('','0', '1'));

COMMIT;
