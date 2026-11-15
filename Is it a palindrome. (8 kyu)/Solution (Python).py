def is_palindrome(s):
    string_lowercase = s.lower()
    return string_lowercase == string_lowercase[ : : -1]