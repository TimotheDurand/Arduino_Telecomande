import serial
import subprocess
import shutil
from fonction import *

Monter_Le_Son()

if shutil.which("vlc"):
    print("VLC est installé !")
else:
    Install_vlc()

PORT = "/dev/ttyACM0"   # À adapter
BAUDRATE = 9600

VIDEO = "/home/melvinrouseau/Vidéos/RICK.mp4"
MP3 = "/home/melvinrouseau/Vidéos/PET.mp3"

ser = serial.Serial(PORT, BAUDRATE)
state = 0

while True:
    cmd = ser.readline().decode().strip()

    if cmd == "VIDEO" and state == 0:
        format = VIDEO
        start = subprocess.Popen(["vlc", "--play-and-exit", format])
        state = 1

    elif cmd == "MP3"and state == 0:
        format = MP3
        start = subprocess.Popen(["vlc", "--play-and-exit", format])
        state = 1

    elif cmd == "STOP" and state == 1:
            start.terminate()
            state = 0
