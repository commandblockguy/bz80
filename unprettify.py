import sys
import re

# Token level unprettifier

with open(sys.argv[1],'rb') as ifile:
	with open(sys.argv[2],'wb') as ofile:
		contents = ifile.read()
		contents = re.sub(b"[\\x11\\x09]+([\\x3F,\\x3E,\\x04])", b"\\1", contents) # Remove ) and } before a newline, colon, or arrow
		contents = re.sub(b"\\x2A([\\x3F,\\x04])", b"\\1", contents) # Remove " before a newline or arrow
		contents = re.sub(b"([^\\x5C-\\x5E\\x60-\\x63\\x7E\\xAA\\xBB\\xEF])\\x29+", b"\\1", contents) # Remove spaces
		contents = re.sub(b"\\x3F+", b"\x3F", contents) # Remove empty lines
		ofile.write(contents)