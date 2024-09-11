import winreg as reg

class Thelio_REG:

    def AddKeyRegister(self, cle_registre, key, value):
        cle = reg.OpenKey(reg.HKEY_CURRENT_USER, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
        reg.CloseKey(cle)

    def DeleteKeyRegister(self, cle_registre, key):
        cle = reg.OpenKey(reg.HKEY_CURRENT_USER, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.DeleteValue(cle, key)
        reg.CloseKey(cle)   

    def AddKeyRegister_HKEY_LOCAL_MACHINE(self, cle_registre, key, value):
        cle = reg.OpenKey(reg.HKEY_LOCAL_MACHINE, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
        reg.CloseKey(cle)

    def DeleteKeyRegister_HKEY_LOCAL_MACHINE(self, cle_registre, key):
        cle = reg.OpenKey(reg.HKEY_LOCAL_MACHINE, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.DeleteValue(cle, key)
        reg.CloseKey(cle)    


    def AddKeyRegister_HKEY_USERS(self, cle_registre, key, value):
        cle = reg.OpenKey(reg.HKEY_USERS, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
        reg.CloseKey(cle)
    
    
    def DeleteKeyRegister_HKEY_USERS(self, cle_registre, key):
        cle = reg.OpenKey(reg.HKEY_USERS, cle_registre, 0, reg.KEY_SET_VALUE)
        reg.DeleteValue(cle, key)
        reg.CloseKey(cle)   



    # ------------------------------------------------------------------------------
    # continuer la documentation a partir d'ici 

    # et définis a 0x0 par défaux
    def AddKeyRegister_ALL(self, cle_registre, key, value, number = 0x0):
        if number == 0x0: # retourne false 
            return False
        elif number == 0x48843214: # ajoute des cle de registre dans HKEY_CURRENT_USER
            cle = reg.OpenKey(reg.HKEY_CURRENT_USER, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
            reg.CloseKey(cle)
        elif number == 0x48844111: # ajoute des cle de registre dans HKEY_LOCAL_MACHIN
            cle = reg.OpenKey(reg.HKEY_LOCAL_MACHINE, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
            reg.CloseKey(cle)
        elif number == 0x48844112: # ajoute des cle de registre dans HKEY_USERS
            cle = reg.OpenKey(reg.HKEY_USERS, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.SetValueEx(cle, key, 0, reg.REG_SZ, value)
            reg.CloseKey(cle)
        else: 
            return 400
    

    def DeleteKeyRegister_ALL(self, cle_registre, key, number = 0x0):
        if number == 0x0: # retourne false 
            return False
        elif number == 0x48843214: # suprimme des cle de registre dans HKEY_CURRENT_USER
            cle = reg.OpenKey(reg.HKEY_CURRENT_USER, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.DeleteValue(cle, key)
            reg.CloseKey(cle)
        elif number == 0x48844111: # suprimmer des cle de registre dans HKEY_LOCAL_MACHIN
            cle = reg.OpenKey(reg.HKEY_LOCAL_MACHINE, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.DeleteValue(cle, key)
            reg.CloseKey(cle)
        elif number == 0x48844112: # suprimmer des cle de registre dans HKEY_USERS
            cle = reg.OpenKey(reg.HKEY_USERS, cle_registre, 0, reg.KEY_SET_VALUE)
            reg.DeleteValue(cle, key)
            reg.CloseKey(cle)
        else: 
            return 400



# Exemple d'utilisation
cle_registre = r"Software\Microsoft\Windows\CurrentVersion\Run"
key = "MonProgramme"
value = r"C:\MonProgramme.exe"

# nombre pour ajouter ou suprimer via les registre 
hkey_current_user = 0x48843214
hkey_local_machin = 0x48844111
hkey_users = 0x48844112

g = Thelio_REG()
if g.DeleteKeyRegister_ALL(cle_registre, key, hkey_current_user) != 400:
    print("Aucune Error Et Survenue")
else:
    print("Une error et survenue")
