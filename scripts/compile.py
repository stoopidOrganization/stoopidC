import hashlib, os, json, subprocess, sys, time

start_time = time.perf_counter()

# get all files
filelist = []
filetypes = (".c", ".cpp")

def getFiles(path):
    global filelist, filetypes
    
    files = os.listdir(path)
    
    for f in files:
        if f.endswith(filetypes):
            filelist.append(os.path.join(path, f))
        elif os.path.isdir(os.path.join(path, f)):
            getFiles(os.path.join(path, f))
    
getFiles(os.path.join("src"))

if not os.path.isdir(os.path.join("bin")):
    os.mkdir("bin")

hashlist = {}

def getHash(file):
    with open(file, 'rb') as opened:
        content = opened.read()
        md5 = hashlib.md5()
        md5.update(content)
        return md5;
 
for f in filelist:
    hashlist[f] = getHash(f).hexdigest()
    
def compile(name):
    print(f'Compiling {name}')
    p = subprocess.Popen(["g++", "-Wall", "-c", os.path.join("..", name)], cwd=os.path.join("bin"))
    print("finished")

if "smart" in sys.argv:
    if os.path.isfile(os.path.join("bin", "hashlist.json")):
        with open(os.path.join("bin", "hashlist.json"), "r") as f:
            oldhashlist = json.load(f)
            
            for n in hashlist:
                if n in oldhashlist:
                    if hashlist[n] != oldhashlist[n]:
                        compile(n)
                else:
                    compile(n)
    else:
        for n in hashlist:
            
            compile(n)
elif "all" in sys.argv:
    for n in hashlist:
        compile(n)
else:
    print("Error")
    exit(0)
                    
with open(os.path.join("bin", "hashlist.json"), 'w') as f:
    f.write(json.dumps(hashlist))
    
if not os.path.isdir(os.path.join("build")):
    os.mkdir("build")

os.system(f'g++ -o {os.path.join("build", "stoopid")} {os.path.join("bin", "*.o")}')

print("\n-----------------\n")
print(f'Compilation took {round(time.perf_counter() - start_time, 2)}s\n')
