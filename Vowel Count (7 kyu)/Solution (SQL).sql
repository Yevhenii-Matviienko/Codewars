SELECT getcount.str, vowels_letters.res
FROM getcount
CROSS JOIN LATERAL (
    SELECT COUNT(*) AS res
    FROM regexp_split_to_table(getcount.str, '') AS letters
    WHERE letters IN ('a', 'e', 'i', 'o', 'u')
) AS vowels_letters
ORDER BY getcount.str ASC;