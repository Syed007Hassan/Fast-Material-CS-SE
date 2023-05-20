pragma solidity >=0.5.0 < 0.6.0;

contract Task{
    address public sender;
    address public reciver;
    address public bank;
    int public Sbalance;
    int public Rbalance;
    address public hash;
    bool public auth;

    constructor() public{
        sender = msg.sender;
    }
    function getSenderAdd() public view returns (address){
        return sender;
    }

    function setReciAdd(address add) public payable returns(bool){
        reciver = add;
        return true;
    }

    function setbANKAdd(address add) public payable returns(bool){
        bank = add;
        return true;
    }

    function getReciverAdd() public view returns (address){
        return reciver;
    }

    function getBankAdd() public view returns (address){
        return bank;
    }

    function authenticate(int pass) public payable returns(bool){
        if(pass == 123){
            auth = true;
        }else{
            auth = false;
        }
        return auth;
    }

    function depositMoney(int money) public payable returns(address){
        if(auth){
            Sbalance += money;
            hash = 0xD7ACd2a9FD159E69Bb102A1ca21C9a3e3A5F771B;
            
            return hash;
        }
       
    }


    function withdrawMoney(address  h) public payable returns(string memory){
        if(auth && hash == h){
            Rbalance += Sbalance;
            Sbalance = 0;
            return "money Sent";
        }else{
            return "Not Authenticated";
        }
    }



}
