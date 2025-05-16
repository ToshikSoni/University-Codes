import hashlib
def hashing(secret):
    return hashlib.sha256(secret.encode()).hexdigest()
secret="Treasure at ABC"
expectedSecret="Treasure at ABC"
sechash=hashing(secret)
exphash=hashing(expectedSecret)
if sechash==exphash:
    print("Hi")
else:
    print("Bye")