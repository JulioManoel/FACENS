import xmlrpc.client

def print_table(tasks):
    if not tasks: return print("(vazio)")
    
    print(f"{'ID':<3} {'Title':<20} {'Created':<10} {'Expires':<10} {'Finished':<50} {'Finished':<8}")
    print("-"*110)
    for t in tasks:
        print(f"{t['id']:<3} {t['title']:<20} {t['createdAt']:<10} {t['expirationDate']:<10} {t['description']:<50} {str(t['finished']):<8}")
    print('')

def client():
    with xmlrpc.client.ServerProxy("http://localhost:50007/") as proxy:
        multi = xmlrpc.client.MultiCall(proxy)

        multi.add('Jogar futebol', '2020-08-05', '2020-08-06', 'Jogar futebol com os amigos')
        multi.add('Jogar basquete', '2020-08-05', '2020-08-06', 'Jogar basquete com os amigos')
        multi.add('Jogar volei', '2020-08-05', '2020-08-06', 'Jogar volei com os amigos')

        multi.finish(1)
        multi.finish(2)

        multi.get('all')
        multi.get('finished')
        multi.get('unfinished')

        try:
            for response in multi():
                if response is None: continue
                print_table(response)
                # print(response)
        except Error as v:
            print("ERROR", v)

if __name__ == '__main__':
    client()