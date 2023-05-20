# -*- coding: utf-8 -*-
"""
Created on Fri Feb  3 13:04:16 2023

@author: Syed Hassan
"""

# client.py
import time
import socket

print("Starting the client end.\n")
time.sleep(1)

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# this represents the domain and type of connection

shost = socket.gethostname()
ip = socket.gethostbyname(shost)
print("The ip of client is: ",ip)

host = ip
name = input(str("Enter the client name: "))
port = 12345

print("\nTrying to connect to ", host, "(", port, ")\n")
time.sleep(1)
client_socket.connect((host, port))
print("Connected!!!\n")

client_socket.send(name.encode())
s_name = client_socket.recv(1024)
s_name = s_name.decode()
print(s_name, "is ready for communication, enter x to terminate communication\n")

while True:
    message = client_socket.recv(1024)
    message = message.decode()
    print(s_name, ":", message)
    message = input(str("you : "))
    if message == "x":
        message = "terminated the connection!"
        client_socket.send(message.encode())
        print("\n")
        break
    client_socket.send(message.encode())