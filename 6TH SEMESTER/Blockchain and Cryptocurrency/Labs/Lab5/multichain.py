
from urllib import request
from urllib import error
import base64
import json
from collections import OrderedDict
import time
import ssl

default_error_code = 502

class MultiChainClient:

    def __init__(self, host, port, username, password, usessl = False):
        self.host = host
        self.port = port
        self.username = username
        self.password = password
        self.usessl = usessl

        self.chainname = None
        self.verifyssl = True

        self.error_code = 0
        self.error_message = ""

    def setoption(self, option, value):

        if(option == "chainname"):
            self.chainname = value
        if(option == "verifyssl"):
            self.verifyssl = value

    def api_wrapper(self, method):

        def api_caller(*args):

            url="https" if self.usessl else "http"

            url += "://" + self.host + ":" + str(self.port)
            userpass64 = base64.b64encode((self.username + ":" + self.password).encode("ascii")).decode("ascii")

            headers={
                "Content-Type" : "application/json",
                "Connection" : "close",
                "Authorization" : "Basic " + userpass64
            }

            api_request={
                "id" : int(round(time.time() * 1000)),
                "method" : method,
                "params" : args
            }

            if self.chainname:
                api_request["chain_name"] = self.chainname

            payload=json.dumps(api_request)

            headers["Content-Length"] = str(len(payload))

            try:
                data = str(payload)
                data = data.encode('utf-8')

                ureq = request.Request(url, data=data)

                for header,value in headers.items():
                    ureq.add_header(header, value)

                if self.verifyssl:
                    req = request.urlopen(ureq)
                else:
                    context = ssl._create_unverified_context()
                    req = request.urlopen(ureq, context=context)

            except error.HTTPError as e:

                self.error_code = e.getcode()
                self.error_message = e.reason

                resp = e.read()

                if resp:
                    req_json=json.loads(resp.decode('utf-8'))
                    if req_json['error'] is not None:
                        self.error_code = req_json['error']['code']
                        self.error_message = req_json['error']['message']
                        if self.error_code == -1:
                            if self.error_message.find("\n\n") >= 0:
                                self.error_message = "Wrong parameters. Usage:\n\n" + self.error_message

                return None

            except error.URLError as e:

                self.error_code = default_error_code
                self.error_message = str(e.reason)

                return None

            resp=req.read()
            req_json=json.loads(resp.decode('utf-8'), object_pairs_hook=OrderedDict)

            return req_json['result']

        return api_caller

    def __getattr__(self, method):
        return self.api_wrapper(method)

    def errorcode(self):
        return self.error_code

    def errormessage(self):
        return self.error_message

    def success(self):
        return (self.error_code == 0)