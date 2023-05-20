# -*- coding: utf-8 -*-
"""
Created on Sun Jan 29 18:00:29 2023

@author: Anabia
"""

import socket
import json
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 12345))
val=50
try:
 with open("message2.json","r") as f:
  data=json.load(message2.json);
except FileNotFoundError:
  with open("messages2.json","w") as f:
   json.dump({"Value":val},f)

message = input("Enter your message: ")
try:
 with open("message2.json","r") as f:
  data=json.load(message2.json);
except FileNotFoundError:
 with open("messages2.json","w") as f:
  json.dump({"Value":val-int(message)},f)

client.send(message.encode())
response = client.recv(1024)
print(response)
client.close()