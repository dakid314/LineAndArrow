LineArrowAndCirco
===

![HomePAGE](lib/img/HomePAGE.png)

# Input Format
```
geneName    complement(3668847..3668981)	#FF0000
geneName    3668847..3668981	#00FF00
```
Note that we pre-define some Color. We can use the word listed follow to access.

1. red
2. blue
3. green
4. black
5. white
6. purple
7. brown
8. skyblue
9. pink

```
geneName    complement(3668847..3668981)	purple
geneName    3668847..3668981	pink
```

# Usage
## Docker Images
```shell
docker build -t wujiamin/landa:1.0 .
docker run -d -p 1080:1080 wujiamin/landa:1.0
```
## Build the Project
```shell
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=gcc-10 -DCMAKE_CXX_COMPILER=g++-10 ..
make -j
```
## LineArrowAndCirco
```
usage: LineArrowAndCirco --input=string --output=string [options] ...
options:
  -i, --input       Path to Input File (string)
  -o, --output      Name of Output. (string)
  -s, --stdout      Print SVG in STDOUT.
      --datapath    Work Path (string [=./])
      --tmppath     Tmp Path (string [=./])
  -?, --help        print this message
```
```shell
# Output to ./o_file.svg
./LineArrowAndCirco --input input_file.data --output o_file
```

## Server
### Lazy Mode
```
usage: server.py [-h] [-e E] [--port PORT]

optional arguments:
  -h, --help   show this help message and exit
  -e E         Path to LineArrowAndCirco.
  --port PORT  Port(Default: 8080)
```
```shell
cd LineArrowAndCirco
python3.8 -W ignore -u server.py --port 8080 -e ./build/bin/LineArrowAndCirco
```

And Then visit: `http://YourAddr:YourPort/LineArrowAndCirco?D=1&Data=YourBase64CodeData`

### Wsgi Mode
Add File named LineArrowAndCirco.wsgi:
```
import sys
import os
sys.path.insert(0, 'Path_to_the_folder_of_server/src')
os.chdir('/home/wujiamin/Source/Project/LineArrowAndCirco')
from server import path_to_exe

path_to_exe = '/Path_to_LineArrowAndCirco/LineArrowAndCirco.exe'
from server import app as application
```

Add Config to Your site_config. (e.g. /etc/apache2/sites-enabled/*.conf)
```
WSGIScriptAlias / /Path_to_the_folder_of_wsgi_file/LineArrowAndCirco.wsgi

<Directory /Path_to_the_folder_of_wsgi_file>
    AllowOverride None
    Require all granted
</Directory>
<Directory /Path_to_the_folder_of_server>
    AllowOverride None
    Require all granted
</Directory>
```

Restart Your Apache2 server
```shell
sudo service apache2 restart
```

And Then visit: `http://YourAddr:YourPort/LineArrowAndCirco?D=1&Data=YourBase64CodeData`

###
serve_mode
cd LineArrowAndCirco
```shell
python3 -u src/server.py -e LineArrowAndCirco/build/bin/LineArrowAndCirco
```
And Then visit: `http://YourAddr:YourPort/