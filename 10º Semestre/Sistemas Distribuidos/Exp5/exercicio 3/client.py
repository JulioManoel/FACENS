import grpc
import contact_book_pb2 as pb2
import contact_book_pb2_grpc as pb2_grpc


def run():
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = pb2_grpc.ContactsManagerStub(channel)

        pessoas = [
            pb2.Person(Name="Julio",   EnrollNumber=101, Height=1.82, LuckNumbers=[7, 13, 21]),
            pb2.Person(Name="Laryssa", EnrollNumber=102, Height=1.65, LuckNumbers=[3, 9, 27]),
            pb2.Person(Name="Rafael",  EnrollNumber=103, Height=1.75, LuckNumbers=[5, 10, 15]),
        ]

        ids = []

        # 1) Cria 3 contatos
        for p in pessoas:
            cid = stub.CreateContact(p)
            ids.append(cid.Id)
            print(f"[CREATE] {p.Name} → ID {cid.Id}")

        # 2) Buscar apenas o segundo
        segundo_id = ids[1]
        segundo = stub.RetrieveContact(pb2.ContactId(Id=segundo_id))
        print("\n[RETRIEVE] Segundo contato:")
        print(f"  Nome: {segundo.Name}")
        print(f"  Matrícula: {segundo.EnrollNumber}")
        print(f"  Altura: {segundo.Height}")
        print(f"  Números da sorte: {list(segundo.LuckNumbers)}")

        # 3) Deleta o primeiro
        primeiro_id = ids[0]
        del_resp = stub.DeleteContact(pb2.ContactId(Id=primeiro_id))
        print(f"\n[DELETE] Primeiro contato (ID {primeiro_id}) → {del_resp.Result or 'NO_RESULT'}")

        # 4) Tentar buscar o primeiro
        print("\n[RETRIEVE após DELETE] Tentando buscar o primeiro contato...")
        try:
            _ = stub.RetrieveContact(pb2.ContactId(Id=primeiro_id))
            print("  (inesperado) Contato retornado.")
        except grpc.RpcError as e:
            print(f"  Falha esperada.")
            print(f"  details: {e.details()}") 


if __name__ == "__main__":
    run()
