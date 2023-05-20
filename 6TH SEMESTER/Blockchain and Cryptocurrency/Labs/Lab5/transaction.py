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
Issuing an asset to the multisig address
For most blockchain actions, a multisig address requires its own
permissions, independent of the permissions of the individual regular
addresses that were combined to create it (more details here).
Let’s grant these permissions on the first server:

grant 4... receive,send

The txid of the grant transaction should be displayed in the response. Now let’s issue a new asset directly to the multisig address:
"""
txid1 = mc.grant(address, 'receive,send')  # global permission


# txid12 = mc1.grant(address, 'send,receive') # global permission

"""
The txid of the grant transaction should be displayed in the response.
Now let’s issue a new asset directly to the multisig address:

issue 4... asset9 10000 0.01

And now let’s check the multisig address has received the
funds successfully:

getaddressbalances 4... 0

A balance of 10000 units of asset9 should be displayed.
"""
txid2 = mc.issue(address, {'name': 'Walletx'}, 1000, 0.01)
result32 = mc.getaddressbalances(address, 0)
print("Blance", result32)


########################### This particular address send and recevieammount on Serverside###
""""
Spending funds from the multisig address
Still on the first server, let’s create a new regular address to receive
some funds from the multisig:

getnewaddress

Copy and paste the new address here:
1...

Now let’s grant this address receive permissions, so it can be sent some funds:

grant 1... receive

"""
txid = mc.grant(result[1]['address'], 'send,receive')  # global permission
print("Address Two ", result[1]['address'])
print(address)
print(result[1]['address'])
"""
Now we begin the process of building the transaction which sends
funds from the multisig address to this new address.
Because this is a 2-of-2 multisig, the process will require a
signature from both servers. Let’s begin on the first server:

createrawsendfrom 4... '{"1...":{"asset9":500}}' '[]' sign

"""

result69 = mc.createrawsendfrom(
    address, {result[1]['address']: {"Walletx": 90}}, [], 'sign')
# print(result69)
Signature2 = result69['hex']
print(Signature2)

"""
The response should contain a complete field with value false, along with a large hexadecimal blob in the hex field. This hexadecimal blob is the raw transaction,
which has been partially signed, and should be copied to the clipboard.

Now switch to the second server and run the following,
pasting the raw transaction from the clipboard where shown:
"""
"""
signrawtransaction [paste-hex-blob]

The response should contain a complete field with value true,
along with an even larger hexadecimal blob in the hex field.
This means that the transaction has enough signatures to be valid,
and is ready for broadcasting to the blockchain.
"""

result123 = mc1.signrawtransaction(result69['hex'])
print(result123)

"""
Copy the new hexadecimal blob, and run:

sendrawtransaction [paste-bigger-hex-blob]

"""
txid = mc.sendrawtransaction(result123['hex'])
print(txid)

"""
getaddressbalances 4... 0

And on the first server only, check the new address’s balance
(including unconfirmed transactions):

getaddressbalances 1... 0
"""

result32 = mc.getaddressbalances(address, 0)
print("Blance", result32)

result32 = mc1.getaddressbalances(address, 0)
print("Blance", result32)
