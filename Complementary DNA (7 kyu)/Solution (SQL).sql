SELECT dna, TRANSLATE(dna, 'ATCG', 'TAGC') AS res
FROM dnastrand
ORDER BY dna;