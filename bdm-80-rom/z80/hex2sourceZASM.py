from intelhex import IntelHex
import subprocess
import os

dirname = os.path.dirname(os.path.abspath(__file__))

# asm build
print("\033[32mz80 asm build\033[0m")
subprocess.run('zasm -uwyx main.asm', cwd=dirname, shell=True)

ih = IntelHex() 
ih.loadhex(dirname + '/main.hex')
f = open(dirname + '/rom.c', 'w')

f.write('#include "rom.h"\n')
f.write('const uint8_t mem_data[65536] = {\n')

for address in range(65536):
    if address in ih.addresses():
        f.write('\t0x%02x, // 0x%02x\n' % (ih[address], address))
    else:
        f.write('\t0x00, // 0x%02x\n' % address)
f.write('};')
f.close()