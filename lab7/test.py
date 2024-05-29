import re

def is_valid_string(s):
    pattern = re.compile(r'[A-Za-z0-9_]+')
    if pattern.fullmatch(s):
        return True
    else:
        return False

# Test cases
print(is_valid_string('A')) # True
print(is_valid_string('123'))   # True
print(is_valid_string('_underscore')) # True
print(is_valid_string('hello_123')) # True
print(is_valid_string('hello world')) # False
print(is_valid_string('hello@world')) # False
print(is_valid_string('hello#123')) # False