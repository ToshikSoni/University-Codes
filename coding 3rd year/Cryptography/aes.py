from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
import base64
import os
SECRET_KEY = b"123456789"
SALTVALUE = b"abcdefg"
def encrypt(plain_text):
    try:
        salt = SALTVALUE
        kdf = PBKDF2HMAC( algorithm=hashes.SHA256(), length=32, salt=salt, iterations=65536, backend=default_backend())
        key = kdf.derive(SECRET_KEY)
        iv = b'\x00' * 16
        cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
        encryptor = cipher.encryptor()
        pad_length = 16 - len(plain_text) % 16
        padded_text = plain_text + (chr(pad_length) * pad_length)
        encrypted = encryptor.update(padded_text.encode('utf-8')) + encryptor.finalize()
        return base64.b64encode(encrypted).decode('utf-8')
    except Exception as e:
        print(f"Error occurred during encryption: {str(e)}")
        return None
def decrypt(cipher_text):
    try:
        salt = SALTVALUE
        kdf = PBKDF2HMAC(algorithm=hashes.SHA256(), length=32, salt=salt, iterations=65536, backend=default_backend())
        key = kdf.derive(SECRET_KEY)
        iv = b'\x00' * 16
        cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
        decryptor = cipher.decryptor()
        encrypted = base64.b64decode(cipher_text)
        decrypted_padded = decryptor.update(encrypted) + decryptor.finalize()
        pad_length = decrypted_padded[-1]
        decrypted = decrypted_padded[:-pad_length]
        return decrypted.decode('utf-8')
    except Exception as e:
        print(f"Error occurred during decryption: {str(e)}")
        return None
if __name__ == "__main__":
    original_val = "AES Encryption"
    encrypted_val = encrypt(original_val)
    decrypted_val = decrypt(encrypted_val)
    print("Original value:", original_val)
    print("Encrypted value:", encrypted_val)
    print("Decrypted value:", decrypted_val)