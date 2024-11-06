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
        return 200

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
    
    def encrypt_file_List(self, key_file, list):
        key = self.load_key(key_file)
        fernet = Fernet(key)

        for i in list:
            with open(i, "rb") as file:
                file_data = file.read()
            encrypted_data = fernet.encrypt(file_data)
            
            with open(f"{i}", "wb") as file:
                file.write(encrypted_data)
        return 200
    
    def decrypt_file_List(self, key_file, list):
        key = self.load_key(key_file)
        fernet = Fernet(key)
          
        for i in list:
            with open(i, "rb") as file:
                file_data = file.read() 
            encrypted_data = fernet.decrypt(file_data) 
            with open(f"{i}", "wb") as file:
                file.write(encrypted_data)
        return 200
    
    
    
    # ajouter des fonction pour chiffre via une cle public et généré et envoyer a une bdd 
    # distante la cle priver et récupéré la cle priver pour déchiffre 
    # en C++ cree une class qui gère facilement les notif windows via cette documentation :
    #https://learn.microsoft.com/fr-fr/windows/apps/design/shell/tiles-and-notifications/send-local-toast-desktop-cpp-wrl

    


#crt = CRTIN()
#crt.generate_key("secret.key") généré la cle

#crt.decrypt_file("009.JPG", "secret.key")# déchiffre le fichier 
#crt.encrypt_file("009.JPG", "secret.key")# chiffre le fichier

#l = ["t.txt", "tt.txt"] # liste des fichier a chiffre 

#crt.encrypt_file_List("secret.key", l) #marche 
#crt.decrypt_file_List("secret.key", l) #marche 