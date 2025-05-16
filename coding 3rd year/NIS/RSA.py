import rsa
publickey,privatekey=rsa.newkeys(2048)
plaintext = "Secret"
def encrypt(plaintext):
    ciphertext = rsa.encrypt(plaintext.encode(), publickey)
    return ciphertext
def decrypt(ciphertext):
    decrypted_text= rsa.decrypt(ciphertext, privatekey)
    return decrypted_text
print("Original text: ",plaintext)
print("Encrypted text: ",encrypt(plaintext))
print("Decrypted text: ",decrypt(encrypt(plaintext)))