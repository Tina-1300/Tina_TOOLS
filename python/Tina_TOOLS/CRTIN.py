#gère le module cryptographie de python plus facilement 
#documentation https://cryptography.io/en/stable/
from cryptography.fernet import Fernet 

class CRTIN:

    def __init__(self):
        pass

    # au formar .key example : secret.key
    def generate_key(self, filename):
        key = Fernet.generate_key()
        with open(filename, "wb") as key_file:
            key_file.write(key)

    # au formar .key example : secret.key
    def load_key(self, filename):
        return open(filename, "rb").read()


    def encrypt_file(self, file_name, key_file):
        key = self.load_key(key_file)
        fernet = Fernet(key)
    
        with open(file_name, "rb") as file:
            file_data = file.read()
        encrypted_data = fernet.encrypt(file_data)
        
        with open(f"{file_name}", "wb") as file:
            file.write(encrypted_data)
        
        return 200


    def decrypt_file(self, file_name, key_file):
        key = self.load_key(key_file)
        fernet = Fernet(key)
          
        with open(file_name, "rb") as file:
            file_data = file.read() 
        
        encrypted_data = fernet.decrypt(file_data) 
        
        with open(f"{file_name}", "wb") as file:
            file.write(encrypted_data)
        
        return 200



crt = CRTIN()
#crt.generate_key("secret.key") généré la cle
crt.decrypt_file("009.JPG", "secret.key")# déchiffre le fichier 
#crt.encrypt_file("009.JPG", "secret.key")# chiffre le fichier




