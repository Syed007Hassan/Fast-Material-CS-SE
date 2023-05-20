import multichain
###################################### Server Connection############################
rpcuser = "multichainrpc"
rpcpassword = "GPnmaoQHgNNuCuzHFy8ADk3sBjUuYo9mjJdVzcAD5heY"
rpchost = "127.0.0.1"
rpcport = "2690"
chainname = "hassan"
mc = multichain.MultiChainClient(rpchost, rpcport, rpcuser, rpcpassword)
result = mc.getaddresses()
print(result)
############################ Client Side Connection###############################
rpcuser = "multichainrpc"
rpcpassword = "92NGX2cNZLmxe7Tvy5KzQWx2BKd5eGHmZ2UBagENMorp"
rpchost = "127.0.0.1"
rpcport = "4860"
chainname = "hassan"
mc1 = multichain.MultiChainClient(rpchost, rpcport, rpcuser, rpcpassword)
result2 = mc1.getaddresses()
print(result2)


############################ Wallet COnfigration#################################
"""
getaddresses true

Choose any address with "ismine" : true, which means that this node’s
wallet contains the private key for the address.


"""
result = mc.getaddresses(True)
pub1 = result[0]['pubkey']
"""
Now run the same getaddresses true command on the second server,
 again choosing an address with "ismine" : true.
"""
# r=mc1.getnewaddress()
result2 = mc1.getaddresses(True)
pub2 = result2[0]['pubkey']
# print("",pub1,pub2)
########################### Create Walletinformation Create on ServerSide###########################
"""
addmultisigaddress 2 '["0...", "0..."]'
"""
address = mc.addmultisigaddress(2, [pub1, pub2])
print(address)
"""
The response should be empty. Now run the same command on the other server,
to add the address to the wallet and start tracking its balance:
addmultisigaddress 2 '["0...", "0..."]'
"""
address1 = mc1.addmultisigaddress(2, [pub1, pub2])
print(address1)
"""
Creating a multisig-only stream
Now let’s create a stream to which only this multisignature address
can write. On the first server:

create stream stream9 false

This automatically grants per-stream write permissions to its creator,
which can be seen here:

listpermissions stream9.write

"""
txid = mc.create('stream', 'shahbaz1', False)  # open to all to write
re1 = mc.listpermissions('shahbaz1.write')  # all permissions
# print(result[0]['address'])
"""
Now we’ll revoke the write permissions for this address and
grant them only to the multisig address:
revoke 1... stream9.write
grant 4... stream9.write
"""
# txid = mc.revoke(result[0]['address'],'shahbaz1.write')
# print(txid)
txid = mc.grant(address, 'shahbaz1.write')  # per-entity permission
print(txid)
"""
Publishing from the multisig address
Now let’s prepare to publish something to the stream from the
multisignature address. Still on the first server:
createrawsendfrom 4... '{}' '[{"for":"stream9","key":"key1","data":"48656c6c6f2066726f6d206d756c746973696721"}]' sign

The response should contain a complete field containing
false, and a large hexadecimal blob in the hex field,
which should be copied to the clipboard.
"""
re4 = mc.createrawsendfrom(address, {result[1]['address']: 0}, [
                           {'for': 'shahbaz1', 'key': 'key1', 'data': 'a1b2c3d4'}], 'sign')
print(re4)
"""
Now switch to the second server and paste from the clipboard where shown:
signrawtransaction [paste-hex-blob]
"""

Signature2 = re4['hex']
print(Signature2)
result123 = mc1.signrawtransaction(re4['hex'])
print(result123)


"""
The response should contain a complete field containing true, along with an
even larger blob in the hex field. Copy the new blob, and run:
"""


"""
sendrawtransaction [paste-bigger-hex-blob]
"""
txid = mc.sendrawtransaction(result123['hex'])
print(txid)

"""
The response should contain the txid of the sent transaction.
Finally let’s check that the item was published successfully.
On either server:

subscribe stream9
liststreamitems stream9
"""

Server = mc.subscribe('shahbaz1')
Client = mc1.subscribe('shahbaz1')


result = mc.liststreamitems('shahbaz1')
print(result)
"""
The response should contain the txid of the sent transaction.
Finally let’s check that the item was published successfully.
 On either server:
subscribe stream9
liststreamitems stream9
You should see the item listed with the multisig address shown
in the publishers field, as well as the key and data entered above.
"""
