import hashlib
def hashing(secret):
    return hashlib.sha256(secret.encode()).hexdigest()
def proveknowledge(secret):
    return hashing(secret)
def verifyingknowledge(hashedSecret, expectedSecret):
    hashExpectedSecret=hashing(expectedSecret)
    if hashExpectedSecret==hashedSecret:
        return True
    else:
        return False
secret="Treasure location is XYZ"
hashedSecret=proveknowledge(secret)
expectedSecret="Treasure location is ABC"
if(verifyingknowledge(hashedSecret,expectedSecret)):
    print("Treasure location is same")
else:
    print("Treasure location is different")