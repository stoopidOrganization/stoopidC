import hashlib

path = "./src/main.cpp"

with open(path, 'rb') as f:
    content = f.read()

    md5 = hashlib.md5()

    md5.update(content)

    print(f'{md5.name} = {md5.hexdigest()}')
