import re

def count_smileys(arr):
    return sum(1 for smiley in arr if re.fullmatch('[:;][-~]?[)D]', smiley))