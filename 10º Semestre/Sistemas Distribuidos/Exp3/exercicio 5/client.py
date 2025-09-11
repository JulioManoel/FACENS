import xmlrpc.client

def client():
    with xmlrpc.client.ServerProxy("http://localhost:50007/", verbose=True) as proxy:
        # Lista todos os métodos disponíveis
        print(proxy.system.listMethods())

        # Informações sobre um método
        print(proxy.system.methodHelp('add'))

        # Assinatura de um método
        print(proxy.system.methodSignature('add'))

if __name__ == '__main__':
    client()
