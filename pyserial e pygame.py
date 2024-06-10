import serial
from os import environ
from pygame import mixer 
import os
os.system("cls")
ser = serial.Serial('COM16',9600) 

environ['PYGAME_HIDE_SUPPORT_PROMPT'] = '1'

mixer.init()
while True :
    if ser.in_waiting :
        mixer.music.stop()
        data = ser.readline().decode('utf-8').strip()
        print(data)
        if data == "botao0" :
            mixer.music.load("music/sede.mp3")
            mixer.music.set_volume(0.7)
            mixer.music.play()
            print("botao apertado")
        elif data == 'botao1' :
            mixer.music.load("music/incomodado 2.0.mp3")
            mixer.music.set_volume(0.5)
            mixer.music.play()

        elif data == 'botao2' :
            mixer.music.load("music/fome.mp3")
            mixer.music.set_volume(0.5)
            mixer.music.play()

        elif data == 'botao3' :
            mixer.music.load("music/banheiro.mp3")
            mixer.music.set_volume(0.5)
            mixer.music.play()

#ser.close()
#input(" enter to exit")





    



