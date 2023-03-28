import socket
import time

UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
serverAddressPort = ("192.168.42.15", 8888)


state_lamp = {  'wait': "l:1:0:0:0#",
                'move': "l:0:0:0:1#",
                'alarm': "l:0:0:1:0#"
               
            }

def send_lamp(state):
    print(state_lamp.get(state))


    msgFromClient = state_lamp.get(state)

    print(msgFromClient)
    bytesToSend = str.encode(msgFromClient)
    #bufferSize = 1024
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)

    time.sleep(0.5)

send_lamp('wait')


