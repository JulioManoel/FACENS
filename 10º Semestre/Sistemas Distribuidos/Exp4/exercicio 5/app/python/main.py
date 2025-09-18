import argparse
import person_pb2
from google.protobuf.json_format import MessageToJson, Parse

def encode():
    p = person_pb2.Person()
    p.Name = "Angelo Duarte"
    p.EnrollNumber = 123456
    p.Height = 1.77
    p.LuckNumbers.extend([7, 23, 47])
    j = MessageToJson(p, including_default_value_fields=False, preserving_proto_field_name=False)
    print(j)

def decode(data):
    p = person_pb2.Person()
    Parse(data, p)
    print(f'Name: {p.Name}')
    print(f'EnrollNumber: {p.EnrollNumber}')
    print(f'Height: {p.Height}')
    print(f'LuckNumbers: {p.LuckNumbers}')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('args', nargs=argparse.REMAINDER)
    args = parser.parse_args()

    if args.args: decode(args.args[0])
    else: encode()
        