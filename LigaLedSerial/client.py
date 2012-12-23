import random
from serial import Serial
from time import sleep

#Inicializa o serial com 9600
com_serial = Serial('/dev/cu.usbmodem411', 9600, timeout = 3)

#Aguarda o setup
sleep(2)

#Percore os leds de 13 a 7(inclusive) enviando para a serial
for i in range(13,6,-1):
    print i
    com_serial.writelines(str(i))
    ret = com_serial.readlines()
    #Caso o arduino nao responda qual led manipulou, envia novamente
    while(len(ret) == 0 or int(ret[0]) != i):
        print ret
        print 'tentando novamente...'
        com_serial.writelines(str(i))
        ret = com_serial.readlines()
    #aguarda 1 segundo para apagar o proximo led
    sleep(1)

#Escolhe um led randomico para ligar/desligar
while True:
    pinRandom = random.randint(7, 13)
    print pinRandom
    com_serial.writelines(str(pinRandom))
    sleep(0.2)

