import hashlib

strInput = raw_input()
print hashlib.sha224(strInput).hexdigest()