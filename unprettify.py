import sys
import re

# Token level unprettifier

with open(sys.argv[1],'rb') as ifile:
	with open(sys.argv[2],'wb') as ofile:
		contents = ifile.read()
		contents = re.sub(b"[\\x11\\x09]+\\x3F", b"\x3F", contents) # Remove ) and } before a newline
		contents = re.sub(b"[\\x11\\x09]+\\x3E", b"\x3E", contents) # Remove ) and } before a colon
		contents = re.sub(b"\\x2A\\x3F", b"\x3F", contents) # Remove " before a newline
		contents = re.sub(b"\\x29", b"", contents) # Remove spaces TODO: this breaks a few window and stats tokens, as well as expr(
		ofile.write(contents)