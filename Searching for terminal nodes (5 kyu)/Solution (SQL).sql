CREATE FUNCTION last_node(first_node INT) 
RETURNS INT AS 
$$
  DECLARE
    i INT := first_node;
    s INT;
    t BOOL;
  BEGIN
    LOOP
      SELECT step, terminal INTO s, t 
      FROM nodes 
      WHERE id = i;
      
      IF t THEN RETURN i; 
      END IF;
      
      i := i + s;
    END LOOP;
  END
$$
LANGUAGE plpgsql;