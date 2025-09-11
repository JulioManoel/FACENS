from xmlrpc.server import SimpleXMLRPCServer

db = []

class Task:
    def __init__(self, id, title, createdAt, expirationDate, description, finished=False):
        self.id = id
        self.title = title
        self.createdAt = createdAt
        self.expirationDate = expirationDate
        self.description = description
        self.finished = finished

def addTask(title, createdAt, expirationDate, description):
    task = Task(len(db), title, createdAt, expirationDate, description)
    db.append(task)
    return task

def finishTask(id):
    for task in db:
        if task.id == id:
            task.finished = True
        
def getTasks(kind):
    if kind == 'all': return db
    elif kind == 'finished': return [t for t in db if t.finished]
    elif kind == 'unfinished': return [t for t in db if not t.finished]

def serve():
    with SimpleXMLRPCServer(("localhost", 50007), allow_none=True, logRequests=True, bind_and_activate=False) as server:
        server.register_introspection_functions()
        server.server_bind()
        server.server_activate()

        server.register_function(addTask, 'add')
        server.register_function(finishTask, 'finish')
        server.register_function(getTasks, 'get')
        print("Servidor XML-RPC ouvindo em http://localhost:50007/")

        try:
            server.serve_forever()
        except KeyboardInterrupt:
            print("Exiting")

if __name__ == '__main__':
    serve()