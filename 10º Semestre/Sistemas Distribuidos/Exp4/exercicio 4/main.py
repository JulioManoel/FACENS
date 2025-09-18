import argparse
import json
from dataclasses import dataclass, field, asdict

@dataclass
class Person:
    Name: str
    EnrollNumber: int
    Height: float
    LuckNumbers: list[int] = field(default_factory=list)

def encode():
    p = Person(Name = "Angelo Duarte", EnrollNumber = 123456, Height = 1.77, LuckNumbers = [7, 23, 47])
    j = json.dumps(asdict(p), ensure_ascii=False)
    print(j)

def decode(data):
    obj = json.loads(data)
    p = Person(**obj)
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
        