import hashlib
def get_md5_hash(message):
    md5=hashlib.md5()
    md5.update(message.encode())
    return md5.hexdigest()
message=input("Enter the message: ")
hash=get_md5_hash(message)
print("Hash: ",hash) 