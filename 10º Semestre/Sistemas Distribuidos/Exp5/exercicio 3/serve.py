import time
from concurrent import futures
import grpc

import contact_book_pb2 as pb2            # <- PRECISA existir
import contact_book_pb2_grpc as pb2_grpc  # <- PRECISA existir


class ContactsManagerImpl(pb2_grpc.ContactsManagerServicer):
    def __init__(self):
        self._db = {}
        self._next_id = 1

    def CreateContact(self, request, context):
        try:
            cid = self._next_id
            self._next_id += 1
            self._db[cid] = pb2.Person(  # <-- usamos pb2 aqui
                Name=request.Name,
                EnrollNumber=request.EnrollNumber,
                Height=request.Height,
                LuckNumbers=list(request.LuckNumbers),
            )
            return pb2.ContactId(Id=cid)  # <-- e aqui
        except Exception as e:
            # log explícito para evitar UNKNOWN silencioso
            context.set_details(f"CreateContact failed: {e!r}")
            context.set_code(grpc.StatusCode.INTERNAL)
            return pb2.ContactId()  # retorno vazio só para tipo bater

    def RetrieveContact(self, request, context):
        person = self._db.get(request.Id)
        if not person:
            context.abort(grpc.StatusCode.NOT_FOUND, f"Contact {request.Id} not found")
        return person

    def DeleteContact(self, request, context):
        if request.Id not in self._db:
            context.abort(grpc.StatusCode.NOT_FOUND, f"Contact {request.Id} not found")
        del self._db[request.Id]
        return pb2.DeleteContactResponse(Result="OK")


def serve(host="0.0.0.0", port=50051):
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    pb2_grpc.add_ContactsManagerServicer_to_server(ContactsManagerImpl(), server)
    server.add_insecure_port(f"{host}:{port}")
    server.start()
    print(f"gRPC server rodando em {host}:{port}")
    try:
        while True:
            time.sleep(86400)
    except KeyboardInterrupt:
        server.stop(grace=None)


if __name__ == "__main__":
    serve()