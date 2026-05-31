import re

def increment_string(string):
    number = re.search('\d*$', string).group()
    text = string[: -len(number)] if number else string
    return text + str(int(number or 0) + 1).zfill(len(number))