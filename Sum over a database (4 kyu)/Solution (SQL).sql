CREATE OR REPLACE FUNCTION get_total()
RETURNS INTEGER
LANGUAGE plpgsql
AS $$
  DECLARE
    sql TEXT;
    result INTEGER;
  BEGIN
    SELECT string_agg(
      format(
        'SELECT COALESCE(SUM(%I), 0) AS total 
        FROM %I.%I',
        c.column_name,
        c.table_schema,
        c.table_name
      ),
      ' UNION ALL '
    )
    INTO sql
    FROM information_schema.columns c
    JOIN information_schema.tables t
      ON c.table_schema = t.table_schema
      AND c.table_name = t.table_name
    WHERE c.data_type = 'integer'
      AND t.table_type = 'BASE TABLE'
      AND c.table_schema NOT IN ('pg_catalog', 'information_schema');

    IF sql IS NULL THEN
      RETURN 0;
    END IF;

    EXECUTE 'SELECT SUM(total) 
      FROM (' || sql || ') total_table'
    INTO result;

    RETURN result;
  END;
$$;

SELECT get_total() AS total;