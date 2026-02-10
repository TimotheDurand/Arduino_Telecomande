import platform
import os

def Monter_Le_Son():
    os_name = platform.system()

    if os_name == "Linux":
        os.system("amixer set Master 100%")

    return


def Install_vlc():
    try :
        os.system("sudo apt update")
        os.system("root")
        os.system("sudo apt vlc")
        os.system("root")
    except :
        return "Erreur de telechargement"
