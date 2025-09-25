from person_pb2 import Person
from base64 import b64encode

if __name__ == "__main__":
    p = Person()
    # Coloque seu Nome, RA, altura e escolha 3 números
    p.Name = "Nome de Alguem"
    p.EnrollNumber = 123456
    p.Height = 1.77
    p.LuckNumbers.extend([7, 23, 47])
    # serialize in python binary "string"
    bstr = p.SerializeToString()
    # transform into a normal string
    txt = b64encode(bstr).decode()
    # print the string
    print(txt);