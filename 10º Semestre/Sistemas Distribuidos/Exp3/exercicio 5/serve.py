# from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import DocXMLRPCServer

def add(a: int, b: int) -> int:
    """Metodo para adicao de dois inteiros
Paramtros: a -> int
           b -> int
Retorno: a+b -> int
"""
    return a + b

def mul(a, b):
    return a * b

def serve():
    with DocXMLRPCServer(("localhost", 50007), allow_none=True) as server:
        server.register_introspection_functions()
        server.register_function(add)
        server.register_function(mul)
        print("Servidor XML-RPC ouvindo em http://localhost:50007/")

        try:
            server.serve_forever()
        except KeyboardInterrupt:
            print("Exiting")

if __name__ == '__main__':
    serve()

