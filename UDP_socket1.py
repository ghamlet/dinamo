import socket
from time import sleep


localIP = "192.168.42.30"
localPort = 8888
bufferSize = 1024

palitazer = ('192.168.42.31', 8888)
lamp = ("192.168.42.32", 8888)
server = ("192.168.42.2", 8888)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.bind((localIP, localPort))


sock.sendto(b'g:200:-120:0:40:0#', palitazer)  # get detail
sleep(4)
# msg, addr = sock.recvfrom(bufferSize)
# print(msg, addr)

# state_lamp = {'waiting': "l:0:0:0:1#",
#               'moving': "l:0:0:1:0#",
#               'alarm': "l:1:0:0:0#",
#               'work': "l:0:1:0:0#"
#              }
#
# state_palitazer = {'get': "g:180:-250:0:70:0#",
#                   'put': "g:200:250:0:50:0#",
#                   'middle': "g:180:0:0:70:0#",
#                   }
#
#
#
#
#
#
# def send_lamp(state):
#     print(state_lamp.get(state))
#     msg = state_lamp.get(state)
#     bytesToSend = str.encode(msg)
#     sock.sendto(bytesToSend, lamp)
#
#
#
# # def moveManipulator(position):
# #     #send_lamp('moving')
# #     #
# #
# #     msg1 = state_palitazer.get(position)
# #     msgsen = str.encode(msg1)
# #
# #
# #
# #     sock.sendto(msgsen, palitazer)
# #
# #     sleep(2)
#
# def move(x, y, z, a, g):
#     #sock.sendto(str.encode("r#"), serverAddressPort)
#     sock.sendto(str.encode(f"g:{x}:{y}:{a}:{z}:{g}#"), palitazer)
#
#
#
# # 180, 130, 0, 50,0
#
#
#
# sock.sendto(str.encode("r#"), palitazer)
# #
# while True:
#     msg, addr = sock.recvfrom(bufferSize)
#     print(msg, addr)
#
#     if addr[0] == '192.168.42.31':
#         print("hello")
#
#     elif addr[0] == '192.168.42.54':
#         print("palitazer_ready")
#
#     # move(180, 0, 70, 0, 0)
#     # sleep(2)
#     #
#     # move(180, -280, 70, 0, 0)
#     # sleep(2)
#     #
#     # move(180, -280, 10, 0, 0)
#     # sleep(2)
#     # move(180, -280, 10, 0, 1)
#
# def sendToServer(N, Param, Value):
#     sock.sendto(str.encode(f"{N}:{Param}:{Value}#"), server)
#
# #sendToServer(3,status,2)
#
#
#
#
#
#
#
#
