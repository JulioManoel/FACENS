import xmlrpc.client

def print_table(tasks):
    if not tasks: return print("(vazio)")
    
    print(f"{'ID':<3} {'Title':<20} {'Created':<10} {'Expires':<10} {'Finished':<50} {'Finished':<8}")
    print("-"*110)
    for t in tasks:
        print(f"{t['id']:<3} {t['title']:<20} {t['createdAt']:<10} {t['expirationDate']:<10} {t['description']:<50} {str(t['finished']):<8}")

def client():
    with xmlrpc.client.ServerProxy("http://localhost:50007/") as proxy:
        proxy.add('Jogar futebol', '2020-08-05', '2020-08-06', 'Jogar futebol com os amigos')
        proxy.add('Jogar basquete', '2020-08-05', '2020-08-06', 'Jogar basquete com os amigos')
        proxy.add('Jogar volei', '2020-08-05', '2020-08-06', 'Jogar volei com os amigos')

        print("\n== All ==")
        print_table(proxy.get('all'))

        proxy.finish(1)

        print("\n== Finished ==")
        print_table(proxy.get('finished'))

        print("\n== Unfinished ==")
        print_table(proxy.get('unfinished'))

if __name__ == '__main__':
    client()